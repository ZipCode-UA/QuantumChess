#ifndef TYPES_H
#define TYPES_H

enum SquareColor{
    White,
    Black
};

enum PieceID{
    king,
    queen,
    bishop,
    knight,
    rook,
    pawn
};

struct Pos{
    int row;
    int column;
};

struct Move{
    Pos start;
    Pos end;
};

struct MovePair{
    Move m1;
    Move m2;
};

enum States {
    pickPieceFirst,
    pickSquareFirst,
    pickPieceSecond,
    pickSquareSecond,
    movePieces,
    waitingForOpponent
};

#endif
