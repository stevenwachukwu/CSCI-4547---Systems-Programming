//Written by Steve Nwachukwu

#include "FileID.hpp"

FileID::FileID(const string& Fname, ino_t iNode_Val, const string& path)
: FileName(Fname), iNode(iNode_Val), Pathname(path) {
    string fullPath = path + "/" + Fname;
    ifstream file(fullPath); //this is supposed to open the file

    if (!file) {
        cerr << "Error: The file cannot be opened: " << fullPath << endl;
        return;
    }

    string word;
    while (file >> word) {
        insertedWord(word); //stores all the found words
    } //the while loop would read the words one by one
    file.close(); //closes the file after it reads it
}
