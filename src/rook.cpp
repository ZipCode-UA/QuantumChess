#include "rook.h"

Rook::Rook(SquareColor color, Pos position) : Piece(color, position) {

}

std::pair<int, int> Rook::getValidMoves(){

}

PieceID Rook::getType() const{
    return rook;
}