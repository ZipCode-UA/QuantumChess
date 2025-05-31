#include "rook.h"
#include <utility>
#include <vector>

Rook::Rook(SquareColor color, Pos position) : Piece(color, position) {

}

std::vector<std::pair<int, int>> Rook::getValidMoves(){
    std::vector<std::pair<int, int>> validMoves;

    // Horizontal and vertical moves
    for (int i = 1; i <= 7; ++i) {
        validMoves.push_back({i, 0});      // Right
        validMoves.push_back({-i, 0});     // Left
        validMoves.push_back({0, i});      // Down
        validMoves.push_back({0, -i});     // Up
    }

    return {validMoves};
}

PieceID Rook::getType() const{
    return rook;
}