/*
    Bishop.h

    Bishop class for QuantumChess Project

    ZipCode
*/

#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include <utility>
#include <vector>

class Bishop : public Piece{
public:
    Bishop(SquareColor color, Pos pos);

    std::pair<int, int> getValidMoves() override;

    PieceID getType() const override;
};

#endif
