#include "GPlotEtabins.h"


using namespace std;

//const Bool_t IsReversed = kTRUE;


GPlotEtabins::GPlotEtabins()
{

}

GPlotEtabins::~GPlotEtabins()
{
}

void  GPlotEtabins::ProcessEvent()
{
    if(photons->GetNParticles() == 2)
    {
        if(eta->GetNParticles() == 1)
        {
            for(int i=0;i<tagger->GetNPrompt(); i++)
             //if(tagger->GetNPrompt()==1)
            {
                for(int l=0; l<=6; l++)
                {
                    if(tagger->GetPhotonBeam_E(tagger->GetPromptIndex(i))>=((30*l)+710) && tagger->GetPhotonBeam_E(tagger->GetPromptIndex(i))<=((30*(l+1))+710))
                    {
                        etaHist[l]->FillPromptTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetPromptIndex(i)),tagger->GetTagged_t(tagger->GetPromptIndex(i)),tagger->GetPhotonBeam_E(tagger->GetPromptIndex(i)),tagger->GetTagged_ch(tagger->GetPromptIndex(i)));
                        etaHist[l]->FillPromptMeson(trigger->GetHelicityBit(), eta->Particle(0));
                        etaHist[l]->FillPromptPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
                    }
                }
            }
            for(int i=0;i<tagger->GetNRand(); i++)
            //if(tagger->GetNRand()==1)
            {
                for(int l=0; l<=6; l++)
                {
                    if(tagger->GetPhotonBeam_E(tagger->GetRandIndex(i))>=((30*l)+710) && tagger->GetPhotonBeam_E(tagger->GetRandIndex(i))<=((30*(l+1))+710))
                    {
                        etaHist[l]->FillRandTagger(trigger->GetHelicityBit(), tagger->GetMissingVector(tagger->GetRandIndex(i)),tagger->GetTagged_t(tagger->GetRandIndex(i)),tagger->GetPhotonBeam_E(tagger->GetRandIndex(i)),tagger->GetTagged_ch(tagger->GetRandIndex(i)));
                        etaHist[l]->FillRandMeson(trigger->GetHelicityBit(), eta->Particle(0));
                        etaHist[l]->FillRandPhoton(trigger->GetHelicityBit(), photons->Particle(eta->GetDaughterIndex(0,0)), photons->Particle(eta->GetDaughterIndex(0,1)));
                    }
                }
            }
        }



    }


}

Bool_t  GPlotEtabins::Process(const char* input_filename, const char* output_filename)
{
    if(!Open(input_filename))    return kFALSE;
    if(!OpenPhotons())    return kFALSE;
    //if(!OpenEtap())    return kFALSE;
    if(!OpenEta())    return kFALSE;
    //if(!OpenPi0())    return kFALSE;
    if(!OpenTagger())    return kFALSE;
    if(!OpenTrigger())    return kFALSE;

    if(!Create(output_filename))    return kFALSE;

    //file_out->cd(); gDirectory->mkdir("eta");
    file_out->cd(); gDirectory->mkdir("eta_0");
    file_out->cd(); gDirectory->mkdir("eta_1");
    file_out->cd(); gDirectory->mkdir("eta_2");
    file_out->cd(); gDirectory->mkdir("eta_3");
    file_out->cd(); gDirectory->mkdir("eta_4");
    file_out->cd(); gDirectory->mkdir("eta_5");
    file_out->cd(); gDirectory->mkdir("eta_6");
   /* file_out->cd(); gDirectory->mkdir("eta_7");
    file_out->cd(); gDirectory->mkdir("eta_8");
    file_out->cd(); gDirectory->mkdir("eta_9");
    file_out->cd(); gDirectory->mkdir("eta_10");
    file_out->cd(); gDirectory->mkdir("eta_11");
    file_out->cd(); gDirectory->mkdir("eta_12");
    file_out->cd(); gDirectory->mkdir("eta_13");
    file_out->cd(); gDirectory->mkdir("eta_14");
    file_out->cd(); gDirectory->mkdir("eta_15");
   */

    file_out->cd(); etaHist[0] = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_0"));
    file_out->cd(); etaHist[1] = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_1"));
    file_out->cd(); etaHist[2] = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_2"));
    file_out->cd(); etaHist[3] = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_3"));
    file_out->cd(); etaHist[4] = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_4"));
    file_out->cd(); etaHist[5] = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_5"));
    file_out->cd(); etaHist[6] = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_6"));
    /*file_out->cd(); etaHist[7] = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_7"));
    file_out->cd(); etaHist[8] = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_8"));
    file_out->cd(); etaHist[9] = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_9"));
    file_out->cd(); etaHist[10] = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_10"));
    file_out->cd(); etaHist[11] = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_11"));
    file_out->cd(); etaHist[12] = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_12"));
    file_out->cd(); etaHist[13] = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_13"));
    file_out->cd(); etaHist[14] = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_14"));
    file_out->cd(); etaHist[15] = new GHistHelTaggedMeson(gDirectory->GetDirectory("eta_15"));
    */


    TraverseEntries(0, eta->GetNEntries()+1);

    for(int j=0; j<=6;j++)
    {
    etaHist[j]->Write();
    }


    return kTRUE;
}

