#ifndef TYPES_H
#define TYPES_H

enum SquareColor{
    White,
    Black
};

enum PieceID{
    WKing,
    WQueen,
    WBishop,
    WKnight,
    WRook,
    WPawn,
    BKing,
    BQueen,
    BBishop,
    BKnight,
    BRook,
    BPawn,
    InvalidPiece
};

struct Pos{
    int row;
    int column;

    bool operator==(const Pos& rightSide) const {
        return row == rightSide.row && column == rightSide.column;
    }
};

struct Move{
    Pos start;
    Pos end;

    bool operator==(const Move& rightSide) const {
        return start == rightSide.start && end == rightSide.end;
    }
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
