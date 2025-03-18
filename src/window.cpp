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

    spriteSheet = LoadTexture("../assets/Chess_Pieces_Sprite.png");
    createBoardTexture();
}

/*
    Destructor for Window class
*/
Window::~Window(){
    if (spriteSheet.id != 0)
        UnloadTexture(spriteSheet);

    if(board.texture.id != 0)
        UnloadRenderTexture(board);

    CloseWindow();
}

/*
    Render window
*/
void Window::render(){
    BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Quantum Chess!", 20, 20, 20, LIGHTGRAY);

        DrawTextureV(board.texture, { 0.0F, 0.0F }, WHITE);

        auto pieces = game.getPieces();
        for (auto cur : pieces){
            drawPiece(cur.second, getSquarePosition({cur.first.row, cur.first.column}));
        }

        drawPiece(9, GetMousePosition(), true);

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
    get the position in the window of a square by index
*/
Vector2 Window::getSquarePosition(std::pair<int, int> square){
    return {
        (7 - square.second) * boardWidth/8 + boardStart.x,
        (7 - square.first) * boardWidth/8 + boardStart.y
    };
}

/*
    Handle resizing of the window
*/
void Window::resizedWindow(){
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();
    createBoardTexture();
}

/*
    Creates board texture
*/
void Window::createBoardTexture(){
    if (board.texture.id != 0)
        UnloadRenderTexture(board);

    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
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
    Draws a specific piece on the board

    @param[in] pieceKey key for the corresponding piece
*/
void Window::drawPiece(int pieceKey, Vector2 pos, bool center){
    Vector2 origin = (center ? (Vector2){boardWidth/16, boardWidth/16} : (Vector2){0, 0});
    Rectangle destination = (Rectangle){pos.x, pos.y, boardWidth/8, boardWidth/8};
    Rectangle spriteRect;

    spriteRect.height = spriteHeight;
    spriteRect.width = spriteWidth;

    if (pieceKey > 5){
        spriteRect.y = spriteHeight;
        spriteRect.x = (pieceKey - 6) * spriteWidth;
    } else {
        spriteRect.y = 0;
        spriteRect.x = pieceKey * spriteWidth;
    }

    DrawTexturePro(
        spriteSheet,
        spriteRect,
        destination,
        origin,
        0.0f,
        WHITE
    );
}
