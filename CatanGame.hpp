/* represents catan game:
has the following fields:
int turnNumber - will represent the turn of what player it is. like a counter that count 1,2,3,1,2,3,1,2,3,1,2,3......
hashmap <string,int> resourceCardsLeft (e.g. "wood", 19)
hashmap <string,int> developmentCardsLeft (e.g. "knight", 14)
set of players (e.g. player1, player2, player3)


has the following methods:
void initializeBoard() - will implement the method later.
void startGame() - each player by order of player1 then player2 then player3 will place their initial settlements and roads.

 */

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
    void startGame();
    void startTurn(string playerName);
    void endTurn();
};
}  // namespace Catan

#endif  // CATANGAME_HPP