/*
    Piece.h

    Piece class for QuantumChess Project

    ZipCode
*/

#ifndef PIECE_H
#define PIECE_H

#include "types.h"

class Piece{
protected:
    SquareColor color;
    Pos pos;
public:
    Piece(SquareColor color, Pos pos);

    Pos getPosition() const;

    SquareColor getColor() const;

    virtual void getValidMoves() = 0;

    virtual PieceID getType() const = 0;

};

#endif
