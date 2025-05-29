#include "bishop.h"
#include <utility>
#include <vector>

Bishop::Bishop(SquareColor color, Pos position) : Piece(color, position) {

}

std::vector<std::pair<int, int>> Bishop::getValidMoves(){
    if(color == White){
        return {{2, 2}};
    }

    return {{-2, -2}};
}

PieceID Bishop::getType() const{
    return bishop;
}
