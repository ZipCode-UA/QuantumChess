/*
    Pawn.h

    Pawn class for QuantumChess Project

    ZipCode
*/

#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include <utility>
#include <vector>

class Pawn : public Piece{
public:
    Pawn(SquareColor c, Pos pos);

    std::vector<Pos> getValidMoves() override;

    PieceID getType() const override;
};

#endif
