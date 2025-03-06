/*
    QuantumChess.h

    Controller class for the QuantumChess game.

    ZipCode
*/

#ifndef QUANTUMCHESS_H
#define QUANTUMCHESS_H

class QuantumChess{
private:
    // Board board;
    // Window window;
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

    // @TODO Implement call to render window
    /*
        Get new state of board and highlighted squares, then call window to update
    */
    void render();

    // @TODO Implement update method
    /*
        Update the state of the board with new moves
    */
    void update();
};

#endif
