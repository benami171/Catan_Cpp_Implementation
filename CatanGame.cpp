#include "CatanGame.hpp"

#include "Board.hpp"
#include "Player.hpp"

using namespace std;
using namespace Catan;

namespace Catan {

class developmentCard;

CatanGame::CatanGame(Player& player1, Player& player2, Player& player3) {
    turnCounter = 0;
    resourceCardsLeft = {{"ore", 40}, {"lumber", 40}, {"brick", 40}, {"wheat", 40}, {"wool", 40}};
    developmentCardsLeft = {{"knight", 3}, {"victoryPoint", 5}, {"roadBuilding", 2}, {"yearOfPlenty", 2}, {"monopoly", 2}};
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
    if (playerName == "P1") {
        players[0]->setTurn(true);
    } else if (playerName == "P2") {
        players[1]->setTurn(true);
    } else {
        players[2]->setTurn(true);
    }
    cout << playerName << " is playing now..." << endl;
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
    if (player.getResourceCardAmount("ore") < 1 || player.getResourceCardAmount("wheat") < 1 || player.getResourceCardAmount("wool") < 1) {
        cout << "Not enough resources to buy a development card." << endl;
        return false;
    }

    // check if there are any development cards of the preffered type left.
    if (developmentCardsLeft[card] > 0) {
        developmentCardsLeft[card]--;
        player.removeResourceCard("ore", 1);
        player.removeResourceCard("wheat", 1);
        player.removeResourceCard("wool", 1);
        // cout << player.getName() << " bought a " << card << " card." << endl;
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

void CatanGame::distributeResources(int dice) {
    for (auto& player : players) {
        player->getResources(dice, board);
    }
}

void CatanGame::printPlayersStats() {
    cout << endl;
    // print a headline in a nice color that says "~~~~~Players Stats~~~~~~"
cout << "\033[38;5;214mPrinting Players stats: \033[0m\n" << endl;    
for (size_t i = 0; i < players.size(); i++) {
        players[i]->printPlayerInfo();
    }
}

void CatanGame::printPlayersResources() {
    for (size_t i = 0; i < players.size(); i++) {
        players[i]->printResources();
    }
}

void CatanGame::checkLargestArmy() {
    Player* playerWithLargestArmy = nullptr;

    for (auto& player : players) {
        int knightCount = player->getDevelopmentCardAmount("Knight");
        if (knightCount == 3) {
            playerWithLargestArmy = player;
            break;
        }
    }

    if (playerWithLargestArmy != nullptr) {
        for (auto& player : players) {
            if (player == playerWithLargestArmy) {
                if (!player->hasLargestArmy) {
                    player->addVictoryPoints(2);
                    player->hasLargestArmy = true;
                }
            }
        }
        cout << playerWithLargestArmy->getName() << " has the largest army." << endl;
    }
}

void CatanGame::checkEndGame() {
    for (auto& player : players) {
        if (player->getVictoryPoints() >= 10) {
            cout << "WE HAVE A WINNER: " << player->getName() << " REACHED 10 VICTORY POINTS !!" << endl;
            for (auto& player : players) {
                player->printPlayerInfo();
            }
            board.printBoard();
            return;
        }
    }
}

// ONLY USED FOR TESTING.
void CatanGame::giveResources(){
    for (auto& player : players) {
        player->addResourceCard("ore", 5);
        player->addResourceCard("lumber", 5);
        player->addResourceCard("brick", 5);
        player->addResourceCard("wheat", 5);
        player->addResourceCard("wool", 5);
    }
}

}  // namespace Catan