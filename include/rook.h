/*
    Rook.h

    Rook class for QuantumChess Project

    ZipCode
*/

#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook : public Piece {
public:
    Rook(SquareColor color, Pos pos);

    void getValidMoves() override;

    PieceID getType() const override;
};

#endif
