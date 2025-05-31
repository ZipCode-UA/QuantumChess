/*
    Knight.h

    Knight class for QuantumChess Project

    ZipCode
*/

#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include <utility>
#include <vector>

class Knight : public Piece{
public:
    Knight(SquareColor c, Pos pos);

    std::vector<std::pair<int, int>> getValidMoves() override;

    PieceID getType() const override;
};

#endif
