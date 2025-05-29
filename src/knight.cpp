#include "knight.h"

Knight::Knight(SquareColor color, Pos position) : Piece(color, position) {

}

std::pair<int, int> Knight::getValidMoves(){
    if(color == White){
        return {2, 1};
    }
    return {-2, -1};
}

PieceID Knight::getType() const{
    return knight;
}
