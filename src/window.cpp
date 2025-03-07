/*
    window.cpp

    window class for QuantumChess Project

    ZipCode
*/

#include "window.h"
#include "raymath.h"

/*
    Initializer for window class
*/
Window::Window(){
    InitWindow(screenWidth, screenHeight, "Quantum Chess");

    Camera2D camera = { 0 };
    camera.zoom = 1.0f;
    SetTargetFPS(30);

    board = LoadRenderTexture(screenWidth, screenHeight);
    redrawBoardTexture();
}

void Window::redrawBoardTexture(){
    boardWidth = ((screenWidth < screenHeight) ? screenWidth : screenHeight) * 0.95;
    boardStart = {(float)(screenWidth-boardWidth)/2, (float)(screenHeight-boardWidth)/2};
    boardEnd = {boardStart.x+boardWidth, boardStart.y+boardWidth};

    BeginTextureMode(board);
        ClearBackground(RAYWHITE);
        float squareSize = boardWidth/8;
        for(int j = 0; j < 8; ++j){
            for (int k = 0; k < 8; ++k){
                DrawRectangleV(
                    Vector2Add(boardStart, {j*squareSize, k*squareSize}), 
                    {squareSize, squareSize}, 
                    ((j + k) % 2 == 0) ? BROWN : BEIGE
                );
            }
        }
    EndTextureMode();
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

    DrawTextureV(board.texture, { 0.0F, 0.0F }, WHITE);

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
