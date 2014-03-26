#ifndef __GPlotJames_h__
#define __GPlotJames_h__


#include <TH1D.h>
#include <TH1I.h>

#include "GTreeManager.h"


class  GPlotJames    : public GTreeManager
{
private:
    TH1D*           misMassPrompt[6];
    TH1D*           misMassRand[6];
    TH1D*           misMass[6];
    static  Int_t   cuts[7];

protected:

    virtual void    ProcessEvent();

public:
    GPlotJames();
    virtual ~GPlotJames();

    virtual Bool_t  Process(const char* input_filename, const char* output_filename = 0);
};





#endif
