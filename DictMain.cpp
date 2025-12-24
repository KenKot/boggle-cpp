#include <iostream>
#include <string>
#include <vector>

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


    std::cout << "\ncleaned dict test\n\n";


    //Dict d2("./dictionaries/cleanedDict.txt");  // has words of len 2
    Dict d2("./dictionaries/cleanDictDec.txt"); // removed words w/ less than len of 3
    Board b2(b1input);
    Solver s2(d2);


    answers = s2.getFoundWords(b1);
    for (auto word : answers)
        word.print();
}
