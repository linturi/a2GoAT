#ifndef __GPlot_h__
#define __GPlot_h__


#include <TH1D.h>
#include <TH1I.h>
#include <TAxis.h>
#include <TGraphErrors.h>
#include <TCanvas.h>

#include "GTreeManager.h"
#include "GHistTaggedMeson.h"
#include "GHistHelTaggedMeson.h"



class  GPlot    : public GTreeManager
{
private:

    GHistHelTaggedMeson*  pi0Hist;
    GHistHelTaggedMeson*  pi0Hist0;
    GHistHelTaggedMeson*  pi0Hist1;
    GHistHelTaggedMeson*  pi0Hist2;
    GHistHelTaggedMeson*  pi0Hist3;
    GHistHelTaggedMeson*  pi0Hist4;
    GHistHelTaggedMeson*  pi0Hist5;
    GHistHelTaggedMeson*  pi0Hist6;
    GHistHelTaggedMeson*  pi0Hist7;
    GHistHelTaggedMeson*  pi0Hist8;
    GHistHelTaggedMeson*  pi0Hist9;
    GHistHelTaggedMeson*  pi0Hist10;
    GHistHelTaggedMeson*  pi0Hist11;
    //==================Eta===============================================================
    GHistHelTaggedMeson*  etaHist;
    GHistHelTaggedMeson*  etaHist0;
    GHistHelTaggedMeson*  etaHist1;
    GHistHelTaggedMeson*  etaHist2;
    GHistHelTaggedMeson*  etaHist3;
    GHistHelTaggedMeson*  etaHist4;
    GHistHelTaggedMeson*  etaHist5;
    GHistHelTaggedMeson*  etaHist6;
    GHistHelTaggedMeson*  etaHist7;
    GHistHelTaggedMeson*  etaHist8;
    GHistHelTaggedMeson*  etaHist9;
    GHistHelTaggedMeson*  etaHist10;
    GHistHelTaggedMeson*  etaHist11;

    //GHistTagged3Pi0* _3pi0Hist;
    //GHistTaggedEtap* etapHist;
   // GHistTaggedEta*  etaHist;

    Int_t bin0_low, bin0_hi,bin1_low, bin1_hi,bin2_low, bin2_hi, bin3_low, bin3_hi, bin4_low, bin4_hi, bin5_low, bin5_hi;
    Int_t bin6_low, bin6_hi,bin7_low, bin7_hi;
    Int_t bin8_low, bin8_hi,bin9_low,  bin9_hi,bin10_low, bin10_hi, bin11_low,bin11_hi;
    //==================Eta============================
    Int_t Ebin0_low, Ebin0_hi,Ebin1_low, Ebin1_hi,Ebin2_low, Ebin2_hi, Ebin3_low, Ebin3_hi, Ebin4_low, Ebin4_hi, Ebin5_low, Ebin5_hi;
    Int_t Ebin6_low, Ebin6_hi, Ebin7_low, Ebin7_hi;
    Int_t Ebin8_low, Ebin8_hi, Ebin9_low, Ebin9_hi, Ebin10_low, Ebin10_hi, Ebin11_low, Ebin11_hi;

protected:

    virtual void    ProcessEvent();

public:
    GPlot();
    virtual ~GPlot();

    virtual Bool_t  Process(const char* input_filename, const char* output_filename = 0);
};





#endif
