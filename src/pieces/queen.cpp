#include "queen.h"
#include <utility>
#include <vector>

Queen::Queen(SquareColor color, Pos position) : Piece(color, position) {

}

std::vector<Pos> Queen::getValidMoves(){
    std::vector<Pos> validMoves;

    // Horizontal and vertical moves
    for (int i = 1; i <= 7; ++i) {
        validMoves.push_back({i, 0});      // Right
        validMoves.push_back({-i, 0});     // Left
        validMoves.push_back({0, i});      // Down
        validMoves.push_back({0, -i});     // Up
    }

    // Diagonal moves
    for (int i = 1; i <= 7; ++i) {
        validMoves.push_back({i, i});      // Down-right
        validMoves.push_back({i, -i});     // Down-left
        validMoves.push_back({-i, i});     // Up-right
        validMoves.push_back({-i, -i});    // Up-left
    }

    return {validMoves};
}

PieceID Queen::getType() const{
    return (color == White) ? WQueen : BQueen;
}
