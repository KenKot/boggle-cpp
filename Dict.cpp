#include "Dict.h"

// #include <iostream>
// #include <iostream>

Dict::Dict(const std::string& filename) {
    wordCount = 0;
    std::string stringa = "from constructor";
    std::cout << stringa;

    loadDictFile(filename);
}

void Dict::loadDictFile(const std::string& filename) {
    std::ifstream inputFile;
    inputFile.open(filename);

    if (!inputFile) {
        std::cerr << "Unable to load file";
        return;
    }

    std::string word;

    while (inputFile >> word) {
        std::cout << word << std::endl;
    }

    inputFile.close();
}

int Dict::getWordCount() { return wordCount; }
