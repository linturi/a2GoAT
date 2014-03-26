#include "GPlotJames.h"


using namespace std;

//const Bool_t IsReversed = kTRUE;


GPlotJames::GPlotJames()
{

}

GPlotJames::~GPlotJames()
{
   // if(file)    delete file;
}

void  GPlotJames::ProcessEvent()
{
    if(photons->GetNParticles() == 2)
    {
        if(pi0->GetNParticles() == 1)
        {
            for(int i=0; i<1; i++)
            {
                for(int w=0; w<5; w++)
                {
                    if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(i)) > cuts[w] && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(i)) < cuts[w+1])
                    {
                        TLorentzVector  mis(0,0,tagger->GetPhotonBeam_E(tagger->GetPromptIndex(i)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(i)) + MASS_PROTON);
                        mis = mis - photons->Particle(0);
                        mis = mis - photons->Particle(1);
                        misMassPrompt[w]->Fill(mis.M());
                    }
                }
            }
            for(int i=0; i<1; i++)
            {
                for(int w=0; w<5; w++)
                {
                    if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(i)) > cuts[w] && tagger->GetPhotonBeam_E(tagger->GetRandIndex(i)) < cuts[w+1])
                    {
                        TLorentzVector  mis(0,0,tagger->GetPhotonBeam_E(tagger->GetRandIndex(i)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(i)) + MASS_PROTON);
                        mis = mis - photons->Particle(0);
                        mis = mis - photons->Particle(1);
                        misMassRand[w]->Fill(mis.M());
                    }
                }
            }
        }
    }
/*
        else if(eta->GetNParticles() == 1)
        {
            if(tagger->GetNPrompt() == 1)
            {
                etaHist->FillPromptTagger(trigger->GetHelicityBit(),tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
                etaHist->FillPromptMeson(trigger->GetHelicityBit(), eta->Particle(0));
                etaHist->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
            }
            if(tagger->GetNRand() == 1)
            {
                etaHist->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
                etaHist->FillRandMeson(trigger->GetHelicityBit(), eta->Particle(0));
                etaHist->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
            }
        }*/
        /*else if(etap->GetNParticles() == 1)
        {
            if(tagger->GetNPrompt() == 1)
            {
                etapHist->FillPromptTagger(tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
                etapHist->FillPromptDaughterMeson(etap->Particle(0));
                etapHist->FillPromptDaughterPhoton(photons->Particle(etap->GetDaughterIndex(0,0)), photons->Particle(etap->GetDaughterIndex(0,1)));
            }
            if(tagger->GetNRand() == 1)
            {
                etapHist->FillRandTagger(tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
                etapHist->FillRandDaughterMeson(etap->Particle(0));
                etapHist->FillRandDaughterPhoton(photons->Particle(etap->GetDaughterIndex(0,0)), photons->Particle(etap->GetDaughterIndex(0,1)));
            }
        }
    }*/

    /*else if(photons->GetNParticles() == 6)
    {
        if(etap->GetNParticles() == 1)
        {
            if(tagger->GetNPrompt() == 1)
            {
                etapHist->FillPromptTagger(tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
                etapHist->FillPromptMeson(etap->Particle(0));
                etapHist->FillPromptDaughterMesons(pi0->Particle(0), pi0->Particle(1), eta->Particle(0));
                etapHist->FillPromptDaughterPhotons(0, photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
                etapHist->FillPromptDaughterPhotons(1, photons->Particle(pi0->GetDaughterIndex(1,0)), photons->Particle(pi0->GetDaughterIndex(1,1)));
                etapHist->FillPromptDaughterPhotons(2, photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
            }
            if(tagger->GetNRand() == 1)
            {
                etapHist->FillRandTagger(tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
                etapHist->FillRandMeson(etap->Particle(0));
                etapHist->FillRandDaughterMesons(pi0->Particle(0), pi0->Particle(1), eta->Particle(0));
                etapHist->FillRandDaughterPhotons(0, photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
                etapHist->FillRandDaughterPhotons(1, photons->Particle(pi0->GetDaughterIndex(1,0)), photons->Particle(pi0->GetDaughterIndex(1,1)));
                etapHist->FillRandDaughterPhotons(2, photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
            }
        }
        else if(eta->GetNParticles() == 1)
        {
            if(tagger->GetNPrompt() == 1)
            {
                etaHist->FillPromptTagger(tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
                etaHist->FillPromptMeson(eta->Particle(0));
                etaHist->FillPromptDaughterMesons(pi0->Particle(0), pi0->Particle(1), pi0->Particle(2));
                etaHist->FillPromptDaughterPhotons(0, photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
                etaHist->FillPromptDaughterPhotons(1, photons->Particle(pi0->GetDaughterIndex(1,0)), photons->Particle(pi0->GetDaughterIndex(1,1)));
                etaHist->FillPromptDaughterPhotons(2, photons->Particle(pi0->GetDaughterIndex(2,0)), photons->Particle(pi0->GetDaughterIndex(2,1)));
            }
            if(tagger->GetNRand() == 1)
            {
                etaHist->FillRandTagger(tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
                etaHist->FillRandMeson(eta->Particle(0));
                etaHist->FillRandDaughterMesons(pi0->Particle(0), pi0->Particle(1), pi0->Particle(2));
                etaHist->FillRandDaughterPhotons(0, photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
                etaHist->FillRandDaughterPhotons(1, photons->Particle(pi0->GetDaughterIndex(1,0)), photons->Particle(pi0->GetDaughterIndex(1,1)));
                etaHist->FillRandDaughterPhotons(2, photons->Particle(pi0->GetDaughterIndex(2,0)), photons->Particle(pi0->GetDaughterIndex(2,1)));
            }
        }
        else    //3pi0
        {
            if(tagger->GetNPrompt() == 1)
            {
                _3pi0Hist->FillPromptTagger(tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
                _3pi0Hist->FillPromptMeson(pi0->Particle(0) + pi0->Particle(1) + pi0->Particle(2));
                _3pi0Hist->FillPromptDaughterMesons(pi0->Particle(0), pi0->Particle(1), pi0->Particle(2));
                _3pi0Hist->FillPromptDaughterPhotons(0, photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
                _3pi0Hist->FillPromptDaughterPhotons(1, photons->Particle(pi0->GetDaughterIndex(1,0)), photons->Particle(pi0->GetDaughterIndex(1,1)));
                _3pi0Hist->FillPromptDaughterPhotons(2, photons->Particle(pi0->GetDaughterIndex(2,0)), photons->Particle(pi0->GetDaughterIndex(2,1)));
            }
            if(tagger->GetNRand() == 1)
            {
                _3pi0Hist->FillRandTagger(tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
                _3pi0Hist->FillRandMeson(pi0->Particle(0) + pi0->Particle(1) + pi0->Particle(2));
                _3pi0Hist->FillRandDaughterMesons(pi0->Particle(0), pi0->Particle(1), pi0->Particle(2));
                _3pi0Hist->FillRandDaughterPhotons(0, photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
                _3pi0Hist->FillRandDaughterPhotons(1, photons->Particle(pi0->GetDaughterIndex(1,0)), photons->Particle(pi0->GetDaughterIndex(1,1)));
                _3pi0Hist->FillRandDaughterPhotons(2, photons->Particle(pi0->GetDaughterIndex(2,0)), photons->Particle(pi0->GetDaughterIndex(2,1)));
            }
        }
    }*/
}

