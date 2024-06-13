
#include <vector>
#include <string>
#include <unordered_map>
#include "Board.hpp"
#include "Player.hpp"
#ifndef CATANGAME_HPP
#define CATANGAME_HPP

using namespace std;

namespace Catan {

class Player;

class CatanGame {
   private:
    int turnCounter;
    string currentPlayerTurn;
    vector<Player*> players;
    Board board;

    void initializeBoard();

    public:
    CatanGame(Player& player1, Player& player2, Player& player3);

    unordered_map<string, int> resourceCardsLeft;
    unordered_map<string, int> developmentCardsLeft;
    Board& getBoard();
    bool buyDevelopmentCard(string card, Player& player);
    int getTurnCounter();
    void startGame();
    void startTurn(string playerName);
    void endTurn();
};
}  // namespace Catan

#endif  // CATANGAME_HPP