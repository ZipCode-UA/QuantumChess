/*
    UIState.cpp

    UIState for Window class

    ZipCode
*/

#ifndef UISTATE_H
#define UISTATE_H

#include <vector>

enum stateOptions{
    selectedPiece1,
    selectedMove,
    selectedPiece2,
    selectedMove
};

struct UIState{
    std::vector<std::tuple<int, int, int>> squaresHighlighted;
    std::vector<std::tuple<int, int, int>> pieces;
    stateOptions state;
};

#endif
