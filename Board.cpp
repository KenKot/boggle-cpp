#include <iostream>
#include "Board.h"

// TODO: consider deep copy or not
Board::Board(const std::vector<std::vector<std::string>>& board) {
    this->rows = board.size();
    this->cols = board[0].size();
    this->board = board;
}

// bool Board::isValidMove(int r, int c) {
//     if (r < 0 || r >= rows)
//         return false;
//     if (c < 0 || c > cols)
//         return false;
//
//     return true;
// }

void Board::printBoard() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            std::string &word = board[r][c];

            std::cout << board[r][c] << " ";

            // for good formatting for both 1 and 2 length squares
            if (word.size() == 1)
                std::cout << " ";
        }
        std::cout << "\n";
    }
}

int Board::getRowCount() const {
    return rows;
}

int Board::getColCount() const {
    return rows;
}
