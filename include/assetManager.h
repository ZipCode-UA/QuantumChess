/*
    assetManager.h

    Manages assets for the Quantum Chess application
*/

#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "raylib.h"
#include <unordered_map>

class AssetManager{
public: //public for testing should be private
    Texture2D spriteSheet;
    const int columns = 5;
    const int rows = 2;
    float spriteWidth = 67.5;
    float spriteHeight = 67.5;

    RenderTexture2D board;
    Vector2 boardStart;
    Vector2 boardEnd;
    float boardWidth;

    /*
        Creates board texture
    */
    void createBoardTexture();

public:
    /*
        Unload Assets when destructed
    */
    ~AssetManager();

    /*
        Loads assets from file
    */
    void loadAssets();

    /*
        Draws a specific piece on the board

        @param[in] pieceKey key for the corresponding piece
    */
    void drawPiece(int pieceKey, Vector2 pos);

    /*
        Draws board
    */
    void drawBoard();

    /*
        Call when the window dimensions are updated
    */
    void dimensionsUpdated();
};

#endif
