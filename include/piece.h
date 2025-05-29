/*
    Piece.h

    Piece class for QuantumChess Project

    ZipCode
*/

#ifndef PIECE_H
#define PIECE_H

#include "types.h"
#include <utility>
#include <vector>

class Piece{
protected:
    // Assuming this is the piece's color
    SquareColor color;
    Pos pos;
public:
    Piece(SquareColor color, Pos pos);

    Pos getPosition() const;

    SquareColor getColor() const;

    virtual std::pair<int, int> getValidMoves() = 0;

    virtual PieceID getType() const = 0;

    void setPosition(Pos newPos);
};

#endif
