/*
    window.h

    window class for QuantumChess Project

    ZipCode
*/

#ifndef WINDOW_H
#define WINDOW_H

#include "raylib.h"
#include <vector>

class Window{
private:
    int screenWidth = 1600;
    int screenHeight = 1000;

    Texture2D spriteSheet;
    const int columns = 5;
    const int rows = 2;
    const float spriteWidth = 67.5;
    const float spriteHeight = 67.5;

    RenderTexture2D board;
    Vector2 boardStart;
    Vector2 boardEnd;
    float boardWidth;

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
        Get corrospoding square by cursor position

        @param cursorPosition 2d vector representing cursor position
        @return index of cell clicked
    */
    std::pair<int, int> getSquare(Vector2 cursorPosition);

    /*
        Handle resizing of the window
    */
    void resizedWindow();

    /*
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


};

#endif
