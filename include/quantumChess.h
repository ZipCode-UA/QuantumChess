/*
    QuantumChess.h

    Controller class for the QuantumChess game.

    ZipCode
*/

#ifndef QUANTUMCHESS_H
#define QUANTUMCHESS_H

#include "window.h"

class QuantumChess{
private:
    // GameState gameState;
    Window window;
    // UIState uiState;
public:
    /*
        Initializer for QuantumChess
    */
    QuantumChess();

    // @TODO Implement CreateMove
    /*
        Manages the state of User interaction (i.e. selected piece, then selected move)
    */
    void processInput();

    // @TODO Implement update method
    /*
        Update the state of the board with new moves
    */
    void update();
};

#endif
