#ifndef __GPlotPi0_h__
#define __GPlotPi0_h__


#include <TH1D.h>
#include <TH1I.h>
#include <TAxis.h>
#include <TGraphErrors.h>
#include <TCanvas.h>

#include "GTreeManager.h"
#include "GHistTaggedMeson.h"
//#include "GHistHelTaggedMeson.h"



class  GPlotPi0    : public GTreeManager
{
private:

    GHistTaggedMeson* pi0Histall[15];



  //==================Eta===============================================================
    GHistTaggedMeson*  etaHist;
    GHistTaggedMeson*  etaHist0;


protected:

    virtual void    ProcessEvent();

public:
    GPlotPi0();
    virtual ~GPlotPi0();

    virtual Bool_t  Process(const char* input_filename, const char* output_filename = 0);
};





#endif
