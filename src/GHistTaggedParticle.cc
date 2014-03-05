#include "GHistTaggedParticle.h"


GHistTaggedParticleWindow::GHistTaggedParticleWindow(TDirectory* _Dir) :
    dir(_Dir)
{
    dir->cd();
    taggerTime  = new TH1D("TaggerTimeOR", "TaggerTimeOR", 200, -50, 50);
    taggerE     = new TH1D("TaggerEnergy", "TaggerEnergy", 1500, 0, 1650);
    taggerCh    = new TH1I("TaggerChannel", "TaggerChannel", 352, 0, 351);
    dir->mkdir("particle");
    dir->cd();
    dir->mkdir("missing");
    dir->cd();
    particle    = new GHistParticle(gDirectory->GetDirectory("particle"));
    dir->cd();
    missing    = new GHistParticle(gDirectory->GetDirectory("missing"));
    dir->cd();
}

GHistTaggedParticleWindow::~GHistTaggedParticleWindow()
{
    if(taggerTime)  delete  taggerTime;
    if(taggerE)  delete  taggerE;
    if(taggerCh)  delete  taggerCh;
    if(particle)  delete  particle;
    if(missing)  delete  missing;
}

void    GHistTaggedParticleWindow::Divide(const GHistTaggedParticleWindow *hist)
{
    taggerTime->Divide(hist->taggerTime);
    taggerE->Divide(hist->taggerE);
    taggerCh->Divide(hist->taggerCh);
    particle->Divide(hist->particle);
    missing->Divide(hist->missing);
}

void    GHistTaggedParticleWindow::Add(const GHistTaggedParticleWindow* hist, const Double_t scale)
{
    taggerTime->Add(hist->taggerTime, scale);
    taggerE->Add(hist->taggerE, scale);
    taggerCh->Add(hist->taggerCh, scale);
    particle->Add(hist->particle, scale);
    missing->Add(hist->missing, scale);
}

void    GHistTaggedParticleWindow::Write()
{
    dir->cd();
    taggerTime->Write();
    taggerE->Write();
    taggerCh->Write();
    particle->Write();
    missing->Write();
}








GHistTaggedParticle::GHistTaggedParticle(TDirectory *_Dir):
    dir(_Dir)
{
    dir->cd();
    dir->mkdir("prompt");
    dir->cd();
    dir->mkdir("rand");
    dir->cd();
    diff      = new GHistTaggedParticleWindow(gDirectory);
    prompt    = new GHistTaggedParticleWindow(gDirectory->GetDirectory("prompt"));
    dir->cd();
    rand    = new GHistTaggedParticleWindow(gDirectory->GetDirectory("rand"));
    dir->cd();
}

GHistTaggedParticle::~GHistTaggedParticle()
{
    if(diff)    delete  diff;
    if(prompt)  delete  prompt;
    if(rand)    delete  rand;
}

void    GHistTaggedParticle::Divide(const GHistTaggedParticle *hist)
{
    prompt->Divide(hist->prompt);
    rand->Divide(hist->rand);
    diff->Divide(hist->diff);
}

void    GHistTaggedParticle::Add(const GHistTaggedParticle* hist, const Double_t scale)
{
    prompt->Add(hist->prompt, scale);
    rand->Add(hist->rand, scale);
    diff->Add(hist->diff, scale);
}

void    GHistTaggedParticle::Write()
{
    prompt->Write();
    rand->Write();
    dir->cd();
    diff->Add(prompt, 1);
    diff->Add(rand, -0.5);
    diff->Write();
    dir->cd();
}
