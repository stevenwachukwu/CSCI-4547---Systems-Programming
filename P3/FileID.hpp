//Written by Steve Nwachukwu

#ifndef FILEID_HPP
#define FILEID_HPP
#include "Params.hpp"
#include <vector>
#include <algorithm>

class FileID {
private:
    FileID(const string &Fname, ino_t iNode_Val, const string &path);

    string FileName;
ino_t iNode;
string Pathname;
vector <string> foundedWords;

public:
    //constructor of the FileID
    FileID (const string& Fname, ino_t iNode_Val, string& path);
    void print (ostream& out) const;
    void insertedWord(const string& word);
    [[nodiscard]] bool NoWords() const {return foundedWords.empty();}

};

#endif
