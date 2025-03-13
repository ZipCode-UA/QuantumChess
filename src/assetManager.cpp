/*
    assetManager.h

    Manages assets for the Quantum Chess application
*/

#include "assetManager.h"

/*
    Loads assets when constructed
*/
AssetManager::AssetManager(){
    spriteSheet = LoadTexture("../assets/Chess_Pieces_Sprite.png");
}

/*
    Unload Assets when destructed
*/
AssetManager::~AssetManager(){
    UnloadTexture(spriteSheet);
}

/*
    Retrieves a specific piece texture

    @param[in] pieceKey key for the corresponding piece
*/
Texture2D& AssetManager::retrievePiece(int pieceKey){

}