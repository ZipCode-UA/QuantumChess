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

    updateBoardDimentions();
}

void Window::updateBoardDimentions(){
    boardWidth = (screenWidth < screenHeight) ? screenWidth : screenHeight;
    boardStart = {(float)screenWidth-boardWidth-20/2, (float)screenHeight-boardWidth-20/2};
    boardEnd = {boardStart.x+boardWidth, boardStart.y+boardWidth};
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
    DrawText("Quantum Chess!", 20, 20, 20, LIGHTGRAY);

    drawGrid();

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

// @TODO implement getSquare function
/*
    Get corrospoding square by cursor position

    @param cursorPosition 2d vector representing cursor position
    @return index of cell clicked
*/
std::pair<int, int> Window::getSquare(Vector2 cursorPosition){

    // temporary return so it compiles
    return {0, 0};
}
