/*
    King.h

    King class for QuantumChess Project

    ZipCode
*/

#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece{
public:
    King(SquareColor c, Pos pos);
    void getValidMoves() override;
    PieceID getType() const override;
};

#endif
