#include "rook.h"

Rook::Rook(SquareColor color, Pos position) : Piece(color, position) {

}

std::pair<int, int> Rook::getValidMoves(){
    if(color == White){
        return {3, 0};
    }
    return {-3, 0};
}

PieceID Rook::getType() const{
    return rook;
}