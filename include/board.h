/*
    Board.h

    Board class for QuantumChess Project

    ZipCode
*/

#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include <memory>
#include <vector>

class Board{
private:
    std::unique_ptr<Piece> pieces[8][8];

public:
    Board();

    void resetBoard();

    std::vector<std::pair<Pos, int>> getPieces();
};

#endif
