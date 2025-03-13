/*
    assetManager.h

    Manages assets for the Quantum Chess application
*/

#include "assetManager.h"
#include "raymath.h"

/*
    Loads assets when constructed
*/
AssetManager::AssetManager(){
}

/*
    Loads assets from file
*/
void AssetManager::loadAssets(){
    spriteSheet = LoadTexture("../assets/Chess_Pieces_Sprite.png");
    createBoardTexture();
}

/*
    Unload Assets when destructed
*/
AssetManager::~AssetManager(){
    if (spriteSheet.id != 0)
        UnloadTexture(spriteSheet);
    if(board.texture.id != 0)
        UnloadRenderTexture(board);
}

/*
    Draws a specific piece on the board

    @param[in] pieceKey key for the corresponding piece
*/
void AssetManager::drawPiece(int pieceKey, Vector2 pos){
    Rectangle spriteRect = {
        0,
        0,
        spriteWidth,
        spriteHeight
    };

    if (pieceKey > 5){
        spriteRect.y = spriteHeight;
        spriteRect.x = (pieceKey - 5) * spriteWidth;
    }

    DrawTexturePro(
        spriteSheet,
        spriteRect,
        {pos.x, pos.y, boardWidth/8, boardWidth/8},
        {0, 0},
        0.0f,
        WHITE
    );
}

/*
    Creates board texture
*/
void AssetManager::createBoardTexture(){
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
    Draws board
*/
void AssetManager::drawBoard(){
    DrawTextureV(board.texture, { 0.0F, 0.0F }, WHITE);
}
