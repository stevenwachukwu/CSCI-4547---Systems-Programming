//Written by Steve Nwachukwu and tested by Hashim Ali

#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char* argv[]) {
    //Opens the file in append mode
    ofstream myOutput ("P1_Nwachukwu.txt", ios::out | ios::app);
    if (!myOutput) {
        cerr << "Error: The file cannot be opened!" << endl;
        return 1;
    }

    //Printout of the dashed lines as dividers
    cout << "--------------------------------" << endl;
    myOutput << "--------------------------------" << endl;

    //The command-line arguments processing
    for (int i = 0; i < argc; ++i) {
        string Type;

        if (i==0) {
            Type = "Command:"; //First part for the program name
        }
        else if (argv[i][0] == '-') {
            Type = "Switch:"; //Second part for the user's switch case
        }
        else {
            Type = "Argument:"; //Last part for anything that isn't the program name or switch
        }
        cout << Type << " " << argv[i] << endl; //Printout to the console
        myOutput << Type << " " << argv[i] << endl; //Printout to the output file
    }
    myOutput.close(); //closing out the output file
    return 0;
}

