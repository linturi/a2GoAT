#include "GPlot.h"


using namespace std;

//const Bool_t IsReversed = kTRUE;


GPlot::GPlot()
{
 //pi0
bin0_low=210; bin0_hi=240; bin1_low=240; bin1_hi= 270; bin2_low=270;bin2_hi= 300; bin3_low=300; bin3_hi= 330;
bin4_low=330;bin4_hi=360;bin5_low=360; bin5_hi=390; bin6_low=390; bin6_hi=420; bin7_low=420;bin7_hi=450;
bin8_low=450; bin8_hi=480; bin9_low=480; bin9_hi=510; bin10_low=510; bin10_hi=540; bin11_low=540;bin11_hi=570;
bin12_low=570; bin12_hi=600; bin13_low=600; bin13_hi=630; bin14_low=630; bin14_hi=660, bin15_low=660; bin15_hi=690;
bin16_low=690, bin16_hi=720; bin17_low=720; bin18_hi=750;bin19_low=750; bin19_hi=780; bin20_low=780; bin20_hi=810;
bin21_low=810; bin21_hi=840; bin22_low=840; bin22_hi=870; bin23_low=870; bin23_hi=900; bin24_low=900; bin24_hi=930;
bin25_low=930; bin25_hi=960;bin26_low=960; bin26_hi=990; bin27_low=990; bin27_hi=1020; bin28_low=1020; bin28_hi=1050;
bin29_low=1050; bin29_hi=1080; bin30_low=1080; bin30_hi=1110;bin31_low=1110; bin31_hi=1140; bin32_low=1140; bin32_hi=1170;
bin33_low=1170; bin33_hi =1200; bin34_low=1200; bin34_hi=1230; bin35_low=1230; bin35_hi=1260; bin36_low=1260; bin36_hi=1290;
bin37_low=1290; bin37_hi=1320; bin38_low=1320; bin38_hi=1350; bin39_low=1350; bin39_hi=1380; bin40_low=1380; bin3_40=1410;
//Eta
Ebin0_low=710; Ebin0_hi=740; Ebin1_low=740; Ebin1_hi= 770; Ebin2_low=770;Ebin2_hi= 800; Ebin3_low=800; Ebin3_hi= 850;
Ebin4_low=850;Ebin4_hi=900;Ebin5_low=900; Ebin5_hi=950; Ebin6_low=950; Ebin6_hi=1000; Ebin7_low=1000;Ebin7_hi=1050;
Ebin8_low=1050;Ebin8_hi=1100;Ebin9_low=1100; Ebin9_hi=1200; Ebin10_low=1200; Ebin10_hi=1300; Ebin11_low=1300;Ebin11_hi=1400;

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

           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > bin4_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < bin4_hi)
             {
                 pi0Hist4->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
                 pi0Hist4->FillPromptMeson(trigger->GetHelicityBit(), pi0->Particle(0));
                 pi0Hist4->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
             }

           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > bin5_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < bin5_hi)
             {
                 pi0Hist5->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
                 pi0Hist5->FillPromptMeson(trigger->GetHelicityBit(), pi0->Particle(0));
                 pi0Hist5->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
             }

           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > bin6_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < bin6_hi)
             {
                 pi0Hist6->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
                 pi0Hist6->FillPromptMeson(trigger->GetHelicityBit(), pi0->Particle(0));
                 pi0Hist6->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
             }

           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > bin7_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < bin7_hi)
             {
                 pi0Hist7->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
                 pi0Hist7->FillPromptMeson(trigger->GetHelicityBit(), pi0->Particle(0));
                 pi0Hist7->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
             }


            }
            //======================================================================================================================================================================================
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

           else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > bin4_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < bin4_hi)
           {
               pi0Hist4->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
               pi0Hist4->FillRandMeson(trigger->GetHelicityBit(), pi0->Particle(0));
               pi0Hist4->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
           }
           else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > bin5_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < bin5_hi)
           {
               pi0Hist5->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
               pi0Hist5->FillRandMeson(trigger->GetHelicityBit(), pi0->Particle(0));
               pi0Hist5->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
           }
           else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > bin6_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < bin6_hi)
           {
               pi0Hist6->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
               pi0Hist6->FillRandMeson(trigger->GetHelicityBit(), pi0->Particle(0));
               pi0Hist6->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
           }
           else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > bin7_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < bin7_hi)
           {
               pi0Hist7->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
               pi0Hist7->FillRandMeson(trigger->GetHelicityBit(), pi0->Particle(0));
               pi0Hist7->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(pi0->GetDaughterIndex(0,0)), photons->Particle(pi0->GetDaughterIndex(0,1)));
           }
            }
        }
