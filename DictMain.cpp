#include <iostream>
#include <string>
#include <vector>

#include "Dict.h"
#include "FoundWord.h"
#include "Solver.h"
#include "Board.h"

#include <emscripten/emscripten.h>

extern "C" {
EMSCRIPTEN_KEEPALIVE
void solveBoard(const char** arr, int rows, int cols) {            // should rows + cols be const?
    static Dict d2("/dictionaries/cleanDictDec.txt"); // removed words w/ less than len of 3
    static Solver s2(d2);
    std::vector<std::vector<std::string>> boardinput;

    for (int i = 0; i < rows; i++) {
        std::vector<std::string> row;
        for (int j = 0; j < cols; j++) {
            int idx = i * cols + j;
            std::string curr = arr[idx];
            row.emplace_back(curr);
        }
        boardinput.push_back(row);
    }

    Board b2(boardinput);

    std::set<FoundWord> answers = s2.getFoundWords(b2);
    for (auto word : answers)
        word.print();
}
}

int main(){
    std::cout << "main fired" << std::flush;
}
