#include "queen.h"
#include <utility>
#include <vector>

Queen::Queen(SquareColor color, Pos position) : Piece(color, position) {

}

std::vector<std::pair<int, int>> Queen::getValidMoves(){
    if(color == White){
        return {{3, 0}};
    }
    return {{-3, 0}};
}

PieceID Queen::getType() const{
    return queen;
}
