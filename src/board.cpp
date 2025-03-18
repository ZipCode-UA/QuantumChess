/*
    Board.cpp

    Board class for QuantumChess Project

    ZipCode
*/

#include "types.h"
#include "board.h"
#include "pawn.h"
#include "bishop.h"
#include "rook.h"
#include "knight.h"
#include "queen.h"
#include "king.h"
#include <optional>

Board::Board(){
    resetBoard();
}

std::vector<std::pair<Pos, int>> Board::getPieces() {
    std::vector<std::pair<Pos, int>> pieceList;
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            if (pieces[i][j] != nullptr){
                pieceList.push_back(std::make_pair<Pos, int>(pieces[i][j].get()->getPosition(), pieces[i][j].get()->getType() + pieces[i][j].get()->getColor() * 6));
            }
        }
    }
    return pieceList;
}

void Board::resetBoard(){
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            SquareColor color = (i == 7 || i == 6) ? Black : White;
            if (i == 1 || i==6){
                pieces[i][j] = std::make_unique<Pawn>(color, (Pos){i, j});
            }
            else if (i == 0 || i == 7){
                if (j == 0 || j == 7)
                    pieces[i][j] = std::make_unique<Rook>(color, (Pos){i, j});
                else if (j == 1 || j == 6)
                    pieces[i][j] = std::make_unique<Knight>(color, (Pos){i, j});
                else if (j == 2 || j == 5)
                    pieces[i][j] = std::make_unique<Bishop>(color, (Pos){i, j});
                else if (j == 3 && i == 0)
                    pieces[i][j] = std::make_unique<King>(color, (Pos){i, j});
                else if (j == 4 && i == 7)
                    pieces[i][j] = std::make_unique<King>(color, (Pos){i, j});
                else if (j == 4 && i == 0)
                    pieces[i][j] = std::make_unique<Queen>(color, (Pos){i, j});
                 else if (j == 3 && i == 7)
                    pieces[i][j] = std::make_unique<Queen>(color, (Pos){i, j});
            }
            else {
                pieces[i][j] = nullptr;
            }
        }
    }
}
