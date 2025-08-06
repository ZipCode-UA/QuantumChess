/*
    Queen.h

    Queen class for QuantumChess Project

    ZipCode
*/

#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include <utility>
#include <vector>

class Queen : public Piece{
public:
    Queen(SquareColor c, Pos pos);

    std::vector<Pos> getValidMoves() override;

    PieceID getType() const override;
};

#endif
