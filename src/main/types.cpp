#include "types.h"

SquareColor getPieceColor(PieceID ID){
    if (ID >= 0 && ID <= 5)
        return White;
    if (ID >= 6 && ID <= 11)
        return Black;
    else
        return InvalidColor;
}