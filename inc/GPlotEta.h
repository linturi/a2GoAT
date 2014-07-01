#ifndef __GPlotEta_h__
#define __GPlotEta_h__


#include <TH1D.h>
#include <TH1I.h>
#include <TAxis.h>
#include <TGraphErrors.h>
#include <TCanvas.h>

#include "GTreeManager.h"
#include "GHistTaggedMeson.h"
//#include "GHistHelTaggedMeson.h"



class  GPlotEta    : public GTreeManager
{
private:

    GHistTaggedMeson*  etaHist[6];


protected:

    virtual void    ProcessEvent();

public:
    GPlotEta();
    virtual ~GPlotEta();

    virtual Bool_t  Process(const char* input_filename, const char* output_filename = 0);
};





#endif
