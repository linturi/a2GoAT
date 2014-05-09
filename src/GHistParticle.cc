#include "GHistParticle.h"



GHistParticle::GHistParticle(TDirectory* _Dir)  :
    dir(_Dir)
{
    dir->cd();
    Px  = new TH1D("Px", "Px", 1000, -500, 2000);
    Py  = new TH1D("Py", "Py", 1000, -500, 2000);
    Pz  = new TH1D("Pz", "Pz", 1000, -500, 2000);
    E   = new TH1D("E", "E", 1000, -500, 2000);
    M   = new TH1D("M", "Mass", 1000, -500, 2000);
    Theta   = new TH1D("Theta", "Theta",18, 0, 180);
    CosTheta =new TH1D("CosTheta","CosTheta",18, -1, 1);
    Phi     = new TH1D("Phi", "Phi", 360, -180, 180);
}

GHistParticle::~GHistParticle()
{
    if(Px)  delete  Px;
    if(Py)  delete  Py;
    if(Pz)  delete  Pz;
    if(E)  delete  E;
    if(M)  delete  M;
    if(Theta)  delete  Theta;
    if( CosTheta) delete  CosTheta;
    if(Phi)  delete  Phi;
}

void    GHistParticle::Divide(const GHistParticle *hist)
{
    Px->Divide(hist->Px);
    Py->Divide(hist->Py);
    Pz->Divide(hist->Pz);
    E->Divide(hist->E);
    M->Divide(hist->M);
    Theta->Divide(hist->Theta);
    CosTheta->Divide(hist-> CosTheta);
    Phi->Divide(hist->Phi);
}

void    GHistParticle::Add(const GHistParticle* hist, const Double_t scale)
{
    Px->Add(hist->Px, scale);
    Py->Add(hist->Py, scale);
    Pz->Add(hist->Pz, scale);
    E->Add(hist->E, scale);
    M->Add(hist->M, scale);
    Theta->Add(hist->Theta, scale);
    CosTheta->Add(hist-> CosTheta, scale);
    Phi->Add(hist->Phi, scale);
}

void    GHistParticle::Write()
{
    dir->cd();
    Px->Write();
    Py->Write();
    Pz->Write();
    E->Write();
    M->Write();
    Theta->Write();
    CosTheta->Write();
    Phi->Write();
}

