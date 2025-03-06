set(Sources
    "assetManager.cpp"
    "window.cpp"
    "gameState.cpp"
    "board.cpp"
    "piece.cpp"
    "king.cpp"
    "queen.cpp"
    "rook.cpp"
    "bishop.cpp"
    "knight.cpp"
    "pawn.cpp"
)

add_library(src ${Sources})
target_include_directories(src PUBLIC "../include")