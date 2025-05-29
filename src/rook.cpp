#include "rook.h"
#include <utility>
#include <vector>

Rook::Rook(SquareColor color, Pos position) : Piece(color, position) {

}

std::vector<std::pair<int, int>> Rook::getValidMoves(){
    if(color == White){
        return {{3, 0}};
    }
    return {{-3, 0}};
}

PieceID Rook::getType() const{
    return rook;
}