/*
    window.cpp

    window class for QuantumChess Project

    ZipCode
*/

#include "window.h"
#include "raymath.h"
#include <iostream>

/*
    Initializer for window class
*/
Window::Window(){
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Quantum Chess");

    Camera2D camera = { 0 };
    camera.zoom = 1.0f;
    SetTargetFPS(30);

    assets.loadAssets();
}

/*
    Destructor for Window class
*/
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

        assets.drawBoard();
        assets.drawPiece(1, getSquarePosition({0,0}));

    EndDrawing();
}

// @TODO implement poll event method
/*
    poll events for
*/
void Window::pollEvents(){
    if(IsKeyPressed(KEY_ESCAPE)) {
        CloseWindow();
    }
    if (IsWindowResized()){
        resizedWindow();
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        // Do Something
    }
}

/*
    Main loop for program
*/
void Window::run(){
    while(!WindowShouldClose()){
        pollEvents();
        render();
    }
}

/*
    Get corrospoding square by cursor position

    @param cursorPosition 2d vector representing cursor position
    @return index of cell clicked
*/
std::pair<int, int> Window::getSquare(Vector2 cursorPosition){
    int squareSize = boardWidth/8;

    // Check if cursor is within the board
    if (cursorPosition.x < boardStart.x || cursorPosition.x > boardEnd.x || cursorPosition.y < boardStart.y || cursorPosition.y > boardEnd.y){
        return {-1, -1};
    }

    // Get the square
    int cursorSquareX = (cursorPosition.x - boardStart.x) / squareSize;
    int cursorSquareY = (cursorPosition.y - boardStart.y) / squareSize;

    return {cursorSquareX, cursorSquareY};
}

/*
*/
Vector2 Window::getSquarePosition(std::pair<int, int> square){
    return {
        square.first*boardWidth/8 + assets.boardStart.x,
        square.second*boardWidth/8 + assets.boardStart.y
    };
}

/*
    Handle resizing of the window
*/
void Window::resizedWindow(){
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();
    assets.dimensionsUpdated();
}
