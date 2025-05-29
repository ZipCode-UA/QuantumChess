#include "piece.h"

Piece::Piece(SquareColor color, Pos pos) : color(color), pos(pos) {

}

Pos Piece::getPosition() const{
    return pos;
}

SquareColor Piece::getColor() const{
    return color;
}

void Piece::setPosition(Pos newPos) {
    pos = newPos;
}
