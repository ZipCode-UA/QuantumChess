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
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Quantum Chess");

    Camera2D camera = { 0 };
    camera.zoom = 1.0f;
    SetTargetFPS(30);

    redrawBoardTexture();
}

/*
    based on screenWidth and Screen Height determines board width and start and end positions
*/
void Window::redrawBoardTexture(){
    if (board.texture.id != 0)
        UnloadRenderTexture(board);
    board = LoadRenderTexture(screenWidth, screenHeight);

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

/*
    Destructor for Window class
*/
Window::~Window(){
    if (board.texture.id != 0)
        UnloadRenderTexture(board);

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
    }
    if (IsWindowResized()){
        resizedWindow();
    }
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        // Do Something
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
    Handle resizing of the window
*/
void Window::resizedWindow(){
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    redrawBoardTexture();
}
