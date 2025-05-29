#include "king.h"
#include <utility>
#include <vector>

King::King(SquareColor color, Pos position) : Piece(color, position) {

}

std::vector<std::pair<int, int>> King::getValidMoves(){
    using pair = std::pair<int, int>;

    pair up = {-1, 0};
    pair down = {1, 0};
    pair left = {0, -1};
    pair right = {0, 1};

    return {up, down, left, right};
}

PieceID King::getType() const{
    return king;
}
