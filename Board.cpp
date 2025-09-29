#include <iostream>
#include "Board.h"

Board::Board(const std::vector<std::vector<std::string>>& board) {
    this->rows = board.size();
    this->cols = board[0].size();
    this->board = board;
}

bool Board::isValidMove(int r, int c) {
    if (r < 0 || r >= rows)
        return false;
    if (c < 0 || c > cols)
        return false;

    return true;
}

void Board::printBoard() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            std::cout << board[r][c] << " ";
        }
        std::cout << "\n";
    }
}
