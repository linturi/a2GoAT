#include "GCorrectScalers.h"


using namespace std;


GCorrectScalers::GCorrectScalers()  :
    taggerTime(0)
{
}

GCorrectScalers::~GCorrectScalers()
{

}

void  GCorrectScalers::ProcessEvent()
{
    if(rawEvent->GetNCB() != 2 && rawEvent->GetNCB() != 6 && rawEvent->GetNCB() != 10)
        return;

    //accepted->Fill(0);
    for(int i=0; i<tagger->GetNTagged(); i++)
        taggerTime->Fill(tagger->GetTagged_t(i));

    photons->Clear();
    protons->Clear();
    eventFlags->SetEventNumber(actualEvent);
    for(Int_t i=0; i<rawEvent->GetNParticles(); i++)
    {
        if(rawEvent->GetApparatus(i) == GTreeRawEvent::APPARATUS_CB)
            photons->AddParticle(rawEvent->GetVector(i), i);
        if(rawEvent->GetApparatus(i) == GTreeRawEvent::APPARATUS_TAPS)
            protons->AddParticle(rawEvent->GetVector(i, 938.272046), i);
    }
    eventFlags->Fill();
    tagger->Fill();
    photons->Fill();
    protons->Fill();
    trigger->Fill();
    actualEvent++;
}

Bool_t  GCorrectScalers::Process(const char* input_filename, const char* output_filename)
{
    if(!Open(input_filename))    return kFALSE;
    if(!OpenRawEvent())    return kFALSE;
    if(!OpenTagger())    return kFALSE;
    if(!OpenScalers())    return kFALSE;
    if(!OpenTrigger())    return kFALSE;
    //if(!OpenEventFlags())    return kFALSE;

    if(scalers->GetNEntries()<2)    return kFALSE;
    scalers->GetEntry(0);
    EventAtFirstScalerRead   = scalers->GetEventNumber();
    scalers->GetEntry(scalers->GetNEntries()-1);
    EventAtLastScalerRead       = scalers->GetEventNumber();

    if(!Create(output_filename))    return kFALSE;
    if(!CreatePhotons())    return kFALSE;
    if(!CreateProtons())    return kFALSE;
    if(!CreateTagger())    return kFALSE;
    if(!CreateEventFlags())    return kFALSE;
    if(!CreateTrigger())    return kFALSE;
    scalers->Clone(*file_out);

    file_out->cd();
    taggerTime  = new TH1D("TaggerTimeOR", "TaggerTimeOR", 1000, -100, 100);
    accepted    = new TH1I("Accepted", "Events with correct scalers (all=0,accepted=1,rejected=2)", 3, 0, 3);
    accepted->SetBinContent(1, rawEvent->GetNEntries());
    accepted->SetBinContent(2, EventAtLastScalerRead-EventAtFirstScalerRead);
    accepted->SetBinContent(3, (EventAtFirstScalerRead+1)+(rawEvent->GetNEntries()-EventAtLastScalerRead-1));

    actualEvent = EventAtFirstScalerRead;
    TraverseEntries(EventAtFirstScalerRead+1, EventAtLastScalerRead);

    if(!Write())    return kFALSE;
    if(!Write(taggerTime))  return kFALSE;
    if(!Write(accepted))  return kFALSE;
    return kTRUE;
}
