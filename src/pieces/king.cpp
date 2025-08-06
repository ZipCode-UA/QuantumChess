#include "king.h"
#include <utility>
#include <vector>

King::King(SquareColor color, Pos position) : Piece(color, position) {

}

std::vector<Pos> King::getValidMoves(){
    Pos up = {-1, 0};
    Pos down = {1, 0};
    Pos left = {0, -1};
    Pos right = {0, 1};

    return {up, down, left, right};
}

PieceID King::getType() const{
    return king;
}
