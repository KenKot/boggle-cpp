#include <iostream>

#include "Dict.h"

int main() {
    std::cout << "Main starting" << std::endl;

    Dict d1("./dictionaries/smalldict1.txt");

    std::cout << d1.getWordCount();

    std::cout << "Main ending";
}
