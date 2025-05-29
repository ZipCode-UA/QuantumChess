#include "knight.h"
#include <utility>
#include <vector>

Knight::Knight(SquareColor color, Pos position) : Piece(color, position) {

}

std::vector<std::pair<int, int>> Knight::getValidMoves(){
    using pair = std::pair<int, int>;

    pair downRight = {2, 1};
    pair downLeft = {2, -1};

    pair rightUp = {-1, 2};
    pair rightDown = {1, 2};

    pair leftUp = {-1, -2};
    pair leftDown = {1, -2};

    pair upRight = {-2, 1};
    pair upLeft = {-2, -1};

    return {
        downRight, downLeft,
        rightUp, rightDown,
        leftUp, leftDown,
        upRight, upLeft
    };
}

PieceID Knight::getType() const{
    return knight;
}
