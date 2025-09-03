#ifndef DICT_H
#define DICT_H

// #include <string.h>
#include <fstream>
#include <iostream>
#include <string>

#define CHAR_LEN 26

class Dict {
   public:
    Dict(const std::string&);
    int getWordCount();

   private:
    int wordCount = 0;
    void loadDictFile(const std::string&);

    class Node {
       public:
        bool isWord = false;
        std::string definition = "definition will go here";
        Node* letterPointers[CHAR_LEN];

        Node() {
            for (int i = 0; i < CHAR_LEN; i++) {
                letterPointers[i] = nullptr;
            }
        }
    };
};

#endif
