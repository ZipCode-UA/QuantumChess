#include "queen.h"

Queen::Queen(SquareColor color, Pos position) : Piece(color, position) {

}

std::pair<int, int> Queen::getValidMoves(){

}

PieceID Queen::getType() const{
    return queen;
}
