/*
    QuantumChess.cpp

    Controller class for the QuantumChess game.

    ZipCode
*/

#include "quantumChess.h"

/*
    Initializer for QuantumChess
*/
QuantumChess::QuantumChess() { }

/*
    Manages the state of User interaction (i.e. selected piece, then selected move)
*/
void QuantumChess::processInput() {}

// @TODO Implement game loop
/*
    Game loop
*/
void QuantumChess::run() {
    while (!window.shouldClose()){
        window.pollEvents();
        window.render();
    }
}

// @TODO Implement update method
/*
    Update the state of the board with new moves
*/
void QuantumChess::update() {}
