//Written by Steve Nwachukwu

#include "FileID.hpp"

FileID::FileID(const string& Fname, ino_t iNode_Val, const string& path)
: FileName(Fname), iNode(iNode_Val), Pathname(path) {}

void FileID::print(ostream& out) const {
    out << iNode << "\t" << Pathname << "/" << FileName << endl;
} //print function showing the iNode number and the path

void FileID::insertedWord(const string& word) {
    if ( find(foundedWords.begin(), foundedWords.end(), word) == foundedWords.end()) {
        foundedWords.push_back(word); //stores the new word in the vector
    }
}
