#include "bishop.h"

Bishop::Bishop(SquareColor color, Pos position) : Piece(color, position) {

}

void Bishop::getValidMoves(){

}

PieceID Bishop::getType() const{
    return bishop;
}
