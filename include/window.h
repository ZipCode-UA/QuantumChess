/*
    window.h

    window class for QuantumChess Project

    ZipCode
*/

#include "raylib.h"

class Window{
private:
    const int screenWidth = 800;
    const int screenHeight = 450;
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
