#include "king.h"

King::King(SquareColor color, Pos position) : Piece(color, position) {

}

std::pair<int, int> King::getValidMoves(){
    if(color == White){
        return {1, 1};
    }
    return {-1, -1};
}

PieceID King::getType() const{
    return king;
}
