#include "rook.h"

Rook::Rook(SquareColor color, Pos position) : Piece(color, position) {

}

std::pair<int, int> Rook::getValidMoves(){
    return {3, 0};
}

PieceID Rook::getType() const{
    return rook;
}