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

#include <set>
#include <string>
#include <unordered_map>

#include "Player.hpp"
#ifndef CATANGAME_HPP
#define CATANGAME_HPP

using namespace std;

namespace Catan {

class CatanGame {
   public:
    // fields //
    int turnNumber;
    unordered_map<string, int> resourceCardsLeft;
    unordered_map<string, int> developmentCardsLeft;
    set<Player> players;

    // methods //
    CatanGame();
    void initializeBoard();
    void startGame();
};
}  // namespace Catan

#endif  // CATANGAME_HPP