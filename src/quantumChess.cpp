/*
    QuantumChess.cpp

    Interface between the window and the game model for the QuantumChess game.

    ZipCode
*/

#include "quantumChess.h"

/*
    Initializer for QuantumChess
*/
QuantumChess::QuantumChess(){ }

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
        std::optional<std::pair<int, int>> index = window.pollEvents();
        if (index != std::nullopt)
            squareClicked(index);
        window.render();
    }
}

/*
    Callback for when a cell was clicked in the window
*/
void QuantumChess::squareClicked(const std::optional<std::pair<int, int>>& index){
    // TODO
    window.highlightSquare(index.value());
}

// @TODO Implement update method
/*
    Update the window with changes made to the gameState
*/
void QuantumChess::update() {}
