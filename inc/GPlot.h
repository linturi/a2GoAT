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
    GHistHelTaggedMeson*  etaHist;
    GHistTagged3Pi0* _3pi0Hist;
    //GHistTaggedEta*  etaHist;
    GHistTaggedEtap* etapHist;
    Int_t bin0_low, bin0_hi,bin1_low, bin1_hi,bin2_low, bin2_hi, bin3_low, bin3_hi, bin4_low, bin4_hi, bin5_low, bin5_hi;
    Int_t bin6_low, bin6_hi,bin7_low, bin7_hi;

protected:

    virtual void    ProcessEvent();

public:
    GPlot();
    virtual ~GPlot();

    virtual Bool_t  Process(const char* input_filename, const char* output_filename = 0);
};





#endif
