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
    GHistHelTaggedMeson*  pi0Hist12;
    GHistHelTaggedMeson*  pi0Hist13;
    GHistHelTaggedMeson*  pi0Hist14;
    GHistHelTaggedMeson*  pi0Hist15;
    GHistHelTaggedMeson*  pi0Hist16;
    GHistHelTaggedMeson*  pi0Hist17;
    GHistHelTaggedMeson*  pi0Hist18;
    GHistHelTaggedMeson*  pi0Hist19;
    GHistHelTaggedMeson*  pi0Hist20;
    GHistHelTaggedMeson*  pi0Hist21;
    GHistHelTaggedMeson*  pi0Hist22;
    GHistHelTaggedMeson*  pi0Hist23;
    GHistHelTaggedMeson*  pi0Hist24;
    GHistHelTaggedMeson*  pi0Hist25;
    GHistHelTaggedMeson*  pi0Hist26;
    GHistHelTaggedMeson*  pi0Hist27;
    GHistHelTaggedMeson*  pi0Hist28;
    GHistHelTaggedMeson*  pi0Hist29;
    GHistHelTaggedMeson*  pi0Hist30;
    GHistHelTaggedMeson*  pi0Hist31;
    GHistHelTaggedMeson*  pi0Hist32;
    GHistHelTaggedMeson*  pi0Hist33;
    GHistHelTaggedMeson*  pi0Hist34;
    GHistHelTaggedMeson*  pi0Hist35;
    GHistHelTaggedMeson*  pi0Hist36;
    GHistHelTaggedMeson*  pi0Hist37;
    GHistHelTaggedMeson*  pi0Hist38;
    GHistHelTaggedMeson*  pi0Hist39;
    GHistHelTaggedMeson*  pi0Hist40;
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
    Int_t bin6_low, bin6_hi,bin7_low, bin7_hi,bin8_low, bin8_hi,bin9_low,  bin9_hi,bin10_low, bin10_hi, bin11_low,bin11_hi;
    Int_t bin12_low, bin12_hi,bin13_low, bin13_hi,bin14_low, bin14_hi, bin15_low, bin15_hi, bin16_low, bin16_hi, bin17_low, bin18_hi;
    Int_t bin19_low, bin19_hi,bin20_low, bin20_hi,bin21_low, bin21_hi, bin22_low, bin22_hi, bin23_low, bin23_hi, bin24_low, bin24_hi;
    Int_t bin25_low, bin25_hi,bin26_low, bin26_hi,bin27_low, bin27_hi, bin28_low, bin28_hi, bin29_low, bin29_hi, bin30_low, bin30_hi;
    Int_t bin31_low, bin31_hi,bin32_low, bin32_hi,bin33_low, bin33_hi, bin34_low, bin34_hi, bin35_low, bin35_hi, bin36_low, bin36_hi;
    Int_t bin37_low, bin37_hi,bin38_low, bin38_hi,bin39_low, bin39_hi, bin40_low, bin3_40, bin41_low, bin41_hi, bin42_low, bin42_hi;
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
