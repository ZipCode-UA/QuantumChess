#include "pawn.h"
#include "board.h"
#include <utility>
#include <vector>

Pawn::Pawn(SquareColor color, Pos position, Board* board) : Piece(color, position, board) {

}
/*
    returns the coordinates of the valid moves for the pawn

    so if the pawn is black it can move up one square
    therefore the function would return {1, 0}
*/
std::vector<Pos> Pawn::getValidMoves(){
    int directionMultiplier = (color == White) ? 1 : -1;
    std::vector<Pos> moves;

    Pos forward = {pos.row + 1*directionMultiplier, pos.column + 0};
    if (board->isEmpty(forward))
        moves.push_back(forward);
    
    Pos forwardTwo = {pos.row + 2*directionMultiplier, pos.column + 0};
    if (hasMoved == false && board->isEmpty(forward) && board->isEmpty(forwardTwo)){
        moves.push_back(forwardTwo);
    }

    Pos diagonalRight = {pos.row + 1*directionMultiplier, pos.column +1};
    if (getPieceColor(board->getPieceID(diagonalRight)) != color && !board->isEmpty(diagonalRight))
        moves.push_back(diagonalRight);

    Pos diagonalLeft = {pos.row + 1*directionMultiplier, pos.column + -1};
     if (getPieceColor(board->getPieceID(diagonalLeft)) != color && !board->isEmpty(diagonalLeft))
        moves.push_back(diagonalLeft);

    return moves;
}

PieceID Pawn::getType() const{
    return (color == White) ? WPawn : BPawn;
}
