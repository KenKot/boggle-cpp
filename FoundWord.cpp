#include "FoundWord.h"
#include <iostream>

FoundWord::FoundWord(const std::string &word, const std::string &definition, const std::vector<std::pair<int, int>> &path) {
    this->word = word;
    this->definition = definition;
    this->path = path;
}

void FoundWord::print() const {
    std::cout << word << " " << definition;

    for (auto& coord : path)
        std::cout << " (" << coord.first << ", " << coord.second << ") ";

    std::cout << std::endl;

}

bool FoundWord::operator<(const FoundWord& other) const {
    return word < other.word;
}

