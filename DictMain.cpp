#include <iostream>
#include <string>
#include <vector>
#include <set>

#include "Dict.h"
#include "FoundWord.h"
#include "Solver.h"
#include "Board.h"


int main() {
    Dict d1("./dictionaries/smalldict1.txt");

    std::vector<std::vector<std::string>> b1input = {
        {"qu", "a", "t"},
        {"x", "c", "k"}
    };

    Board b1(b1input);
    b1.printBoard();

    Solver s1(d1);

    std::set<FoundWord> answers = s1.getFoundWords(b1);
    for (auto word : answers)
        word.print();


}
