/*
    GameState.h

    GameState class for QuantumChess Project

    ZipCode
*/

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "types.h"

class GameState{
private:
    SquareColor turn;
    States state;

public:
    GameState() : turn(White), state(pickPieceFirst) {}

    SquareColor getTurn() const;

    int next();

    States getState() const;

    void setState(States newState);
};

#endif
