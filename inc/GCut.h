#ifndef __GCut_h__
#define __GCut_h__


#include <vector>
#include <fstream>

#include "GRawCut.h"


class  GCut  : public GRawCut
{
private:
    Bool_t  doMultiplicity;
    Int_t   nPi0;
    Int_t   nEta;
    Int_t   nEtap;

    Bool_t      doInvMass;
    Double_t    pi0InvMass[2];
    Double_t    etaInvMass[2];
    Double_t    etapInvMass[2];

    Bool_t      doMisMass;
    Double_t    MisMass[2];


    Bool_t      doESum;
    Double_t    ESum[2];

    Bool_t      DoMultiplicity();
    Bool_t      DoInvMass();
    Bool_t      DoMisMass();
    Bool_t      DoESum();
    
    Int_t           nTagged;
    Int_t           tagged_ch[GTreeTagger_MAX];
    Double_t        tagged_t[GTreeTagger_MAX];
    Double_t        photonbeam_E[GTreeTagger_MAX];
    TLorentzVector  missingVector[GTreeTagger_MAX];

protected:

    virtual void    ProcessEvent();

public:
    GCut();
    virtual ~GCut();

    virtual Bool_t  Process(const char* input_filename, const char* output_filename = 0);

    void    SetNPhoton(const Int_t Multiplicity);
    void    SetNProton(const Int_t Multiplicity);
    void    SetNPi0(const Int_t Multiplicity);
    void    SetNEta(const Int_t Multiplicity);
    void    SetNEtap(const Int_t Multiplicity);
    void    ClearInvMass()          {doInvMass=kFALSE;}
    void    ClearMisMass()          {doMisMass=kFALSE;}
    void    ClearNParticle()        {doMultiplicity=kFALSE;}
    void    SetPi0InvMassCut(const Double_t min, const Double_t max);
    void    SetEtaInvMassCut(const Double_t min, const Double_t max);
    void    SetEtapInvMassCut(const Double_t min, const Double_t max);
    void    SetMisMassCut(const Double_t min, const Double_t max);
    void    SetESumCut(const Double_t min, const Double_t max);

};





#endif
