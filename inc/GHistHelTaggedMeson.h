#ifndef __GHistHelTaggedMeson_h__
#define __GHistHelTaggedMeson_h__


#include "GHistTaggedMeson.h"



class  GHistHelTaggedMeson
{
private:
    TDirectory*     dir;
    Bool_t         IsReversed;

    GHistTaggedMeson*    hel0;
    GHistTaggedMeson*    hel1;
    GHistTaggedMeson*    helAdd;
    GHistTaggedMeson*    helSub;
    GHistTaggedMeson*    helNorm;

protected:

public:
    GHistHelTaggedMeson(TDirectory* _Dir);
    virtual ~GHistHelTaggedMeson();

            //void    Add(const GHistHelTaggedMeson *hist, const Double_t scale);
    inline  void    FillPromptTagger(const Int_t helicity, const TLorentzVector& mis, const Double_t _TaggerTime, const Double_t _TaggerEnergy, const Int_t _TaggerChannel);
    inline  void    FillRandTagger(const Int_t helicity, const TLorentzVector& mis, const Double_t _TaggerTime, const Double_t _TaggerEnergy, const Int_t _TaggerChannel);
    inline  void    FillPromptMeson(const Int_t helicity, const TLorentzVector& vec);
    inline  void    FillRandMeson(const Int_t helicity, const TLorentzVector& vec);
    inline  void    FillPromptPhoton(const Int_t helicity, const TLorentzVector& vec0, const TLorentzVector& vec1);
    inline  void    FillRandPhoton(const Int_t helicity, const TLorentzVector& vec0, const TLorentzVector& vec1);
    virtual void    Write();

};

void    GHistHelTaggedMeson::FillPromptTagger(const Int_t helicity, const TLorentzVector& mis, const Double_t _TaggerTime, const Double_t _TaggerEnergy, const Int_t _TaggerChannel)
{
    if(IsReversed==kFALSE)
    {
        if(helicity == 0)
            hel0->FillPromptTagger(mis, _TaggerTime, _TaggerEnergy, _TaggerChannel);

        if(helicity == 1)
            hel1->FillPromptTagger(mis, _TaggerTime, _TaggerEnergy, _TaggerChannel);
    }
    else if(IsReversed==kTRUE)
    {
        if(helicity == 0)
            hel1->FillPromptTagger(mis, _TaggerTime, _TaggerEnergy, _TaggerChannel);

        if(helicity == 1)
            hel0->FillPromptTagger(mis, _TaggerTime, _TaggerEnergy, _TaggerChannel);   // some inclusion for taking care of change of helicity
    }
}
void    GHistHelTaggedMeson::FillRandTagger(const Int_t helicity, const TLorentzVector& mis, const Double_t _TaggerTime, const Double_t _TaggerEnergy, const Int_t _TaggerChannel)
{
    if(IsReversed==kFALSE)
    {
        if(helicity == 0)
            hel0->FillRandTagger(mis, _TaggerTime, _TaggerEnergy, _TaggerChannel);
        if(helicity == 1)
            hel1->FillRandTagger(mis, _TaggerTime, _TaggerEnergy, _TaggerChannel);
    }
    else if(IsReversed==kTRUE)
    {
        if(helicity == 0)
            hel1->FillRandTagger(mis, _TaggerTime, _TaggerEnergy, _TaggerChannel);
        if(helicity == 1)
            hel0->FillRandTagger(mis, _TaggerTime, _TaggerEnergy, _TaggerChannel);   // some inclusion for taking care of change of helicity
    }
}

void    GHistHelTaggedMeson::FillPromptMeson(const Int_t helicity, const TLorentzVector& vec)
{
    if(IsReversed==kFALSE)
    {
    if(helicity == 0)
        hel0->FillPromptMeson(vec);
    if(helicity == 1)
        hel1->FillPromptMeson(vec);
    }
    else if(IsReversed==kTRUE)
    {
        if(helicity == 0)
            hel1->FillPromptMeson(vec);
        if(helicity == 1)
           hel0->FillPromptMeson(vec);
    }


}
void    GHistHelTaggedMeson::FillRandMeson(const Int_t helicity, const TLorentzVector& vec)
{
    if(IsReversed==kFALSE)
    {
    if(helicity == 0)
        hel0->FillRandMeson(vec);
    if(helicity == 1)
        hel1->FillRandMeson(vec);
    }
    else if(IsReversed==kTRUE)
    {
        if(helicity == 0)
            hel1->FillRandMeson(vec);
       if(helicity == 1)
            hel0->FillRandMeson(vec);
   }
}

void    GHistHelTaggedMeson::FillPromptPhoton(const Int_t helicity, const TLorentzVector& vec0, const TLorentzVector& vec1)
{
    if(IsReversed==kFALSE)
    {
    if(helicity == 0)
        hel0->FillPromptPhoton(vec0, vec1);
    if(helicity == 1)
        hel1->FillPromptPhoton(vec0, vec1);
    }
    else if (IsReversed==kTRUE)
    {
        if(helicity == 0)
            hel1->FillPromptPhoton(vec0, vec1);
        if(helicity == 1)
           hel0->FillPromptPhoton(vec0, vec1);
    }
}
void    GHistHelTaggedMeson::FillRandPhoton(const Int_t helicity, const TLorentzVector& vec0, const TLorentzVector& vec1)
{
    if(IsReversed==kFALSE)
    {
    if(helicity == 0)
        hel0->FillRandPhoton(vec0, vec1);
    if(helicity == 1)
        hel1->FillRandPhoton(vec0, vec1);
    }
    else if (IsReversed==kTRUE)
    {
        if(helicity == 0)
            hel1->FillRandPhoton(vec0, vec1);
        if(helicity == 1)
            hel0->FillRandPhoton(vec0, vec1);
    }
}
#endif
