#include "pawn.h"
#include <utility>

Pawn::Pawn(SquareColor color, Pos position) : Piece(color, position) {

}
/*
    returns the coordinates of the valid moves for the pawn

    so if the pawn is black it can move up one square
    therefore the function would return {1, 0}
*/
std::pair<int, int> Pawn::getValidMoves(){
    return {1, 0};
}

PieceID Pawn::getType() const{
    return pawn;
}
