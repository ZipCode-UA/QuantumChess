/*
    window.h

    window class for QuantumChess Project

    ZipCode
*/

#ifndef WINDOW_H
#define WINDOW_H

#include "board.h"
#include "raylib.h"
#include <vector>

class Window{
private:
    int screenWidth = 1600;
    int screenHeight = 1000;

    std::vector<Texture2D> sprites;
    const float spriteWidth = 300;
    const float spriteHeight = 300;

    RenderTexture2D board;
    Vector2 boardStart;
    Vector2 boardEnd;
    float boardWidth;

    Board game;

    void loadSprites();

    /*
        based on screenWidth and Screen Height determines board width and start and end positions
    */

    /*
        Render window
    */
    void render();

    /*
        poll events for
    */
    void pollEvents();

    /*
        Handle resizing of the window
    */
    void resizedWindow();

    /*
        get the position in the window of a square by index
    */
    Vector2 getSquarePosition(std::pair<int, int> square);

    /*
        Creates board texture
    */
    void createBoardTexture();

    /*
        Draws a specific piece on the board

        @param[in] pieceKey key for the corresponding piece
    */
    void drawPiece(int pieceKey, Vector2 pos, bool center = false);

    // highlight the square that the user is hovering over
    void highlightSquare();

    void movePiece();

    void displayMoves();

public:
    /*
        Initializer for window class
    */
    Window();

    /*
        Destructor for Window class
    */
    ~Window();

    /*
        Main loop for program
    */
    void run();

    /*
        Get corresponding square by cursor position

        @param cursorPosition 2d vector representing cursor position
        @return index of cell clicked
    */
    std::pair<int, int> getSquare(Vector2 cursorPosition);

    // public method to update the board
    void updateBoard();

};

#endif
