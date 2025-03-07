/*
    window.cpp

    window class for QuantumChess Project

    ZipCode
*/

#include "window.h"

// @TODO implement constructor
/*
    Initializer for window class
*/
Window::Window(){
    InitWindow(screenWidth, screenHeight, "Quantum Chess");
    Camera2D camera = { 0 };
    camera.zoom = 1.0f;

    SetTargetFPS(30);
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

// @TODO implement render method
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

}
