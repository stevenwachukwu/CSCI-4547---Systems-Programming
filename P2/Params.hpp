//Written by Steve Nwachukwu

#ifndef PARAMS_HPP
#define PARAMS_HPP
#include <string>
#include <getopt.h>

using namespace std;

class Params {
public:
    //Data members of the Params class
    string startDir = ".";
    string outputFile;
    bool verbose = false;
    bool ignoreCase = false;
    string searchWords;

    //Function prototypes of the Params class
    Params(int argc, char* argv[]);
    void print() const;
    static void usage ();
};

#endif
