/*
    King.h

    King class for QuantumChess Project

    ZipCode
*/

#ifndef KING_H
#define KING_H

#include "piece.h"
#include <utility>
#include <vector>

class King : public Piece{
public:
    King(SquareColor c, Pos pos);

    std::vector<Pos> getValidMoves() override;

    PieceID getType() const override;
};

#endif
