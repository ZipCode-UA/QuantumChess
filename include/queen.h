/*
    Queen.h

    Queen class for QuantumChess Project

    ZipCode
*/

#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece{
public:
    Queen(SquareColor c, Pos pos);
    void getValidMoves() override;
    PieceID getType() const override;
};

#endif
