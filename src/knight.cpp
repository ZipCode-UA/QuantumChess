#include "knight.h"

Knight::Knight(SquareColor color, Pos position) : Piece(color, position) {

}

void Knight::getValidMoves(){

}

PieceID Knight::getType() const{
    return knight;
}
