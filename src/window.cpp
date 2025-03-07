/*
    window.cpp

    window class for QuantumChess Project

    ZipCode
*/

#include "window.h"

/*
    Initializer for window class
*/
Window::Window(){
    InitWindow(screenWidth, screenHeight, "Quantum Chess");

    Camera2D camera = { 0 };
    camera.zoom = 1.0f;
    SetTargetFPS(30);

    boardWidth = (screenWidth < screenHeight) ? screenWidth : screenHeight;
}

Window::~Window(){
    CloseWindow();
}

/*
    Returns flag for whether or not the window should close

    @return Window Should Close
*/
bool Window::shouldClose(){
    return WindowShouldClose();
}

/*
    Render window
*/
void Window::render(){
    BeginDrawing();

    ClearBackground(RAYWHITE);
    DrawText("Quantum Chess!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
}

// @TODO implement poll event method
/*
    poll events for 
*/
void Window::pollEvents(){
    if(IsKeyPressed(KEY_ESCAPE)) {
        CloseWindow();
    } else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        // Do Something
    }

}

/*
    Draws empty chess board
*/
void Window::drawGrid() {

}

/*
    Get corrospoding square by cursor position

    @param cursorPosition 2d vector representing cursor position
    @return index of cell clicked
*/
std::pair<int, int> Window::getSquare(Vector2 cursorPosition){

}
