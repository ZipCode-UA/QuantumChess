#include "queen.h"

Queen::Queen(SquareColor color, Pos position) : Piece(color, position) {

}

std::pair<int, int> Queen::getValidMoves(){
    if(color == White){
        return {3, 0};
    }
    return {-3, 0};
}

PieceID Queen::getType() const{
    return queen;
}
