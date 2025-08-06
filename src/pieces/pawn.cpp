#include "pawn.h"
#include <utility>
#include <vector>

Pawn::Pawn(SquareColor color, Pos position) : Piece(color, position) {

}
/*
    returns the coordinates of the valid moves for the pawn

    so if the pawn is black it can move up one square
    therefore the function would return {1, 0}
*/
std::vector<Pos> Pawn::getValidMoves(){

    if(color == White){
        Pos down = {1, 0};
        Pos diagonalRight = {1, 1};
        Pos diagonalLeft = {1, -1};
        return {down, diagonalRight, diagonalLeft};
    }

    Pos up = {-1, 0};
    Pos diagonalRight = {-1, 1};
    Pos diagonalLeft = {-1, -1};
    return {up, diagonalRight, diagonalLeft};
}

PieceID Pawn::getType() const{
    return (color == White) ? WPawn : BPawn;
}
