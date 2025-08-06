#include "piece.h"
#include "board.h"

Piece::Piece(SquareColor color, Pos pos, Board *board) : color(color), pos(pos), board(board) {

}

Pos Piece::getPosition() const{
    return pos;
}

SquareColor Piece::getColor() const{
    return color;
}

void Piece::setPosition(Pos newPos) {
    pos = newPos;
    hasMoved = true;
}
