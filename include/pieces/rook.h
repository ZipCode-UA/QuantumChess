/*
    Rook.h

    Rook class for QuantumChess Project

    ZipCode
*/

#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include <utility>
#include <vector>

class Rook : public Piece {
public:
    Rook(SquareColor color, Pos pos, Board *board);

    std::vector<Pos> getValidMoves() override;

    PieceID getType() const override;
};

#endif
