//Written by Steve Nwachukwu and tested by Hashim Ali

#include <iostream>
#include "Params.hpp"
#include "Sniff.hpp"
#include "tools.hpp"


int main(int argc, char* argv[]) {
    banner();

    Params params(argc, argv);

    Sniff sniffing (params); //created the sniff object with a parameter

    sniffing.run(); //does the directory traversal and the file sniffing

    bye();
    return 0;

}
