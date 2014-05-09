#ifndef __GPlotEbins_h__
#define __GPlotEbins_h__


#include <TH1D.h>
#include <TH1I.h>
#include <TAxis.h>
#include <TGraphErrors.h>
#include <TCanvas.h>

#include "GTreeManager.h"
#include "GHistTaggedMeson.h"
#include "GHistHelTaggedMeson.h"



class  GPlotEbins    : public GTreeManager
{
private:

    GHistHelTaggedMeson*  pi0Hist[15];



  //==================Eta===============================================================
    GHistHelTaggedMeson*  etaHist;
    GHistHelTaggedMeson*  etaHist0;


protected:

    virtual void    ProcessEvent();

public:
    GPlotEbins();
    virtual ~GPlotEbins();

    virtual Bool_t  Process(const char* input_filename, const char* output_filename = 0);
};





#endif
