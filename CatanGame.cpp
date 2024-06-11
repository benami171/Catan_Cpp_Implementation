#include "CatanGame.hpp"

#include <set>
#include <string>
#include <unordered_map>

#include "Player.hpp"

using namespace std;

namespace Catan {


CatanGame::CatanGame() {
    turnNumber = 0;
    resourceCardsLeft = {{"Ore", 19}, {"Wood", 19}, {"Brick", 19}, {"Wheat", 19}, {"Sheep", 19}};
    developmentCardsLeft = {{"Knight", 14}, {"Victory Point", 5}, {"Road Building", 2}, {"Year of Plenty", 2}, {"Monopoly", 2}};
    players = {Player("p1"), Player("p2"), Player("p3")};
    initializeBoard();
}

void CatanGame::initializeBoard() {
    board = Board();
}

void CatanGame::startGame() {
    // implement later
}

void CatanGame::nextPlayer() {
    turnNumber = (turnNumber + 1) % 3;
}
}  // namespace Catan