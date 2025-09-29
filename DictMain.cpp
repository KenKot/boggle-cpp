#include <iostream>
#include <string>
// #include <vector>
#include <set>

#include "Dict.h"
#include "FoundWord.h"
#include "Solver.h"
#include "Board.h"

void dfs(int row, int col, Dict::Node* currNode, std::string& currPrefix,
         std::string board[2][3], std::set<FoundWord> &wordsFound, std::vector<std::pair<int, int>> &currPath) {
    // bounds
    if (row < 0 || col < 0) return;
    if (row >= 2 || col >= 3) return; 

    // "*" means cell is visited
    if (board[row][col] == "*") return;

    std::string cellStr = board[row][col];
    Dict::Node* next = currNode;

    for (char ch : cellStr) {
        int idx = ch - 'a';
        if (idx < 0 || idx >= 26) return;
        next = next->letterPointers[idx];
        if (!next) return;  // ex: ensures both "q" and "u" are in path for "qu"
    }
    board[row][col] = "*";  // mark visited

    currPath.emplace_back(row, col);
    currPrefix += cellStr;

    if (next->isWord) {
        // wordsFound.insert(currPrefix);
        wordsFound.insert(FoundWord(currPrefix, next->definition, currPath));
    }

    dfs(row - 1, col, next, currPrefix, board, wordsFound, currPath); 
    dfs(row - 1, col + 1, next, currPrefix, board, wordsFound, currPath); 
    dfs(row, col + 1, next, currPrefix, board, wordsFound, currPath);    
    dfs(row + 1, col + 1, next, currPrefix, board, wordsFound, currPath);
    dfs(row + 1, col, next, currPrefix, board, wordsFound, currPath);   
    dfs(row + 1, col - 1, next, currPrefix, board, wordsFound, currPath);
    dfs(row, col - 1, next, currPrefix, board, wordsFound, currPath);   
    dfs(row - 1, col - 1, next, currPrefix, board, wordsFound, currPath);

    // backtrack
    currPrefix.resize(currPrefix.size() - cellStr.size());
    currPath.pop_back();
    board[row][col] = cellStr; 
}

int main() {
    std::cout << "Main starting" << std::endl;

    Dict d1("./dictionaries/smalldict1.txt");

    std::cout << "word count: " << d1.getWordCount();
    std::cout << "\n\n\n";


    std::string board[2][3];
    board[0][0] = "qu";
    board[0][1] = "a";
    board[0][2] = "t";

    board[1][0] = "x";
    board[1][1] = "c";
    board[1][2] = "k";


    Dict::Node* root = d1.getRoot();
    std::string currPrefix = "";

    std::vector<std::pair<int, int>> currPath;
    // std::set<std::string> wordsFound;
    std::set<FoundWord> wordsFound;

    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; c++) {
            dfs(r, c, root, currPrefix, board, wordsFound, currPath);
        }
    }

    for (auto& word : wordsFound) {
        word.print();
    }

    std::cout << "\n\n\n" << std::endl;




    std::vector<std::vector<std::string>> b1input = {
        {"c", "a", "t"},
        {"th", "e", "n"}
    };
    Board b1(b1input);
    b1.printBoard();





}