//======================================================================================================================================================
      /* else if(eta->GetNParticles() == 1)
        {
            if(tagger->GetNPrompt() == 1)
            {
                  etaHist->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
                  etaHist->FillPromptMeson(trigger->GetHelicityBit(), eta->Particle(0));
                  etaHist->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));


           if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > Ebin0_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < Ebin0_hi)
            {
              etaHist0->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
              etaHist0->FillPromptMeson(trigger->GetHelicityBit(), eta->Particle(0));
              etaHist0->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
            }
           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > Ebin1_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < Ebin1_hi)
             {
               etaHist1->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
               etaHist1->FillPromptMeson(trigger->GetHelicityBit(), eta->Particle(0));
               etaHist1->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
             }

           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > Ebin2_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < Ebin2_hi)
             {
               etaHist2->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
               etaHist2->FillPromptMeson(trigger->GetHelicityBit(), eta->Particle(0));
               etaHist2->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
             }

           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > Ebin3_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < Ebin3_hi)
             {
               etaHist3->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
               etaHist3->FillPromptMeson(trigger->GetHelicityBit(), eta->Particle(0));
               etaHist3->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
             }

           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > Ebin4_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < Ebin4_hi)
             {
               etaHist4->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
               etaHist4->FillPromptMeson(trigger->GetHelicityBit(), eta->Particle(0));
               etaHist4->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
             }

           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > Ebin5_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < Ebin5_hi)
             {
               etaHist5->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
               etaHist5->FillPromptMeson(trigger->GetHelicityBit(), eta->Particle(0));
               etaHist5->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
             }

           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > Ebin6_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < Ebin6_hi)
             {
               etaHist6->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
               etaHist6->FillPromptMeson(trigger->GetHelicityBit(), eta->Particle(0));
               etaHist6->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
             }

           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > Ebin7_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < Ebin7_hi)
             {
               etaHist7->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
               etaHist7->FillPromptMeson(trigger->GetHelicityBit(), eta->Particle(0));
               etaHist7->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
             }

           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > Ebin8_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < Ebin8_hi)
             {
               etaHist8->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
               etaHist8->FillPromptMeson(trigger->GetHelicityBit(), eta->Particle(0));
               etaHist8->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
             }

           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > Ebin9_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < Ebin9_hi)
             {
               etaHist9->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
               etaHist9->FillPromptMeson(trigger->GetHelicityBit(), eta->Particle(0));
               etaHist9->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
             }

           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > Ebin10_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < Ebin10_hi)
             {
               etaHist10->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
               etaHist10->FillPromptMeson(trigger->GetHelicityBit(), eta->Particle(0));
               etaHist10->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
             }

           else if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) > Ebin11_low && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)) < Ebin11_hi)
             {
               etaHist11->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(0)),tagger->GetTagged_t(tagger->GetPromptIndex(0)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(0)),tagger->GetTagged_ch(tagger->GetPromptIndex(0)));
               etaHist11->FillPromptMeson(trigger->GetHelicityBit(), eta->Particle(0));
               etaHist11->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
             }
            }
            //===================================================================================================================
            if(tagger->GetNRand() == 1)
            {
             etaHist->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
             etaHist->FillRandMeson(trigger->GetHelicityBit(), eta->Particle(0));
             etaHist->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));


          if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > Ebin0_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < Ebin0_hi)
           {
             etaHist0->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
             etaHist0->FillRandMeson(trigger->GetHelicityBit(), eta->Particle(0));
             etaHist0->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
           }

           else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > Ebin1_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < Ebin1_hi)
           {
             etaHist1->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
             etaHist1->FillRandMeson(trigger->GetHelicityBit(), eta->Particle(0));
             etaHist1->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
           }
          else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > Ebin2_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < Ebin2_hi)
          {
            etaHist2->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
            etaHist2->FillRandMeson(trigger->GetHelicityBit(), eta->Particle(0));
            etaHist2->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
          }

          else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > Ebin3_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < Ebin3_hi)
          {
            etaHist3->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
            etaHist3->FillRandMeson(trigger->GetHelicityBit(), eta->Particle(0));
            etaHist3->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
          }

          else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > Ebin4_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < Ebin4_hi)
          {
            etaHist4->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
            etaHist4->FillRandMeson(trigger->GetHelicityBit(), eta->Particle(0));
            etaHist4->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
          }
          else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > Ebin5_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < Ebin5_hi)
          {
            etaHist5->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
            etaHist5->FillRandMeson(trigger->GetHelicityBit(), eta->Particle(0));
            etaHist5->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
          }
          else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > Ebin6_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < Ebin6_hi)
          {
            etaHist6->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
            etaHist6->FillRandMeson(trigger->GetHelicityBit(), eta->Particle(0));
            etaHist6->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
          }
          else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > Ebin7_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < Ebin7_hi)
          {
            etaHist7->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
            etaHist7->FillRandMeson(trigger->GetHelicityBit(), eta->Particle(0));
            etaHist7->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
          }

          else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > Ebin8_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < Ebin8_hi)
          {
            etaHist8->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
            etaHist8->FillRandMeson(trigger->GetHelicityBit(), eta->Particle(0));
            etaHist8->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
          }

          else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > Ebin9_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < Ebin9_hi)
          {
            etaHist9->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
            etaHist9->FillRandMeson(trigger->GetHelicityBit(), eta->Particle(0));
            etaHist9->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
          }

          else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > Ebin10_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < Ebin10_hi)
          {
            etaHist10->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
            etaHist10->FillRandMeson(trigger->GetHelicityBit(), eta->Particle(0));
            etaHist10->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
          }

          else if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) > Ebin11_low && tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)) < Ebin11_hi)
          {
            etaHist11->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(0)),tagger->GetTagged_t(tagger->GetRandIndex(0)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(0)),tagger->GetTagged_ch(tagger->GetRandIndex(0)));
            etaHist11->FillRandMeson(trigger->GetHelicityBit(), eta->Particle(0));
            etaHist11->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
          }
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
    gDirectory->mkdir("pi0_4");
    file_out->cd();
    gDirectory->mkdir("pi0_5");
    file_out->cd();
    gDirectory->mkdir("pi0_6");
    file_out->cd();
    gDirectory->mkdir("pi0_7");
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
    pi0Hist4 = new GHistHelTaggedMeson(gDirectory->GetDirectory("pi0_4"));
    file_out->cd();
    pi0Hist5 = new GHistHelTaggedMeson(gDirectory->GetDirectory("pi0_5"));
    file_out->cd();
    pi0Hist6 = new GHistHelTaggedMeson(gDirectory->GetDirectory("pi0_6"));
    file_out->cd();
    pi0Hist7 = new GHistHelTaggedMeson(gDirectory->GetDirectory("pi0_7"));


    //=================== Eta ================================
    /*file_out->cd();
    etaHist = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta"));
    file_out->cd();
    etaHist0 = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_0"));
    file_out->cd();
    etaHist1 = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_1"));
    file_out->cd();
    etaHist2 = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_2"));
    file_out->cd();
    etaHist3 = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_3"));
    file_out->cd();
    etaHist4 = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_4"));
    file_out->cd();
    etaHist5 = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_5"));
    file_out->cd();
    etaHist6 = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_6"));
    file_out->cd();
    etaHist7 = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_7"));
    file_out->cd();
    etaHist8 = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_8"));
    file_out->cd();
    etaHist9 = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_9"));
    file_out->cd();
    etaHist10 = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_10"));
    file_out->cd();
    etaHist11 = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_11"));*/

    //file_out->cd();
   // etapHist = new GHistTaggedEtap(gDirectory->GetDirectory("etap"));

    TraverseEntries(0, pi0->GetNEntries()+1);

    pi0Hist->Write();
    pi0Hist0->Write();
    pi0Hist1->Write();
    pi0Hist2->Write();
    pi0Hist3->Write();
    pi0Hist4->Write();
    pi0Hist5->Write();
    pi0Hist6->Write();
    pi0Hist7->Write();
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

