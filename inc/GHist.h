#ifndef __GHist_h__
#define __GHist_h__


#include <TDirectory.h>
#include <TH1D.h>
#include <TH1I.h>

class  GHist
{
public:
    enum    FLAG_TAGGER_WINDOW
    {
        FLAG_TAGGER_WINDOW_PROMPT   = 0,
        FLAG_TAGGER_WINDOW_RAND1    = 1,
        FLAG_TAGGER_WINDOW_RAND2    = 2
    };
private:

protected:
    TDirectory* dir;

    TH1*   prompt;
    TH1*   rand[2];
    TH1*   randAll;
    TH1*   result;

public:
    GHist(TDirectory* _Dir);
    virtual ~GHist()    = 0;

            void    Add(const GHist *hist, const Double_t scale);
            void    Write(const Double_t RandPromptFactor = 1);
};






class  GHistD   : public GHist
{
private:

protected:

public:
    GHistD(TDirectory* _Dir, const TString& name, const TString& title, const Int_t nBins, const Double_t min, const Double_t max);
    virtual ~GHistD();

    inline  void    Fill(const FLAG_TAGGER_WINDOW taggerWindow, const Double_t value);
};






class  GHistI   : public GHist
{
private:

protected:

public:
    GHistI(TDirectory* _Dir, const TString& name, const TString& title, const Int_t nBins, const Int_t min, const Int_t max);
    virtual ~GHistI();

    inline  void    Fill(const FLAG_TAGGER_WINDOW taggerWindow, const Int_t value);
};






void    GHistD::Fill(const FLAG_TAGGER_WINDOW taggerWindow, const Double_t value)
{
    switch(taggerWindow)
    {
    case FLAG_TAGGER_WINDOW_PROMPT:
        prompt->Fill(value);
        break;
    case FLAG_TAGGER_WINDOW_RAND1:
        GHist::rand[0]->Fill(value);
        break;
    case FLAG_TAGGER_WINDOW_RAND2:
        rand[1]->Fill(value);
        break;
    }
}

void    GHistI::Fill(const FLAG_TAGGER_WINDOW taggerWindow, const Int_t value)
{
    switch(taggerWindow)
    {
    case FLAG_TAGGER_WINDOW_PROMPT:
        prompt->Fill(value);
        break;
    case FLAG_TAGGER_WINDOW_RAND1:
        rand[0]->Fill(value);
        break;
    case FLAG_TAGGER_WINDOW_RAND2:
        rand[1]->Fill(value);
        break;
    }
}




#endif
