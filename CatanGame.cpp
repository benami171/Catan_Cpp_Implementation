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
    // You can add code to handle the game start, initial placement, etc.
    cout << "Game started" << endl;
}

void CatanGame::nextPlayer() {
    turnNumber = (turnNumber + 1) % 3;
}

bool CatanGame::buyDevelopmentCard(string card, Player& player) {
    // check if player has enough resources to buy a development card
    if(player.getResourceCardAmount("Ore") < 1 || player.getResourceCardAmount("Wheat") < 1 || player.getResourceCardAmount("Sheep") < 1) {
        cout << "Not enough resources to buy a development card." << endl;
        return false;
    }

    // check if there are any development cards of the preffered type left.
    if (developmentCardsLeft[card] > 0) {
        developmentCardsLeft[card]--;
        player.addDevelopmentCard(card, 1);
        player.removeResourceCard("Ore", 1);
        player.removeResourceCard("Wheat", 1);
        player.removeResourceCard("Sheep", 1);
        return true;
    } else {
        cout << "No " << card << " cards left." << endl;
        return false;
    }
}

}  // namespace Catan