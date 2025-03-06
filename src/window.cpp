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

// @TODO implement render method
/*
    Render window
*/
void Window::render(){

}

// @TODO implement poll event method
/*
    poll events for 
*/
void Window::pollEvents(){

}
