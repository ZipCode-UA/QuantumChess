#include "bishop.h"
#include <utility>
#include <vector>

Bishop::Bishop(SquareColor color, Pos position) : Piece(color, position) {

}

std::vector<std::pair<int, int>> Bishop::getValidMoves(){
    std::vector<std::pair<int, int>> validMoves;

    // Diagonal moves
    for (int i = 1; i <= 7; ++i) {
        validMoves.push_back({i, i});      // Down-right
        validMoves.push_back({i, -i});     // Down-left
        validMoves.push_back({-i, i});     // Up-right
        validMoves.push_back({-i, -i});    // Up-left
    }
    return {validMoves};
}

PieceID Bishop::getType() const{
    return bishop;
}
