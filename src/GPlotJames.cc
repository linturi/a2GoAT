#include "GPlotJames.h"


using namespace std;

//const Bool_t IsReversed = kTRUE;


GPlotJames::GPlotJames()
{

}

GPlotJames::~GPlotJames()
{
}

void  GPlotJames::ProcessEvent()
{
    if(photons->GetNParticles() == 2)
    {
        if(pi0->GetNParticles() == 1)
        {
            for(int i=0;i<tagger->GetNPrompt(); i++)
            //if(tagger->GetNPrompt()==1)
            {
                for(int l=0; l<=15; l++)
                {
                    if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(i))>=((30*l)+210) && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(i))<=((30*(l+1))+210))
                    {
                        pi0Histall[l]->FillPromptTagger(tagger->GetMissingVector(tagger->GetPromptIndex(i)),tagger->GetTagged_t(tagger->GetPromptIndex(i)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(i)),tagger->GetTagged_ch(tagger->GetPromptIndex(i)));
                        pi0Histall[l]->FillPromptMeson(pi0->Particle(0));
                        pi0Histall[l]->FillPromptPhoton(photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
                    }
                }
            }
            for(int i=0;i<tagger->GetNRand(); i++)
            //if(tagger->GetNRand()==1)
            {
                for(int l=0; l<=15; l++)
                {
                    if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(i))>=((30*l)+210) && tagger->GetPhotonBeam_E(tagger->GetRandIndex(i))<=((30*(l+1))+210))
                    {
                        pi0Histall[l]->FillRandTagger(tagger->GetMissingVector(tagger->GetRandIndex(i)),tagger->GetTagged_t(tagger->GetRandIndex(i)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(i)),tagger->GetTagged_ch(tagger->GetRandIndex(i)));
                        pi0Histall[l]->FillRandMeson(pi0->Particle(0));
                        pi0Histall[l]->FillRandPhoton(photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
                    }
                }
            }
        }

//======================================================================================================================================================
    /*   else if(eta->GetNParticles() == 1)
        {
            if(tagger->GetNPrompt() == 1)
            {
                  etaHist->FillPromptTagger( tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
                  etaHist->FillPromptMeson( eta->Particle(0));
                  etaHist->FillPromptPhoton( photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));


           if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > Ebin0_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < Ebin0_hi)
            {
              etaHist0->FillPromptTagger( tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
              etaHist0->FillPromptMeson( eta->Particle(0));
              etaHist0->FillPromptPhoton( photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
            }

            }
            //===================================================================================================================
            if(tagger->GetNRand() == 1)
            {
             etaHist->FillRandTagger( tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
             etaHist->FillRandMeson( eta->Particle(0));
             etaHist->FillRandPhoton( photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));


          if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > Ebin0_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < Ebin0_hi)
           {
             etaHist0->FillRandTagger( tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
             etaHist0->FillRandMeson( eta->Particle(0));
             etaHist0->FillRandPhoton( photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
           }


        }
        }*/


    }


}

