#ifndef __GAcquTree_h__
#define __GAcquTree_h__


#include "TTree.h"
#include "TLeaf.h"
#include "TCanvas.h"
#include "TChain.h"
#include "TF1.h"
#include "TGraph.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TLorentzVector.h"
#include "TMath.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TSystem.h"
#include "TSystemDirectory.h"
#include "TSystemFile.h"
#include "TCutG.h"

#include "GTree.h"

#define GAcquTree_MAX_TAGGER	1024
#define GAcquTree_MAX_PARTICLE	128
#define GAcquTree_MAX_HITS		860
#define EAppCB  1
#define EAppTAPS 2


class	GAcquTree    : public GTree
{
private:
    /*TTree*		treeRawEvent;		// Raw particle information (filled each event)
	TTree*		treeTagger;			// Tagger information (filled each event)
	TTree* 		treeTrigger;		// Trigger information (filled each event)
	TTree* 		treeDetectorHits;	// Detector system hit patterns (filled each event)
	TTree*		treeScaler; 		// Scaler read information (filled each scaler read)

    TTree*	treeRawEvent_clone;		// Raw particle information (filled when required)
    TTree*	treeTagger_clone;		// Tagger information (filled when required)
    TTree* 	treeTrigger_clone;		// Trigger information (filled when required)
    TTree* 	treeDetectorHits_clone;	// Detector system hit patterns (filled when required)
    TTree*	treeScaler_clone; 		// Scaler read information (filled when required)*/


    //Particles    
    Int_t		nParticles;
    Double_t*	Ek;
    Double_t* 	Theta;
    Double_t* 	Phi;
   	Double_t*	time;
    UChar_t*    clusterSize;
    
    //Tagger
    Int_t		nTagged;
    Int_t*		tagged_ch;
    Double_t*	tagged_t;
    Double_t*	photonbeam_E;    
    
    //Apparatus
    UChar_t*	Apparatus;
    
    //Charged detector energies
    Double_t*	d_E;
    Double_t*	WC0_E;
    Double_t*	WC1_E;

	//Wire Chamber vertex reconstruction
   	Double_t* 	WC_Vertex_X;
   	Double_t* 	WC_Vertex_Y;
   	Double_t* 	WC_Vertex_Z;
    
   	//Hits
   	Int_t		nNaI_Hits;
   	Int_t*		NaI_Hits;
   	Int_t		nPID_Hits;
   	Int_t*		PID_Hits;
   	Int_t		nWC_Hits;
   	Int_t*		WC_Hits;
   	Int_t		nBaF2_PbWO4_Hits;
   	Int_t*		BaF2_PbWO4_Hits;
   	Int_t		nVeto_Hits;
   	Int_t*		Veto_Hits;
    
   	//Trigger
   	Double_t 	ESum;
   	Int_t 		Mult;
	
    //Scalers
    Int_t		EventNumber;
    Int_t		EventID;
    UInt_t*		Scaler;
    Int_t		NScaler;

    void 	GetEntryFast();                	// without testing index

    Double_t* 	Mass;

protected:
	
public:
    GAcquTree();
    virtual ~GAcquTree();

    virtual void        CloseAllTrees()                     {}
    virtual Bool_t      InitNewTree()                       {}
    virtual void        WriteNewTree(const char* treefile)  {}
    
    /*Bool_t	OpenTreeRawEvent();
    Bool_t	OpenTreeTagger();		
    Bool_t	OpenTreeTrigger();
    Bool_t	OpenTreeDetectorHits();
    Bool_t	OpenTreeScaler();
    Bool_t	CloseTreeRawEvent();
    Bool_t	CloseTreeTagger();
    Bool_t	CloseTreeTrigger();
    Bool_t	CloseTreeDetectorHits();
    Bool_t	CloseTreeScaler();

    Bool_t	FindValidEvents();
		
    virtual Bool_t	GetEntry();
    virtual Bool_t	GetEntry(const Int_t index);

    virtual void	Reset();
    virtual Bool_t 	FillEvent();
    virtual Bool_t	WriteTrees();
    virtual	void	Print();*/

    virtual Int_t   GetMultiplicity()   const               {return nParticles;}
	
    		Int_t		GetNParticles()             const	{return nParticles;}
    const	Double_t*	GetEk()                      const	{return Ek;}
    		Double_t	GetEk(const Int_t index)		const	{return Ek[index];}    
    		    		
    const	Double_t*	GetTheta()                  	const	{return Theta;}
    		Double_t	GetTheta(const Int_t index)		const	{return Theta[index];}
    const	Double_t*	GetPhi()                  		const	{return Phi;}
    		Double_t	GetPhi(const Int_t index)		const	{return Phi[index];} 
    		
    		Double_t	GetThetaRad(const Int_t index)	const	{return Theta[index] * TMath::DegToRad();}
     		Double_t	GetPhiRad(const Int_t index)	const	{return Theta[index] * TMath::DegToRad();}
    		    
    const	Double_t*	GetTime()                   const	{return time;}
    		Double_t	GetTime(const Int_t index)	const	{return time[index];}
    		
    		UChar_t 	GetClusterSize(const Int_t index) const 	{return clusterSize[index];}
    
