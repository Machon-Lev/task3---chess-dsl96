#pragma once

struct ChessSquare {

    int row;   // represents the file of the square (0-7)
    int col;   // represents the rank of the square (0-7)

    ChessSquare(int row = 0, int col = 0) : row(row), col(col) {}

    void operator+=(const ChessSquare& other) {
        col += other.col;
        row += other.row;
    }

    bool operator==(const ChessSquare& other) {
  
        return  col == other.col && row == other.row;
    }
};
