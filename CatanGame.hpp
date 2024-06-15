#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include "Board.hpp"


using namespace std;

namespace Catan {

class Player;

class CatanGame {
   private:
    int turnCounter;
    string currentPlayerTurn;
    vector<Player*> players;
    Board board;

    public:
    CatanGame(Player& player1, Player& player2, Player& player3);

    unordered_map<string, int> resourceCardsLeft;
    unordered_map<string, int> developmentCardsLeft;
    Board& getBoard();
    vector<Player*>& getPlayers();
    bool buyDevelopmentCard(string card, Player& player);
    int getTurnCounter();
    string getCurrentPlayerTurn();
    int developmentCardsRemaining(string card);
    void printBoard();
    void startGame();
    void startTurn(string playerName);
    void printPlayersStats();
    void checkLargestArmy();
    void endTurn();
    void checkEndGame();
};
}  // namespace Catan

