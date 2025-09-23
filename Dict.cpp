#include "Dict.h"

#include <stdexcept>

// #include <iostream>
// #include <iostream>

Dict::Dict(const std::string& filename) {
    root = new Node();

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
        addWord(word);
    }

    inputFile.close();
}

void Dict::addWord(const std::string& word) {
    Node* curr = root;

    for (int i = 0; i < word.size(); i++) {
        int nodeIndex = int(word[i]) - a_CHAR_CODE;

        if (nodeIndex < 0 || nodeIndex > 25) {
            throw std::runtime_error("Letter index not within 0-25");
        }

        if (curr->letterPointers[nodeIndex] == nullptr) {
            Node* newNode = new Node();
            curr->letterPointers[nodeIndex] = newNode;
            curr = newNode;
        } else {
            curr = curr->letterPointers[nodeIndex];
        }

        if (i == word.size() - 1) {
            curr->isWord = true;
            curr->definition = word + "'s def goes here";
            wordCount++;
        }
    }
}

// go back to use ENUM
// -1 = dead
// 0 = prefix
// 1 = word
// int Dict::CheckWord(const std::string& word) {
//     Node* curr = root;
//
//     for (int i = 0; i < word.size(); i++) {
//         int nodeIndex = int(word[i] - a_CHAR_CODE);
//
//         if (nodeIndex < 0 || nodeIndex > 25) {
//             throw std::runtime_error("Letter index not within 0-25");
//         }
//
//         if (curr->letterPointers[nodeIndex] == nullptr) {
//             return -1;
//         }
//
//         curr = curr->letterPointers[nodeIndex];
//     }
//     return curr->isWord ? 1 : 0;
// }

int Dict::getWordCount() { return wordCount; }
Dict::Node* Dict::getRoot() { return root; }
