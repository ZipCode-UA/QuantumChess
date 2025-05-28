#include "queen.h"

Queen::Queen(SquareColor color, Pos position) : Piece(color, position) {

}

std::pair<int, int> Queen::getValidMoves(){
    return {3, 0};
}

PieceID Queen::getType() const{
    return queen;
}
