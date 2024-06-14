#include "CatanGame.hpp"
#include "Board.hpp"
#include "Player.hpp"

using namespace std;
using namespace Catan;

namespace Catan {

class developmentCard;

CatanGame::CatanGame(Player& player1, Player& player2, Player& player3) {
    turnCounter = 0;
    resourceCardsLeft = {{"Ore", 19}, {"Wood", 19}, {"Brick", 19}, {"Wheat", 19}, {"Sheep", 19}};
    developmentCardsLeft = {{"Knight", 14}, {"Victory Point", 5}, {"Road Building", 2}, {"Year of Plenty", 2}, {"Monopoly", 2}};
    players = {&player1, &player2, &player3};
    currentPlayerTurn = "P1";
}

void CatanGame::printBoard() {
    board.printBoard();
}

Board& CatanGame::getBoard() {
    return board;
}

int CatanGame::getTurnCounter() {
    return turnCounter;
}
vector<Player*>& CatanGame::getPlayers() {
    return players;
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
    cout  << playerName << " is playing now..." << endl;
    return;
}

void CatanGame::endTurn() {
    if (currentPlayerTurn == "P1") {
        players[0]->setTurn(false);
        startTurn("P2");
    } else if (currentPlayerTurn == "P2") {
        players[1]->setTurn(false);
        startTurn("P3");
    } else {
        players[2]->setTurn(false);
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

int CatanGame::developmentCardsRemaining(string card) {
    return developmentCardsLeft[card];
}

string CatanGame::getCurrentPlayerTurn() {
    return currentPlayerTurn;
}

void CatanGame::printPlayersStats() {
    for (size_t i = 0; i < players.size(); i++) {
        players[i]->printPlayerInfo();
    }
}

void CatanGame::checkLargestArmy() {
    for (size_t i = 0; i < players.size(); i++) {
        if (players[i]->getDevelopmentCardAmount("Knight") >= 3) {
            if(players[i]->hasLargestArmy == false) {
                players[i]->addVictoryPoints(2);
                players[i]->hasLargestArmy = true;
            }
            cout << players[i]->getName() << " has the largest army." << endl;
        }
    }
}

}  // namespace Catan