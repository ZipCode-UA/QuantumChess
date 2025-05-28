/*
    Pawn.h

    Pawn class for QuantumChess Project

    ZipCode
*/

#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece{
public:
    Pawn(SquareColor c, Pos pos);

    std::pair<int, int> getValidMoves() override;

    PieceID getType() const override;
};

#endif
