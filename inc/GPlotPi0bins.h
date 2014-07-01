#ifndef __GPlotPi0bins_h__
#define __GPlotPi0bins_h__


#include <TH1D.h>
#include <TH1I.h>
#include <TAxis.h>
#include <TGraphErrors.h>
#include <TCanvas.h>

#include "GTreeManager.h"
#include "GHistTaggedMeson.h"
#include "GHistHelTaggedMeson.h"



class  GPlotPi0bins    : public GTreeManager
{
private:

    GHistHelTaggedMeson*  pi0Hist[15];



  //==================Eta===============================================================
    GHistHelTaggedMeson*  etaHist;
    GHistHelTaggedMeson*  etaHist0;


protected:

    virtual void    ProcessEvent();

public:
    GPlotPi0bins();
    virtual ~GPlotPi0bins();

    virtual Bool_t  Process(const char* input_filename, const char* output_filename = 0);
};





#endif