Bool_t  GPlotJames::Process(const char* input_filename, const char* output_filename)
{
    if(!Open(input_filename))    return kFALSE;
    if(!OpenPhotons())    return kFALSE;
   // if(!OpenEtap())    return kFALSE;
    if(!OpenEta())    return kFALSE;
    if(!OpenPi0())    return kFALSE;
    if(!OpenTagger())    return kFALSE;
    if(!OpenTrigger())    return kFALSE;

    if(!Create(output_filename))    return kFALSE;

    //file_out->cd(); gDirectory->mkdir("pi0");
    file_out->cd(); gDirectory->mkdir("pi0_0");
    file_out->cd(); gDirectory->mkdir("pi0_1");
    file_out->cd(); gDirectory->mkdir("pi0_2");
    file_out->cd(); gDirectory->mkdir("pi0_3");
    file_out->cd(); gDirectory->mkdir("pi0_4");
    file_out->cd(); gDirectory->mkdir("pi0_5");
    file_out->cd(); gDirectory->mkdir("pi0_6");
    file_out->cd(); gDirectory->mkdir("pi0_7");
    file_out->cd(); gDirectory->mkdir("pi0_8");
    file_out->cd(); gDirectory->mkdir("pi0_9");
    file_out->cd(); gDirectory->mkdir("pi0_10");
    file_out->cd(); gDirectory->mkdir("pi0_11");
    file_out->cd(); gDirectory->mkdir("pi0_12");
    file_out->cd(); gDirectory->mkdir("pi0_13");
    file_out->cd(); gDirectory->mkdir("pi0_14");
    file_out->cd(); gDirectory->mkdir("pi0_15");
    /*file_out->cd(); gDirectory->mkdir("pi0_16");
    file_out->cd(); gDirectory->mkdir("pi0_17");
    file_out->cd(); gDirectory->mkdir("pi0_18");
    file_out->cd(); gDirectory->mkdir("pi0_19");
    file_out->cd(); gDirectory->mkdir("pi0_20");
    file_out->cd(); gDirectory->mkdir("pi0_21");
    file_out->cd(); gDirectory->mkdir("pi0_22");
    file_out->cd(); gDirectory->mkdir("pi0_23");
    file_out->cd(); gDirectory->mkdir("pi0_24");
    file_out->cd(); gDirectory->mkdir("pi0_25");
    file_out->cd(); gDirectory->mkdir("pi0_26");
    file_out->cd(); gDirectory->mkdir("pi0_27");
    file_out->cd(); gDirectory->mkdir("pi0_28");
    file_out->cd(); gDirectory->mkdir("pi0_29");
    file_out->cd(); gDirectory->mkdir("pi0_30");
    file_out->cd(); gDirectory->mkdir("pi0_31");
    file_out->cd(); gDirectory->mkdir("pi0_32");
    file_out->cd(); gDirectory->mkdir("pi0_33");
    file_out->cd(); gDirectory->mkdir("pi0_34");
    file_out->cd(); gDirectory->mkdir("pi0_35");
    file_out->cd(); gDirectory->mkdir("pi0_36");
    file_out->cd(); gDirectory->mkdir("pi0_37");
    file_out->cd(); gDirectory->mkdir("pi0_38");
    file_out->cd(); gDirectory->mkdir("pi0_39");
    file_out->cd(); gDirectory->mkdir("pi0_40");
    file_out->cd(); gDirectory->mkdir("pi0_41");*/
    //file_out->cd(); gDirectory->mkdir("pi0_42");

    //=================Eta starts here==========================
    /*file_out->cd();
    gDirectory->mkdir("eta");
    file_out->cd();
    gDirectory->mkdir("eta_0");
    file_out->cd();
    gDirectory->mkdir("eta_1");
    file_out->cd();
    gDirectory->mkdir("eta_2");
    file_out->cd();
    gDirectory->mkdir("eta_3");
    file_out->cd();
    gDirectory->mkdir("eta_4");
    file_out->cd();
    gDirectory->mkdir("eta_5");
    file_out->cd();
    gDirectory->mkdir("eta_6");
    file_out->cd();
    gDirectory->mkdir("eta_7");
    file_out->cd();
    gDirectory->mkdir("eta_8");
    file_out->cd();
    gDirectory->mkdir("eta_9");
    file_out->cd();
    gDirectory->mkdir("eta_10");
    file_out->cd();
    gDirectory->mkdir("eta_11");*/
   // file_out->cd();
    //gDirectory->mkdir("etap");

    file_out->cd();pi0Histall[0] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_0"));
    file_out->cd();pi0Histall[1] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_1"));
    file_out->cd();pi0Histall[2] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_2"));
    file_out->cd();pi0Histall[3] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_3"));
    file_out->cd();pi0Histall[4] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_4"));
    file_out->cd();pi0Histall[5] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_5"));
    file_out->cd();pi0Histall[6] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_6"));
    file_out->cd();pi0Histall[7] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_7"));
    file_out->cd();pi0Histall[8] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_8"));
    file_out->cd();pi0Histall[9] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_9"));
    file_out->cd();pi0Histall[10] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_10"));
    file_out->cd();pi0Histall[11] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_11"));
    file_out->cd();pi0Histall[12] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_12"));
    file_out->cd();pi0Histall[13] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_13"));
    file_out->cd();pi0Histall[14] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_14"));
    file_out->cd();pi0Histall[15] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_15"));
    /*file_out->cd();pi0Histall[16] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_16"));
    file_out->cd();pi0Histall[17] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_17"));
    file_out->cd();pi0Histall[18] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_18"));
    file_out->cd();pi0Histall[19] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_19"));
    file_out->cd();pi0Histall[20] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_20"));
    file_out->cd();pi0Histall[21] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_21"));
    file_out->cd();pi0Histall[22] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_22"));
    file_out->cd();pi0Histall[23] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_23"));
    file_out->cd();pi0Histall[24] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_24"));
    file_out->cd();pi0Histall[25] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_25"));
    file_out->cd();pi0Histall[26] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_26"));
    file_out->cd();pi0Histall[27] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_27"));
    file_out->cd();pi0Histall[28] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_28"));
    file_out->cd();pi0Histall[29] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_29"));
    file_out->cd();pi0Histall[30] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_30"));
    file_out->cd();pi0Histall[31] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_31"));
    file_out->cd();pi0Histall[32] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_32"));
    file_out->cd();pi0Histall[33] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_33"));
    file_out->cd();pi0Histall[34] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_34"));
    file_out->cd();pi0Histall[35] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_35"));
    file_out->cd();pi0Histall[36] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_36"));
    file_out->cd();pi0Histall[37] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_37"));
    file_out->cd();pi0Histall[38] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_38"));
    file_out->cd();pi0Histall[39] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_39"));
    file_out->cd();pi0Histall[40] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_40"));
    file_out->cd();pi0Histall[41] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_41"));*/
    //file_out->cd();pi0Histall[42] = new GHistTaggedMeson(gDirectory->GetDirectory("pi0_42"));




    //=================== Eta ================================
    /*file_out->cd();
    etaHist = new GHistTaggedMeson(gDirectory->GetDirectory("eta"));
    file_out->cd();
    etaHist0 = new GHistTaggedMeson(gDirectory->GetDirectory("eta_0"));
    file_out->cd();
    etaHist1 = new GHistTaggedMeson(gDirectory->GetDirectory("eta_1"));
    file_out->cd();
    etaHist2 = new GHistTaggedMeson(gDirectory->GetDirectory("eta_2"));
    file_out->cd();
    etaHist3 = new GHistTaggedMeson(gDirectory->GetDirectory("eta_3"));
    file_out->cd();
    etaHist4 = new GHistTaggedMeson(gDirectory->GetDirectory("eta_4"));
    file_out->cd();
    etaHist5 = new GHistTaggedMeson(gDirectory->GetDirectory("eta_5"));
    file_out->cd();
    etaHist6 = new GHistTaggedMeson(gDirectory->GetDirectory("eta_6"));
    file_out->cd();
    etaHist7 = new GHistTaggedMeson(gDirectory->GetDirectory("eta_7"));
    file_out->cd();
    etaHist8 = new GHistTaggedMeson(gDirectory->GetDirectory("eta_8"));
    file_out->cd();
    etaHist9 = new GHistTaggedMeson(gDirectory->GetDirectory("eta_9"));
    file_out->cd();
    etaHist10 = new GHistTaggedMeson(gDirectory->GetDirectory("eta_10"));
    file_out->cd();
    etaHist11 = new GHistTaggedMeson(gDirectory->GetDirectory("eta_11"));*/

    //file_out->cd();
   // etapHist = new GHistTaggedEtap(gDirectory->GetDirectory("etap"));

    TraverseEntries(0, pi0->GetNEntries()+1);

    for(int j=0; j<=15;j++)
    {
    pi0Histall[j]->Write();
    }

    //=============Eta=================================
 /*    TraverseEntries(0, eta->GetNEntries()+1);
    etaHist->Write();
    etaHist0->Write();
    etaHist1->Write();
    etaHist2->Write();
    etaHist3->Write();
    etaHist4->Write();
    etaHist5->Write();
    etaHist6->Write();
    etaHist7->Write();
    etaHist8->Write();
    etaHist9->Write();
    etaHist10->Write();
    etaHist11->Write();*/
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

