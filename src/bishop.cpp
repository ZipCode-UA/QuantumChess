#include "bishop.h"

Bishop::Bishop(SquareColor color, Pos position) : Piece(color, position) {

}

std::pair<int, int> Bishop::getValidMoves(){

}

PieceID Bishop::getType() const{
    return bishop;
}
