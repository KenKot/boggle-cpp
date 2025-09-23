#include <iostream>
#include <string>
// #include <vector>
#include <set>

#include "Dict.h"

void dfs(int row, int col, Dict::Node* currNode, std::string& currPrefix,
         std::string board[2][3], std::set<std::string>& wordsFound) {
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

    currPrefix += cellStr;

    if (next->isWord) {
        wordsFound.insert(currPrefix);
    }

    dfs(row - 1, col, next, currPrefix, board,
        wordsFound); 
    dfs(row - 1, col + 1, next, currPrefix, board, wordsFound); 
    dfs(row, col + 1, next, currPrefix, board, wordsFound);    
    dfs(row + 1, col + 1, next, currPrefix, board, wordsFound);
    dfs(row + 1, col, next, currPrefix, board, wordsFound);   
    dfs(row + 1, col - 1, next, currPrefix, board, wordsFound);
    dfs(row, col - 1, next, currPrefix, board, wordsFound);   
    dfs(row - 1, col - 1, next, currPrefix, board, wordsFound);

    // backtrack
    currPrefix.resize(currPrefix.size() - cellStr.size());
    board[row][col] = cellStr; 
}

int main() {
    std::cout << "Main starting" << std::endl;

    Dict d1("./dictionaries/smalldict1.txt");

    std::cout << "word count: " << d1.getWordCount();
    std::cout << "\n\n\n";

    std::set<std::string> wordsFound;

    std::string board[2][3];
    board[0][0] = "qu";
    board[0][1] = "a";
    board[0][2] = "t";

    board[1][0] = "x";
    board[1][1] = "c";
    board[1][2] = "k";

    Dict::Node* root = d1.getRoot();
    std::string currPrefix = "";

    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; c++) {
            dfs(r, c, root, currPrefix, board, wordsFound);
        }
    }

    for (auto& word : wordsFound) {
        std::cout << word + " found\n";
    }

    std::cout << "Main ending" << std::endl;
}
