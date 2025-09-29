#ifndef SOLVER_H
#define SOLVER_H

#include "Board.h"
#include "FoundWord.h"

class Solver {
public:
    Solver(Dict& d);
    std::set<FoundWord> getFoundWords(const Board &board);


private:
    Dict& dict;
    // up, up-right, right, down-right, down, down-left, left, up-left
    static const std::pair<int, int> moves[8] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {0, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };



};

#endif
