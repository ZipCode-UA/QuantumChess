/*
    window.h

    window class for QuantumChess Project

    ZipCode
*/

#include "raylib.h"
#include <vector>

class Window{
private:
    int screenWidth = 800;
    int screenHeight = 450;

    float boardWidth;
    RenderTexture2D board;
    Vector2 boardStart;
    Vector2 boardEnd;

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

    /*
        Handle resizing of the window
    */
    void resizedWindow();

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
