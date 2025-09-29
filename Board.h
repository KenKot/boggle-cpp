#ifndef BOARD_H
#define BOARD_h

#include <vector>

class Board {
public:
    Board(const std::vector<std::vector<std::string>>& board);
    bool isValidMove(int r, int c);

    int getRowCount() const;
    int getColCount() const;

    void printBoard();

private:
    int rows;
    int cols;
    std::vector<std::vector<std::string>>& board;



};

#endif