    		Int_t		GetNTagged()                    const	{return nTagged;}
    const	Int_t*		GetTagged_ch()               	const	{return tagged_ch;}
    		Int_t		GetTagged_ch(const Int_t index)	const	{return tagged_ch[index];}
    const	Double_t*	GetTagged_t()                   const	{return tagged_t;}
    		Double_t	GetTagged_t(const Int_t index)	const	{return tagged_t[index];}
    const	Double_t*	GetPhotonBeam_E()                   const	{return photonbeam_E;}
    		Double_t	GetPhotonBeam_E(const Int_t index)	const	{return photonbeam_E[index];}
    		    
    const	UChar_t*	GetApparatus()                  const	{return Apparatus;}
    		UChar_t		GetApparatus(const Int_t index)	const	{return Apparatus[index];}

    const	Double_t*	Get_dE()                    const	{return d_E;}
    		Double_t	Get_dE(const Int_t index)	const	{return d_E[index];}
    const	Double_t*	GetWC0_E()                  const	{return WC0_E;}
    		Double_t	GetWC0_E(const Int_t index)	const	{return WC0_E[index];}
    const	Double_t*	GetWC1_E()                  const	{return WC1_E;}
    		Double_t	GetWC1_E(const Int_t index)	const	{return WC1_E[index];}
    
    const	Double_t* 	GetWC_Vertex_X()                    const	{return WC_Vertex_X;}
   			Double_t 	GetWC_Vertex_X(const Int_t index)	const	{return WC_Vertex_X[index];}
    const	Double_t* 	GetWC_Vertex_Y()                    const	{return WC_Vertex_Y;}
    		Double_t 	GetWC_Vertex_Y(const Int_t index)	const	{return WC_Vertex_Y[index];}
    const	Double_t* 	GetWC_Vertex_Z()                    const	{return WC_Vertex_Z;}
    		Double_t 	GetWC_Vertex_Z(const Int_t index)	const	{return WC_Vertex_Z[index];}
    
			Double_t 	GetESum()	const	{return ESum;}
			Int_t	 	GetMult()	const	{return Mult;}	
    
    		Int_t 		GetNScaler()    			const	{return NScaler;}
    		Int_t 		GetEventID()        		const	{return EventID;}
    		Int_t 		GetEventNumber()        	const	{return EventNumber;}
    const	UInt_t*		GetScaler()                 const	{return	Scaler;}
    		UInt_t		GetScaler(const Int_t index)const	{return	Scaler[index];}

    		Int_t		GetNNaI_Hits()              	const	{return nNaI_Hits;}
    const	Int_t*		GetNaI_Hits()           		const	{return NaI_Hits;}
    		Int_t		GetNaI_Hits(const Int_t index)	const	{return NaI_Hits[index];}

    		Int_t		GetNPID_Hits()      			const	{return nPID_Hits;}
    const	Int_t*		GetPID_Hits()               	const	{return PID_Hits;}
    		Int_t		GetPID_Hits(const Int_t index)	const	{return PID_Hits[index];}

    		Int_t		GetNWC_Hits()       			const	{return nWC_Hits;}
    const	Int_t*		GetWC_Hits()                	const	{return WC_Hits;}
    		Int_t		GetWC_Hits(const Int_t index)	const	{return WC_Hits[index];}

    		Int_t		GetNBaF2_PbWO4_Hits()                   const	{return nBaF2_PbWO4_Hits;}
    const	Int_t*		GetBaF2_PbWO4_Hits()                    const	{return BaF2_PbWO4_Hits;}
    		Int_t		GetBaF2_PbWO4_Hits(const Int_t index)	const	{return BaF2_PbWO4_Hits[index];}

			Int_t		GetNVeto_Hits()                 const	{return nVeto_Hits;}
    const	Int_t*		GetVeto_Hits()                  const	{return Veto_Hits;}
            Int_t		GetVeto_Hits(const Int_t index)	const	{return Veto_Hits[index];}

	void 	SetInputMass(Int_t index, Double_t value)	{Mass[index] 	= value;}
			Double_t 	GetInputMass(Int_t index) 	const    {return Mass[index];}
	

    inline  TLorentzVector	GetVector(const Int_t index) const;
    inline  Int_t		GetNCB()	const;
    inline  Int_t		GetNTAPS()	const;
};

TLorentzVector	GAcquTree::GetVector(const Int_t index) const
{
    Double_t th = Theta[index] * TMath::DegToRad();
    Double_t ph = Phi[index]   * TMath::DegToRad();

    Double_t E 	= Ek[index] + Mass[index];
    Double_t P 	= TMath::Sqrt(E*E - Mass[index]*Mass[index]);
    Double_t Px = P* sin(th)*cos(ph);
    Double_t Py = P* sin(th)*sin(ph);
    Double_t Pz = P* cos(th);

    return TLorentzVector(Px, Py, Pz, E);
}

Int_t           GAcquTree::GetNCB()	const
{
    Int_t NCB = 0;
    for(Int_t i = 0; i < nParticles; i++)
    {
        if (Apparatus[i] == EAppCB)
            NCB++;
    }
    return NCB;
}
Int_t           GAcquTree::GetNTAPS()	const
{
    Int_t NTAPS = 0;
    for(Int_t i = 0; i < nParticles; i++)
    {
        if (Apparatus[i] == EAppTAPS)
            NTAPS++;
    }
    return NTAPS;
}


#endif
