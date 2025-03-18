/*
    Bishop.h

    Bishop class for QuantumChess Project

    ZipCode
*/

#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop : public Piece{
public:
    Bishop(SquareColor color, Pos pos);
    void getValidMoves() override;
    PieceID getType() const override;
};

#endif
