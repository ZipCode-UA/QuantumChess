/*
    assetManager.h

    Manages assets for the Quantum Chess application
*/

#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "raylib.h"
#include <unordered_map>

class AssetManager{
private:
    std::unordered_map<int, Texture2D> pieces;

public:
    /*
        Loads assets when constructed
    */
    AssetManager();

    /*
        Unload Assets when destructed
    */
    ~AssetManager();

    /*
        Retrieves a specific piece texture

        @param[in] pieceKey key for the corresponding piece
    */
    Texture2D& retrievePiece(int pieceKey);
};

#endif
