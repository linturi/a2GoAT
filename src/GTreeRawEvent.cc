#include "GTreeRawEvent.h"

GTreeRawEvent::GTreeRawEvent()    :
    GTree(TString("treeRawEvent")),
    nParticles(0)
{

}

GTreeRawEvent::~GTreeRawEvent()
{

}

void    GTreeRawEvent::SetBranchAdresses()
{
    tree_in->SetBranchAddress("nParticles",&nParticles);
    tree_in->SetBranchAddress("Ek",  Ek);
    tree_in->SetBranchAddress("Theta", Theta);
    tree_in->SetBranchAddress("Phi",  Phi);
    tree_in->SetBranchAddress("time", time);
    tree_in->SetBranchAddress("clusterSize", clusterSize);
    tree_in->SetBranchAddress("Apparatus", Apparatus);
    tree_in->SetBranchAddress("d_E", d_E);
    tree_in->SetBranchAddress("WC0_E", WC0_E);
    tree_in->SetBranchAddress("WC1_E", WC1_E);
    tree_in->SetBranchAddress("WC_Vertex_X", WC_Vertex_X);
    tree_in->SetBranchAddress("WC_Vertex_Y", WC_Vertex_Y);
    tree_in->SetBranchAddress("WC_Vertex_Z", WC_Vertex_Z);
}

void    GTreeRawEvent::SetBranches()
{
    tree_out->Branch("nParticles",&nParticles,"nParticles/I");
    tree_out->Branch("Ek",  Ek,  "Ek[nParticles]/D");
    tree_out->Branch("Theta",  Theta,  "Theta[nParticles]/D");
    tree_out->Branch("Phi",  Phi,  "Phi[nParticles]/D");
    tree_out->Branch("time", time, "time[nParticles]/D");
    tree_out->Branch("clusterSize", clusterSize, "clusterSize[nParticles]/b");
    tree_out->Branch("Apparatus", Apparatus, "Apparatus[nParticles]/b");
    tree_out->Branch("d_E", d_E, "d_E[nParticles]/D");
    tree_out->Branch("WC0_E", WC0_E, "WC0_E[nParticles]/D");
    tree_out->Branch("WC1_E", WC1_E, "WC1_E[nParticles]/D");
    tree_out->Branch("WC_Vertex_X", WC_Vertex_X, "WC_Vertex_X[nParticles]/D");
    tree_out->Branch("WC_Vertex_Y", WC_Vertex_Y, "WC_Vertex_Y[nParticles]/D");
    tree_out->Branch("WC_Vertex_Z", WC_Vertex_Z, "WC_Vertex_Z[nParticles]/D");
}

void    GTreeRawEvent::Print(const Bool_t All) const
{
    std::cout << "GTreeParticle: nParticles->" << nParticles << std::endl;
}
