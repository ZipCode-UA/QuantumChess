/*
    BoardInterface.h

    Controller class for the BoardInterface game.

    ZipCode
*/

#ifndef BOARDINTERFACE_H
#define BOARDINTERFACE_H

#include "window.h"

class BoardInterface{
private:
    // GameState gameState;
    // UIState uiState;
public:
    /*
        Initializer for QuantumChess
    */
    BoardInterface();

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