Bool_t  GPlotJames::Process(const char* input_filename, const char* output_filename)
{
    if(!Open(input_filename))    return kFALSE;
    if(!OpenPhotons())    return kFALSE;
    if(!OpenEtap())    return kFALSE;
    if(!OpenEta())    return kFALSE;
    if(!OpenPi0())    return kFALSE;
    if(!OpenTagger())    return kFALSE;
    if(!OpenTrigger())    return kFALSE;

    if(!Create(output_filename))    return kFALSE;

    misMassPrompt[0]    = new TH1D("misMasspromptBin0", "misMasspromptBin0", 2000, 0, 2000);
    misMassPrompt[1]    = new TH1D("misMasspromptBin1", "misMasspromptBin1", 2000, 0, 2000);
    misMassPrompt[2]    = new TH1D("misMasspromptBin2", "misMasspromptBin2", 2000, 0, 2000);
    misMassPrompt[3]    = new TH1D("misMasspromptBin3", "misMasspromptBin3", 2000, 0, 2000);
    misMassPrompt[4]    = new TH1D("misMasspromptBin4", "misMasspromptBin4", 2000, 0, 2000);
    misMassPrompt[5]    = new TH1D("misMasspromptBin5", "misMasspromptBin5", 2000, 0, 2000);

    misMassRand[0]    = new TH1D("misMassRandBin0", "misMassRandBin0", 2000, 0, 2000);
    misMassRand[1]    = new TH1D("misMassRandBin1", "misMassRandBin1", 2000, 0, 2000);
    misMassRand[2]    = new TH1D("misMassRandBin2", "misMassRandBin2", 2000, 0, 2000);
    misMassRand[3]    = new TH1D("misMassRandBin3", "misMassRandBin3", 2000, 0, 2000);
    misMassRand[4]    = new TH1D("misMassRandBin4", "misMassRandBin4", 2000, 0, 2000);
    misMassRand[5]    = new TH1D("misMassRandBin5", "misMassRandBin5", 2000, 0, 2000);

    misMass[0]    = new TH1D("misMassBin0", "misMassBin0", 2000, 0, 2000);
    misMass[1]    = new TH1D("misMassBin1", "misMassBin1", 2000, 0, 2000);
    misMass[2]    = new TH1D("misMassBin2", "misMassBin2", 2000, 0, 2000);
    misMass[3]    = new TH1D("misMassBin3", "misMassBin3", 2000, 0, 2000);
    misMass[4]    = new TH1D("misMassBin4", "misMassBin4", 2000, 0, 2000);
    misMass[5]    = new TH1D("misMassBin5", "misMassBin5", 2000, 0, 2000);

    TraverseEntries(0, pi0->GetNEntries()+1);

    for(int i=0; i<6; i++)
    {
        Write(misMassPrompt[i]);
        Write(misMassRand[i]);
        misMass[i]->Reset();
        misMass[i]->Add(misMassPrompt[i]);
        misMass[i]->Add(misMassRand[i], -0.75);
        Write(misMass[i]);
    }

    return kTRUE;
}


Int_t   GPlotJames::cuts[7] =
{
    180,
    220,
    260,
    300,
    340,
    380,
    420
};
