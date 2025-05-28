#include "knight.h"

Knight::Knight(SquareColor color, Pos position) : Piece(color, position) {

}

std::pair<int, int> Knight::getValidMoves(){
    return {2, 1};
}

PieceID Knight::getType() const{
    return knight;
}
