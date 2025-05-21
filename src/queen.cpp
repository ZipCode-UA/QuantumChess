#include "queen.h"

Queen::Queen(SquareColor color, Pos position) : Piece(color, position) {

}

void Queen::getValidMoves(){

}

PieceID Queen::getType() const{
    return queen;
}
