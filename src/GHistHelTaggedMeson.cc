#include "GHistHelTaggedMeson.h"




GHistHelTaggedMeson::GHistHelTaggedMeson(TDirectory* _Dir):
    dir(_Dir),
    IsReversed(kFALSE)
{
    dir->cd();
    gDirectory->mkdir("hel_0");
    dir->cd();
    gDirectory->mkdir("hel_1");
    dir->cd();
    gDirectory->mkdir("add");
    dir->cd();
    gDirectory->mkdir("substract");
    dir->cd();
    gDirectory->mkdir("normalised");
    dir->cd();
    hel0    = new GHistTaggedMeson(gDirectory->GetDirectory("hel_0"));
    dir->cd();
    hel1    = new GHistTaggedMeson(gDirectory->GetDirectory("hel_1"));
    dir->cd();
    helAdd  = new GHistTaggedMeson(gDirectory->GetDirectory("add"));
    dir->cd();
    helSub  = new GHistTaggedMeson(gDirectory->GetDirectory("substract"));
    dir->cd();
    helNorm = new GHistTaggedMeson(gDirectory->GetDirectory("normalised"));
}

GHistHelTaggedMeson::~GHistHelTaggedMeson()
{
    if(hel0)  delete  hel0;
    if(hel1)  delete  hel1;
    if(hel0)  delete  hel0;
    if(hel0)  delete  hel0;
}


void    GHistHelTaggedMeson::Write()
{
    hel0->Write();
    hel1->Write();
    dir->cd();
    helAdd->Add(hel0, 1);
    helAdd->Add(hel1, 1);
    helAdd->Write();
    dir->cd();
    helSub->Add(hel0, 1);
    helSub->Add(hel1, -1);
    helSub->Write();
    dir->cd();
    helNorm->Add(helSub, 1);
    helNorm->Divide(helAdd);
    helNorm->Write();
    dir->cd();
}


/*void    GHistHelTaggedMeson::Add(const GHistHelTaggedMeson* hist, const Double_t scale)
{
    hel0->Add(hist->hel0, scale);
    hel1->Add(hist->hel1, scale);
    helAdd->Add(hist->helAdd, scale);
    helSub->Add(hist->helSub, scale);
    helNorm->Add(hist->helNorm, scale);
}*/






