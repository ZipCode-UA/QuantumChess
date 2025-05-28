#include "king.h"

King::King(SquareColor color, Pos position) : Piece(color, position) {

}

std::pair<int, int> King::getValidMoves(){

}

PieceID King::getType() const{
    return king;
}
