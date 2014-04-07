#include "GPlot.h"


using namespace std;

//const Bool_t IsReversed = kTRUE;


GPlot::GPlot()
{
bin0_low=1110; bin0_hi=1140; bin1_low=210; bin1_hi= 240; bin2_low=240;
bin2_hi= 270; bin3_low=270; bin3_hi= 300; bin4_low=300;bin4_hi=330;
bin5_low=330; bin5_hi=360; bin6_low=360; bin6_hi=390; bin7_low=390;
bin7_hi=420;


}

GPlot::~GPlot()
{
}

void  GPlot::ProcessEvent()
{
    if(photons->GetNParticles() == 2)
    {
        if(pi0->GetNParticles() == 1)
        {
            if(tagger->GetNPrompt() == 1)
            {
                    pi0Hist->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
                    pi0Hist->FillPromptMeson(trigger->GetHelicityBit(), pi0->Particle(0));
                    pi0Hist->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));


           if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > bin0_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < bin0_hi)
            {
                pi0Hist0->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
                pi0Hist0->FillPromptMeson(trigger->GetHelicityBit(), pi0->Particle(0));
                pi0Hist0->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
            }
           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > bin1_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < bin1_hi)
             {
                 pi0Hist1->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
                 pi0Hist1->FillPromptMeson(trigger->GetHelicityBit(), pi0->Particle(0));
                 pi0Hist1->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
             }

           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > bin2_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < bin2_hi)
             {
                 pi0Hist2->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
                 pi0Hist2->FillPromptMeson(trigger->GetHelicityBit(), pi0->Particle(0));
                 pi0Hist2->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
             }

           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > bin3_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < bin3_hi)
             {
                 pi0Hist3->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
                 pi0Hist3->FillPromptMeson(trigger->GetHelicityBit(), pi0->Particle(0));
                 pi0Hist3->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
             }

            }
            if(tagger->GetNRand() == 1)
             {
                pi0Hist->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
                pi0Hist->FillRandMeson(trigger->GetHelicityBit(), pi0->Particle(0));
                pi0Hist->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));


           if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > bin0_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < bin0_hi)
            {
                pi0Hist0->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
                pi0Hist0->FillRandMeson(trigger->GetHelicityBit(), pi0->Particle(0));
                pi0Hist0->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
            }

            else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > bin1_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < bin1_hi)
            {
                pi0Hist1->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
                pi0Hist1->FillRandMeson(trigger->GetHelicityBit(), pi0->Particle(0));
                pi0Hist1->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
            }
           else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > bin2_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < bin2_hi)
           {
               pi0Hist2->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
               pi0Hist2->FillRandMeson(trigger->GetHelicityBit(), pi0->Particle(0));
               pi0Hist2->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
           }

           else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > bin3_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < bin3_hi)
           {
               pi0Hist3->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
               pi0Hist3->FillRandMeson(trigger->GetHelicityBit(), pi0->Particle(0));
               pi0Hist3->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
           }
            }
        }

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
        }
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
        }*/
    }

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

Bool_t  GPlot::Process(const char* input_filename, const char* output_filename)
{
    if(!Open(input_filename))    return kFALSE;
    if(!OpenPhotons())    return kFALSE;
    if(!OpenEtap())    return kFALSE;
    if(!OpenEta())    return kFALSE;
    if(!OpenPi0())    return kFALSE;
    if(!OpenTagger())    return kFALSE;
    if(!OpenTrigger())    return kFALSE;

    if(!Create(output_filename))    return kFALSE;

    file_out->cd();
    gDirectory->mkdir("pi0");
    file_out->cd();
    gDirectory->mkdir("pi0_0");
    file_out->cd();
    gDirectory->mkdir("pi0_1");
    file_out->cd();
    gDirectory->mkdir("pi0_2");
    file_out->cd();
    gDirectory->mkdir("pi0_3");
    file_out->cd();
    gDirectory->mkdir("eta");
   // file_out->cd();
    //gDirectory->mkdir("etap");

    file_out->cd();
    pi0Hist = new GHistHelTaggedMeson(gDirectory->GetDirectory("pi0"));
    file_out->cd();
    pi0Hist0 = new GHistHelTaggedMeson(gDirectory->GetDirectory("pi0_0"));
    file_out->cd();
    pi0Hist1 = new GHistHelTaggedMeson(gDirectory->GetDirectory("pi0_1"));
    file_out->cd();
    pi0Hist2 = new GHistHelTaggedMeson(gDirectory->GetDirectory("pi0_2"));
    file_out->cd();
    pi0Hist3 = new GHistHelTaggedMeson(gDirectory->GetDirectory("pi0_3"));
    file_out->cd();
    etaHist = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta"));
    //file_out->cd();
   // etapHist = new GHistTaggedEtap(gDirectory->GetDirectory("etap"));

    TraverseEntries(0, pi0->GetNEntries()+1);

    pi0Hist->Write();
    pi0Hist0->Write();
    pi0Hist1->Write();
    pi0Hist2->Write();
    pi0Hist3->Write();
    etaHist->Write();
    //etapHist->Write();
    /*hist->Write(&taggerTime);
    TH1D    diff(protonAngleDiffPrompt);
    diff.SetNameTitle("protonAngleDiffPromptRandSubst", "Proton Angle Difference Prompt/Rand Substracted");
    diff.Add(&protonAngleDiffRand,-1);
    TH1D    diffNormed(protonAngleDiffPrompt);
    diffNormed.SetNameTitle("protonAngleDiffPromptRandSubstNorm", "Proton Angle Difference Prompt/Rand Substracted Normalised");
    diffNormed.Add(&protonAngleDiffRand,-protonAngleDiffPrompt.GetMaximum()/protonAngleDiffRand.GetMaximum());
    hist->Write(&protonAngleDiffPrompt);
    hist->Write(&protonAngleDiffRand);
    hist->Write(&diff);
    hist->Write(&diffNormed);*/

    return kTRUE;
}

