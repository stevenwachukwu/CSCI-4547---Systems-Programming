//Written by Steve Nwachukwu

#include "Sniff.hpp"
#include <iostream>
#include <sys/stat.h>

using namespace std;

void Sniff::run() {
    string &current = dirName;
    string &path = dirName;
    chdir(current.c_str());
    travel(path, current);

    //For-loop utilized for printing results
    for (const auto& file : foundedFiles) {
        cout << "\nFile: " << file.getPath() << endl;

        vector<string> words = file.gettingWords();
        cout << "The sniff words that were found: ";
        for (const auto& word : words) {
            cout << word << " ";
        }
        cout << endl;
    }
}

void Sniff::travel(const string& pathname, const string& dirName) {
    DIR* dir = opendir(dirName.c_str());
    if (!dir) {
        cerr << "Error: Could not open the directory: " << dirName << endl;
        return;
    }

    struct dirent* FileEntry;
    while ((FileEntry = readdir(dir)) != nullptr) {
        string fileName = FileEntry->d_name;
        if (fileName == "." || fileName == "..") continue;

        struct stat ST;
        string fullPath = pathname + "/" + fileName;
        if (stat(fullPath.c_str(), &ST) == 0) {
            if (S_ISDIR(ST.st_mode)) {
                travel(fullPath, fileName); //making the recursive call
            } else if (S_ISREG(ST.st_mode)) {
                foundedFiles.emplace_back(fileName, ST.st_ino, pathname); //process the file
            }
        }
    }
    closedir(dir);
    chdir("..");
}

