#ifndef DICT_H
#define DICT_H

// #include <string.h>
#include <fstream>
#include <iostream>
#include <string>

#define CHAR_LEN 26
#define a_CHAR_CODE 97

class Dict {
   public:
    Dict(const std::string&);
    int getWordCount();

   private:
    class Node {
       public:
        bool isWord = false;
        std::string definition = "";
        Node* letterPointers[CHAR_LEN];

        Node() {
            for (int i = 0; i < CHAR_LEN; i++) {
                letterPointers[i] = nullptr;
            }
        }
    };

    int wordCount = 0;
    Node* root = nullptr;

    void loadDictFile(const std::string&);
    void addWord(const std::string&);
};

#endif
