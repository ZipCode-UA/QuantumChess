/*
    Board.h

    Board class for QuantumChess Project

    ZipCode
*/

#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include <memory>
#include <vector>
#include <functional>

class Board{
private:
    std::unique_ptr<Piece> pieces[8][8];

    // returns a reference to the piece at the given position
    std::unique_ptr<Piece>& getPiece(Pos pos);

public:
    Board();

    void resetBoard();

    // Returns a list of pieces on the Board. Stores position and type of each piece
    std::vector<std::pair<Pos, int>> getPieces();

    void movePiece(Move move);

    // Checks if the square on board is empty
    bool isEmpty(Pos pos);
};

#endif
