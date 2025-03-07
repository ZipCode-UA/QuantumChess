/*
    window.h

    window class for QuantumChess Project

    ZipCode
*/

#include "raylib.h"
#include <vector>

class Window{
private:
    const int screenWidth = 800;
    const int screenHeight = 450;

    float boardWidth;
    RenderTexture2D board;
    Vector2 boardStart;
    Vector2 boardEnd;

    std::vector<std::pair<int, int>> highlightedSquares;

    /*
        based on screenWidth and Screen Height determines board width and start and end positions
    */
    void redrawBoardTexture();

    /*
        Get corrospoding square by cursor position

        @param cursorPosition 2d vector representing cursor position
        @return index of cell clicked
    */
    std::pair<int, int> getSquare(Vector2 cursorPosition);

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
        Returns flag for whether or not the window should close

        @return Window Should Close
    */
    bool shouldClose();

    /*
        Render window
    */
    void render();

    // @TODO implement poll event method
    /*
        poll events for 
    */
    void pollEvents();
};
