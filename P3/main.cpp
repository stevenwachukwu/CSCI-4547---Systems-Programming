//Written by Steve Nwachukwu and tested by Hashim Ali

#include <iostream>
#include "Params.hpp"
#include "Sniff.hpp"
#include "tools.hpp"


int main(int argc, char* argv[]) {
banner();

Params params(argc, argv);

if (params.verbose) {
    params.print();
} //this would do the verbose printing to debug issues

Sniff sniffing (params);

if (chdir(params.startDir.c_str()) != 0) {
    cerr << "Error: Couldn't change the directory to " << params.startDir << endl;
    bye();
    return 1;
}

sniffing.oneDir();

bye();
return 0;

}
