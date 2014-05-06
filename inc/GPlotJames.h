#ifndef __GPlotJames_h__
#define __GPlotJames_h__


#include <TH1D.h>
#include <TH1I.h>
#include <TAxis.h>
#include <TGraphErrors.h>
#include <TCanvas.h>

#include "GTreeManager.h"
#include "GHistTaggedMeson.h"
//#include "GHistHelTaggedMeson.h"



class  GPlotJames    : public GTreeManager
{
private:

    GHistTaggedMeson*  pi0Hist[41];



  //==================Eta===============================================================
    GHistTaggedMeson*  etaHist;
    GHistTaggedMeson*  etaHist0;


protected:

    virtual void    ProcessEvent();

public:
    GPlotJames();
    virtual ~GPlotJames();

    virtual Bool_t  Process(const char* input_filename, const char* output_filename = 0);
};





#endif
