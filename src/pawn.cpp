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
    if(color == White){
        return {{1, 0}};
    }
    return {{-1, 0}};
}

PieceID Pawn::getType() const{
    return pawn;
}
