#include "rook.h"

Rook::Rook(SquareColor color, Pos position) : Piece(color, position) {

}

void Rook::getValidMoves(){

}

PieceID Rook::getType() const{
    return rook;
}