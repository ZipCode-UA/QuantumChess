#include "gameState.h"
#include "types.h"

SquareColor GameState::getTurn() const {
    return turn;
}

int GameState::next() {
    if (turn == White) {
        return turn = Black;
    }
    return turn = White;
}

States GameState::getState() const {
    return state;
}

void GameState::setState(States newState) {
    state = newState;
}