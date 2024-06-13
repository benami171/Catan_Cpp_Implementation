#include "CatanGame.hpp"

#include <set>
#include <string>
#include <unordered_map>

#include "Player.hpp"

using namespace std;

namespace Catan {

class developmentCard;

CatanGame::CatanGame(Player& player1, Player& player2, Player& player3) {
    turnCounter = 0;
    resourceCardsLeft = {{"Ore", 19}, {"Wood", 19}, {"Brick", 19}, {"Wheat", 19}, {"Sheep", 19}};
    developmentCardsLeft = {{"Knight", 14}, {"Victory Point", 5}, {"Road Building", 2}, {"Year of Plenty", 2}, {"Monopoly", 2}};
    players = {&player1, &player2, &player3};
    currentPlayerTurn = "P1";
    initializeBoard();
}

void CatanGame::initializeBoard() {
 //   board = Board();
}

Board& CatanGame::getBoard() {
    return board;
}

int CatanGame::getTurnCounter() {
    return turnCounter;
}


void CatanGame::startGame() {
    // You can add code to handle the game start, initial placement, etc.
    cout << "Game started" << endl;
}

void CatanGame::startTurn(string playerName) {
    if (playerName != "P1" && playerName != "P2" && playerName != "P3") {
        cout << "Invalid player name: " << playerName << endl;
        return;
    }
    turnCounter++;
    currentPlayerTurn = playerName;
    if (playerName == "P1"){
        players[0]->setTurn(true);
    } else if (playerName == "P2") {
        players[1]->setTurn(true);
    } else {
        players[2]->setTurn(true);
    }
    cout << "It is now " << playerName << "'s turn." << endl;
    return;
}

void CatanGame::endTurn() {
    if (currentPlayerTurn == "P1") {
        startTurn("P2");
    } else if (currentPlayerTurn == "P2") {
        startTurn("P3");
    } else {
        startTurn("P1");
    }
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