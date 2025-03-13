set(Sources
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
    "quantumChess.cpp"
)

add_library(src ${Sources})
target_include_directories(src PUBLIC "../include")
target_link_libraries(src PUBLIC raylib)