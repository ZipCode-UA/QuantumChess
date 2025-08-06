/*
    window.cpp

    window class for QuantumChess Project

    ZipCode
*/

#include "window.h"
#include "boardInterface.h"
#include "board.h"
#include "raymath.h"
#include "raylib.h"
#include "boardInterface.h"
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

    createBoardTexture();

    loadSprites();
}

/*
    Destructor for Window class
*/
Window::~Window(){
    if(board.texture.id != 0)
        UnloadRenderTexture(board);

    for (auto& cur : sprites){
        if (cur.id != 0)
            UnloadTexture(cur);
    }

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

        // highlighting a square
        highlightSquare();

        // draw valid moves
        for (const auto& pos : validMovePositions) {
            DrawCircleV({pos.x + boardWidth/16, pos.y + boardWidth/16}, boardWidth/20, Fade(GREEN, 0.5f));
        }

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
        handleLeftMouseDown();
    }

}

void Window::handleLeftMouseDown(){
    switch (gameState)
    {
    case pickPieceFirst:
        
        break;
    case pickSquareFirst:
        break;
    case pickPieceSecond:
        break;
    case pickSquareSecond:
        break;
    default:
        break;
    }
    movePiece();
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
    Get corresponding square by cursor position

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
    int cursorSquareY = (cursorPosition.y - boardStart.y) / squareSize;
    int cursorSquareX = (cursorPosition.x - boardStart.x) / squareSize;

    return {cursorSquareY, cursorSquareX};
}

/*
    get the position in the window of a square by index
*/
Vector2 Window::getSquarePosition(std::pair<int, int> square){
    return {
        ( square.second) * boardWidth/8 + boardStart.x,
        ( square.first) * boardWidth/8 + boardStart.y
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

    DrawTexturePro(
        sprites[pieceKey],
        (Rectangle){0, 0, spriteWidth, spriteHeight},
        destination,
        origin,
        0.0f,
        WHITE
    );
}

void Window::highlightSquare(){
    auto square = getSquare(GetMousePosition());
    if (square.first != -1 && square.second != -1) {
        Vector2 squarePos = getSquarePosition(square);
        DrawRectangleV(squarePos, {boardWidth/8, boardWidth/8}, Fade(BLUE, 0.3f));
    }
}

void Window::loadSprites(){
    sprites.resize(12);

    sprites[Pawn] = LoadTexture("../assets/wp.png");
    sprites[Knight] = LoadTexture("../assets/wn.png");
    sprites[Bishop] = LoadTexture("../assets/wb.png");
    sprites[Rook] = LoadTexture("../assets/wr.png");
    sprites[Queen] = LoadTexture("../assets/wq.png");
    sprites[King] = LoadTexture("../assets/wk.png");
    sprites[Pawn + 6] = LoadTexture("../assets/bp.png");
    sprites[Knight + 6] = LoadTexture("../assets/bn.png");
    sprites[Bishop + 6] = LoadTexture("../assets/bb.png");
    sprites[Rook + 6] = LoadTexture("../assets/br.png");
    sprites[Queen + 6] = LoadTexture("../assets/bq.png");
    sprites[King + 6] = LoadTexture("../assets/bk.png");
}

void Window::updateBoard() {
    render();
}

void Window::movePiece() {
    auto square = getSquare(GetMousePosition());
    if(square.first == -1 || square.second == -1)
        return;

    if(!game.isEmpty({square.first, square.second})){
        auto moves = game.getPiece({square.first, square.second})->getValidMoves()[0];
        setDisplayMoves();
        game.movePiece({square.first, square.second}, {square.first + moves.first, square.second + moves.second}, [this]() { updateBoard(); });
    }
}

void Window::setDisplayMoves() {
    if (validMovePositions.size() > 0) {
        validMovePositions.clear();
    }

    auto square = getSquare(GetMousePosition());
    if (square.first == -1 || square.second == -1)
        return;

    auto validMoves = game.getPiece({square.first, square.second})->getValidMoves();
    if (validMoves.size() <= 0)
        return;

    for (const auto& move : validMoves) {
        int upDown = move.first + square.first;
        int leftRight = move.second + square.second;

        // if the move is out of bounds, skip it
        if (upDown < 0 || upDown >= 8 || leftRight < 0 || leftRight >= 8) {
            continue;
        }

        Vector2 pos = getSquarePosition({upDown, leftRight});
        validMovePositions.push_back(pos);
    }
}
