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
std::vector<std::pair<int, int>> Pawn::getValidMoves(){
    using pair = std::pair<int, int>;

    if(color == White){
        pair down = {1, 0};
        pair diagonalRight = {1, 1};
        pair diagonalLeft = {1, -1};
        return {down, diagonalRight, diagonalLeft};
    }

    pair up = {-1, 0};
    pair diagonalRight = {-1, 1};
    pair diagonalLeft = {-1, -1};
    return {up, diagonalRight, diagonalLeft};
}

PieceID Pawn::getType() const{
    return pawn;
}
