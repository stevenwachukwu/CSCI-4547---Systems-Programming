//Written by Steve Nwachukwu and tested by Hashim Ali

#include <iostream>
#include "Params.hpp"

using namespace std;

int main(int argc, char* argv[]) {
Params params(argc, argv);
params.print(); //Utilized Params' print function to show the parsed options
return 0;
}
