/*
    Knight.h

    Knight class for QuantumChess Project

    ZipCode
*/

#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight : public Piece{
public:
    Knight(SquareColor c, Pos pos);
    void getValidMoves() override;

    PieceID getType() const override;
};

#endif
