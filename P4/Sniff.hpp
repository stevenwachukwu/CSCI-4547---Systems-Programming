//Written by Steve Nwachukwu

#ifndef SNIFF_HPP
#define SNIFF_HPP
#include "Params.hpp"
#include "FileID.hpp"
#include <dirent.h>

class Sniff {
private:
    Params params;
    string dirName;
    string dirPath;
    vector <string> words;
    vector <FileID> foundedFiles;
    struct dirent* curEntry;

public:
    Sniff(const Params& p);
    //void oneDir();
    //FileID oneFile(const string& Fname, ino_t iNode_Val);
    void run();
    void travel(const string& pathname, const string& dirname);

};

#endif
