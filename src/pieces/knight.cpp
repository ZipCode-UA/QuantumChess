#include "knight.h"
#include "board.h"
#include <utility>
#include <vector>

Knight::Knight(SquareColor color, Pos position, Board *board) : Piece(color, position, board) {

}

std::vector<Pos> Knight::getValidMoves(){

    Pos downRight = {2, 1};
    Pos downLeft = {2, -1};

    Pos rightUp = {-1, 2};
    Pos rightDown = {1, 2};

    Pos leftUp = {-1, -2};
    Pos leftDown = {1, -2};

    Pos upRight = {-2, 1};
    Pos upLeft = {-2, -1};

    return {
        downRight, downLeft,
        rightUp, rightDown,
        leftUp, leftDown,
        upRight, upLeft
    };
}

PieceID Knight::getType() const{
    return (color == White) ? WKnight : BKnight;
}
