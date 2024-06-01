#include "CatanGame.hpp"

#include <set>
#include <string>
#include <unordered_map>

#include "Player.hpp"

using namespace std;

namespace Catan {

CatanGame::CatanGame() {
    turnNumber = 1;
    resourceCardsLeft = {{"Ore", 19}, {"Wood", 19}, {"Brick", 19}, {"Wheat", 19}, {"Sheep", 19}};
    players = {Player("p1"), Player("p2"), Player("p3")};
}

void CatanGame::initializeBoard() {
    // implement later
}

void CatanGame::startGame() {
    // implement later
}
}  // namespace Catan