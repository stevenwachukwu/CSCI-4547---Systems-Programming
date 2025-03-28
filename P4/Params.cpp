//Written by Steve Nwachukwu

#include "Params.hpp"

Params::Params(int argc, char* argv[]) {
    struct option longOptions [] {
            {"verbose", no_argument, nullptr, 'v'},
            {"ignore-case", no_argument, nullptr, 'i'},
            {"output", required_argument, nullptr, 'o'},
            {"dir", required_argument, nullptr, 'd'},
            {"help", no_argument, nullptr, 'h'},
            {nullptr, 0, nullptr, 0}
    };

    int opt;
    while ((opt = getopt_long(argc, argv, "vio:d:h", longOptions, nullptr)) != -1) {
        switch (opt) {
            case 'v':
                verbose = true;
                break;
            case 'i':
                ignoreCase = true;
                break;
            case 'o':
                outputFile = optarg;
                break;
            case 'd':
                startDir = optarg;
                break;
            case 'h':
                usage();
                exit(0);
            default:
                usage();
                exit(1);
        }
    }

    if (optind < argc){
        searchWords = argv[optind];
    }

    // If the user did not specify a directory, default to "."
    if (startDir.empty()) {
        startDir = ".";
    }
}

void Params::print () const {
    cout << "Starting at: " << startDir << endl;
    cout << "The output file name: " << outputFile << endl;
    cout << "Verbose?: " << (verbose ? "Yes" : "No") << endl;
    cout << "Ignore case?: " << (ignoreCase ? "Yes" : "No") << endl;
    cout << "The search words: " << searchWords << endl;
}

void Params::usage() {
    cout << "Usage: Sniff [options] \"search words\"\n"
         << "Search for the words in the files within a directory. \n\n"
         << "Options:\n"
         << " -v, --verbose       Enables verbose mode\n"
         << " -i, --ignore-case   Case-insensitive search\n"
         << " -o, --output FILE   Writing output to FILE\n"
         << " -d, --dir DIR       Starts to search in a specific directory\n"
         << " -h, --help          Shows the help message you see\n";
}
