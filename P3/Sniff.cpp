//Written by Steve Nwachukwu

#include "Sniff.hpp"
#include <sstream> //library to deal with the strings
#include <sys/stat.h> //library to help with some of the variables

Sniff::Sniff(const Params& p) : params(p), dirName(p.startDir), dirPath(p.startDir) {
    istringstream SS(p.searchWords); //variable for the string stream
    string word;
    while (SS >> word) {
        words.push_back(word);
    } //this while loop would get the characters one by one
}

void Sniff::oneDir() {
    DIR* DP = opendir("."); //this variable's purpose is to find the path
    if (!DP) {
        cerr << "Error: Couldn't open directory!" << endl;
        return;
    }

    cout << "Scanning the directory: " << dirPath << endl;

    //Utilizing two readdir functions to avoid '.' and '..'
    readdir(DP);
    readdir(DP);

    //Implemented a while loop to go through the directory entries
    while ((curEntry = readdir(DP)) != nullptr) {
        string Name = curEntry->d_name;
        if (Name == "." || Name == "..") continue;

        struct stat StatsBuf;
        if (stat(Name.c_str(), &StatsBuf) != 0) {
            cerr << "Couldn't stat: " << Name << endl;
            continue;
        }

        if (S_ISREG(StatsBuf.st_mode)) {
            if (params.verbose) {
                cout << "Processing the file: " << Name << endl;
            }
            FileID file = oneFile(Name, StatsBuf.st_ino);
            if (!file.NoWords()) {
                foundedFiles.push_back(file);
            }
        } else if (S_ISDIR(StatsBuf.st_mode)) {
            if (params.verbose) {
                cout << "Founded the directory: " << Name << endl;
            }
        }

        cout << "Finished processing the directory!" << endl;
        closedir(DP);
    }
}
