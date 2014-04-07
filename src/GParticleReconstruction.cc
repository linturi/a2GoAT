#include "GParticleReconstruction.h"


using namespace std;


GParticleReconstruction::GParticleReconstruction()  :
    CBTime(0),
    TAPSTime(0),
    CBTimeAfterCut(0),
    TAPSTimeAfterCut(0),
    DoScalerCorrection(kFALSE),
    DoTrigger(kFALSE),
    E_Sum(50),
    multiplicity(1)
{
    CBTimeCut[0]    = -1000000.0;
    CBTimeCut[1]    = 1000000.0;
    TAPSTimeCut[0]    = -1000000.0;
    TAPSTimeCut[1]    = 1000000.0;
}

GParticleReconstruction::~GParticleReconstruction()
{
    if(CBTime)              delete  CBTime;
    if(TAPSTime)            delete  TAPSTime;
    if(CBTimeAfterCut)      delete  CBTimeAfterCut;
    if(TAPSTimeAfterCut)    delete  TAPSTimeAfterCut;
}

Bool_t  GParticleReconstruction::Trigger()
{
    if(trigger->GetESum() < E_Sum)
        return kFALSE;
    if(trigger->GetMult() < multiplicity)
        return kFALSE;
    return kTRUE;
}

void  GParticleReconstruction::ProcessEvent()
{
    if(DoTrigger)
    {
        if(!Trigger())
            return;
    }
    if(rawEvent->GetNCB() != 2 && rawEvent->GetNCB() != 3)
        return;
    if(rawEvent->GetNTAPS()>1)
        return;

    for(Int_t i=0; i<rawEvent->GetNParticles(); i++)
    {
        if(rawEvent->GetApparatus(i) == GTreeRawEvent::APPARATUS_CB)
            CBTime->Fill(rawEvent->GetTime(i));
        if(rawEvent->GetApparatus(i) == GTreeRawEvent::APPARATUS_TAPS)
            TAPSTime->Fill(rawEvent->GetTime(i));
    }

    for(Int_t i=0; i<rawEvent->GetNParticles(); i++)
    {
        if(rawEvent->GetApparatus(i) == GTreeRawEvent::APPARATUS_CB)
        {
            if(rawEvent->GetTime(i)<CBTimeCut[0] || rawEvent->GetTime(i)>CBTimeCut[1])
                return;
        }
        if(rawEvent->GetApparatus(i) == GTreeRawEvent::APPARATUS_TAPS)
        {
            if(rawEvent->GetTime(i)<TAPSTimeCut[0] || rawEvent->GetTime(i)>TAPSTimeCut[1])
                return;
        }
    }

    GCorrectScalers::ProcessEvent();

    photons->Clear();
    protons->Clear();
    if(rawEvent->GetNParticles()==2)
    {
        for(Int_t i=0; i<rawEvent->GetNParticles(); i++)
        {
            CBTimeAfterCut->Fill(rawEvent->GetTime(i));
            photons->AddParticle(rawEvent->GetVector(i), i);
        }
    }
    else
    {
        Double_t ChiSq[6];
        ChiSq[0]    = (rawEvent->GetVector(1) + rawEvent->GetVector(1)).M() - MASS_PI0 / 22; ChiSq[0] *= ChiSq[0];
        ChiSq[1]    = (rawEvent->GetVector(0) + rawEvent->GetVector(2)).M() - MASS_PI0 / 22; ChiSq[1] *= ChiSq[1];
        ChiSq[2]    = (rawEvent->GetVector(0) + rawEvent->GetVector(1)).M() - MASS_PI0 / 22; ChiSq[2] *= ChiSq[2];

        ChiSq[3]    = (rawEvent->GetVector(1) + rawEvent->GetVector(1)).M() - MASS_ETA / 40; ChiSq[3] *= ChiSq[3];
        ChiSq[4]    = (rawEvent->GetVector(0) + rawEvent->GetVector(2)).M() - MASS_ETA / 40; ChiSq[4] *= ChiSq[4];
        ChiSq[5]    = (rawEvent->GetVector(0) + rawEvent->GetVector(1)).M() - MASS_ETA / 40; ChiSq[5] *= ChiSq[5];

        Double_t    min = ChiSq[0];
        Double_t    min_index = 0;
        for(int i=1; i<6; i++)
        {
            if(ChiSq[i]<min)
            {
                min = ChiSq[i];
                min_index = i;
            }
        }

        TAPSTimeAfterCut->Fill(rawEvent->GetTime(min_index));
        protons->AddParticle(rawEvent->GetVector(min_index), min_index);
        for(int i=0; i<3; i++)
        {
            if(i!=min_index)
            {
                CBTimeAfterCut->Fill(rawEvent->GetTime(i));
                photons->AddParticle(rawEvent->GetVector(i), i);
            }
        }
    }
    photons->Fill();
    protons->Fill();
}

Bool_t  GParticleReconstruction::Process(const char* input_filename, const char* output_filename)
{
    if(!Create(output_filename))    return kFALSE;
    if(!CreatePhotons())    return kFALSE;
    if(!CreateProtons())    return kFALSE;

    file_out->cd();
    CBTime              = new TH1D("CBTimeOR", "CBTimeOR", 10000, -1000, 1000);
    TAPSTime            = new TH1D("TAPSTimeOR", "TAPSTimeOR", 10000, -1000, 1000);
    CBTimeAfterCut      = new TH1D("CBTimeOR_Cut", "CBTimeOR_Cut", 10000, -1000, 1000);
    TAPSTimeAfterCut    = new TH1D("TAPSTimeOR_Cut", "TAPSTimeOR_Cut", 10000, -1000, 1000);

    if(DoScalerCorrection)
    {
        if(!GCorrectScalers::Process(input_filename, output_filename))  return kFALSE;

        if(!Write(CBTime))  return kFALSE;
        if(!Write(TAPSTime))  return kFALSE;
        if(!Write(CBTimeAfterCut))  return kFALSE;
        if(!Write(TAPSTimeAfterCut))  return kFALSE;
        return kTRUE;
    }

    if(!Open(input_filename))    return kFALSE;
    if(!OpenRawEvent())    return kFALSE;
    if(!OpenTagger())    return kFALSE;
    if(!OpenScalers())    return kFALSE;
    if(!OpenTrigger())    return kFALSE;

    if(!CreateTagger())    return kFALSE;
    if(!CreateEventFlags())    return kFALSE;
    if(!CreateTrigger())    return kFALSE;
    scalers->Clone(*file_out);

    file_out->cd();
    taggerTime  = new TH1D("TaggerTimeOR", "TaggerTimeOR", 10000, -1000, 1000);
    accepted    = new TH1I("Accepted", "Events with correct scalers (all=0,accepted=1,rejected=2)", 3, 0, 3);
    accepted->SetBinContent(1, rawEvent->GetNEntries());
    accepted->SetBinContent(2, rawEvent->GetNEntries());
    accepted->SetBinContent(3, 0);

    TraverseEntries(0, rawEvent->GetNEntries()+1);

    if(!Write())    return kFALSE;
    if(!Write(taggerTime))  return kFALSE;
    if(!Write(accepted))  return kFALSE;
    if(!Write(CBTime))  return kFALSE;
    if(!Write(TAPSTime))  return kFALSE;
    if(!Write(CBTimeAfterCut))  return kFALSE;
    if(!Write(TAPSTimeAfterCut))  return kFALSE;
    return kTRUE;
}
