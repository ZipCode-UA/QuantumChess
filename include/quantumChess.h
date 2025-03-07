/*
    QuantumChess.h

    Interface between the window and the game model for the QuantumChess game.

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

    // @TODO Implement game loop
    /*
        Game loop
    */
    void run();

    /*
        Callback for when a cell was clicked in the window

        @param [in] cell index clicked
    */
    void squareClicked(const std::optional<std::pair<int, int>>&);

    // @TODO Implement update method
    /*
        Update the state of the board with new moves
    */
    void update();
};

#endif
