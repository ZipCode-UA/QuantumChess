#include "king.h"

King::King(SquareColor color, Pos position) : Piece(color, position) {

}

void King::getValidMoves(){

}

PieceID King::getType() const{
    return king;
}
