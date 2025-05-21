#include "pawn.h"

Pawn::Pawn(SquareColor color, Pos position) : Piece(color, position) {

}

void Pawn::getValidMoves(){

}

PieceID Pawn::getType() const{
    return pawn;
}
