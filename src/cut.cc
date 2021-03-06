#ifndef __CINT__

#include <time.h>
#include <iostream>
#include <fstream>
#include <TSystem.h>

#include "GCut.h"

using namespace std;

/**
 * @brief the main routine
 * @param argc number of parameters
 * @param argv the parameters as strings
 * @return exit code
 */
int main(int argc, char *argv[])
{
    clock_t start, end;
    start = clock();

    gSystem->Load("libPhysics.so");
    gSystem->Load("libHist.so");
    GCut    tree;

    if(argc == 4)
    {
        // Associate 1nd terminal input with the input file ----------------
        Char_t* file_in;
        if(argv[1]) file_in = argv[1];
        else
        {
            cout << "Please provide an input file" << endl;
            return 0;
        }
        // Check that input file exists:
        ifstream ifile(file_in);
        if(!ifile)
        {
            cout << "Input file " << file_in << " could not be found." << endl;
            return 0;
        }

        // Associate 2rd terminal input with the output file ---------------
        Char_t* file_out;
        if(argv[2]) file_out = argv[2];
        else
        {
            cout << "Please provide an output file" << endl;
            return 0;
        }

        // Associate 2rd terminal input with the output file ---------------
        if(argv[3])
        {
            if(strcmp(argv[3], "pi0")==0)
            {
                tree.SetNPi0(1);
                tree.SetNEta(0);
                tree.SetNEtap(0);
            }
            else if(strcmp(argv[3], "eta2g")==0)
            {
                tree.SetNPi0(0);
                tree.SetNEta(1);
                tree.SetNEtap(0);
            }
            else if(strcmp(argv[3], "eta6g")==0)
            {
                tree.SetNPi0(3);
                tree.SetNEta(1);
                tree.SetNEtap(0);
            }
            else if(strcmp(argv[3], "etap2g")==0)
            {
                tree.SetNPi0(0);
                tree.SetNEta(0);
                tree.SetNEtap(1);
            }
            else if(strcmp(argv[3], "etap6g")==0)
            {
                tree.SetNPi0(2);
                tree.SetNEta(1);
                tree.SetNEtap(1);
            }
            else if(strcmp(argv[3], "proton")==0)
            {
                tree.SetNProton(1);
            }
            else if(strcmp(argv[3], "invMass")==0)
            {
                tree.SetPi0InvMassCut(115, 155);
                tree.SetEtaInvMassCut(500, 590);
                tree.SetEtapInvMassCut(900, 1010);
            }
            else if(strcmp(argv[3], "misMass")==0)
            {
                tree.SetMisMassCut(900, 980);
            }
        }
        else
        {
            cout << "Please provide an output file" << endl;
            return 0;
        }

        tree.Process(file_in, file_out);
    }
    else
    {
        cout << "#ERROR: Please provide correct number of arguments!" << endl;
        cout << "cut <input filename> <output filename>" << endl;
    }

    end = clock();
    cout << "Time required for execution: "
    << (double)(end-start)/CLOCKS_PER_SEC
    << " seconds." << "\n\n";

    return 0;
}

#endif
