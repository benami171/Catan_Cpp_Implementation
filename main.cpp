#include <array>
#include <iostream>
#include <string>

#include "Board.hpp"
#include "CatanGame.hpp"
#include "Tile.hpp"

using namespace std;
using namespace Catan;

int main() {
    /*                       THE BOARD
                    mountains -  pasture - forrest
                        10          2         9
                fields  -  hills  -  pasture  -  hills
                  12         6          4          10
        fields  -  forrest  -  desert  -  forrest  -  mountains
            9        11          0           3            8
                forrest  -  mountains  -  fields -  pasture
                   8            3           4          5
                    hills  -  fields  -  pasture
                      5         6          11
    */

    Player _p1("P1");
    Player _p2("P2");
    Player _p3("P3");
    CatanGame game(_p1, _p2, _p3);
    cout << "Board created" << endl;
    Board& board = game.getBoard();

    cout << "Players created" << endl;
    game.startTurn("P1");
    _p1.placeSettlement(2, board);  //  wood,9
    _p1.placeRoad(5, board);
    game.endTurn();
    _p2.placeSettlement(13, board);  // sheep 2, sheep 4, bricks 6
    _p2.placeRoad(13, board);
    game.endTurn();
    _p3.placeSettlement(34, board);  // wood 11, wood 8, ore 3
    _p3.placeRoad(41, board);
    game.endTurn();
    _p1.placeSettlement(25, board);  // bricks 10, ore 8, wood 3
    _p1.placeRoad(31, board);
    game.endTurn();
    _p2.placeSettlement(22, board);  // wheat 12, wheat 9, wood 11
    _p2.placeRoad(24, board);
    game.endTurn();
    _p3.placeSettlement(45, board);  // wheat 4, wheat 6, sheep 11
    _p3.placeRoad(59, board);
    game.endTurn();
    cout << " INITIAL RESOURCES:" << endl;
    _p1.printResources();
    _p2.printResources();
    _p3.printResources();
    cout << " " << endl;
    int dice = _p1.rollDice(6);
    game.distributeResources(dice);
    game.endTurn();
    _p2.rollDice(8);
    game.distributeResources(8);
    game.endTurn();
    _p3.rollDice(9);
    game.distributeResources(9);
    game.endTurn();
    cout << " " << endl;
    _p2.trade({{"brick", 1}, {"lumber", 1}}, {{"wheat", 1}, {"wool", 1}}, _p3);  // should not be allowed, its P1's turn.
    cout << "resourced before valid trade: " << endl;
    _p1.printResources();  // should have [ore, 0] - [wheat, 3] - [lumber, 1] - [wool, 1] - [brick, 0]
    _p3.printResources();  // should have [ore, 2] - [wheat, 0] - [lumber, 2] - [wool, 0] - [brick, 1]
    _p1.trade({{"lumber", 1}, {"brick", 1}}, {{"wheat", 1}, {"wool", 1}}, _p3);
    cout << "resources after valid trade: " << endl;
    _p1.printResources();  // should have [ore, 2] - [wheat, 1] - [lumber, 1] - [wool, 1] - [brick, 0]
    _p3.printResources();  // should have [ore, 0] - [wheat, 2] - [lumber, 2] - [wool, 0] - [brick, 1]
    _p1.buyDevelopmentCard("victoryPoint", game);
    game.endTurn();
    _p2.rollDice(11);
    game.distributeResources(11);
    game.endTurn();
    _p3.rollDice(4);
    game.distributeResources(4);
    game.endTurn();
    game.printPlayersResources();
    _p1.rollDice(8);
    game.distributeResources(8);
    _p1.trade({{"lumber",1}},{{"wheat",1}},_p3);
    game.endTurn();
    _p2.rollDice(6);
    game.distributeResources(6);
    _p2.placeRoad(12, board);
    _p2.placeSettlement(12, board);
    game.printPlayersResources();
    game.endTurn();
    _p3.rollDice(7);
    game.distributeResources(7);
    game.printPlayersResources();
    game.endTurn();
    _p1.rollDice(6);
    game.distributeResources(6);
    game.printPlayersResources();
    _p1.trade({{"ore",1}},{{"wool",1}},_p3);
    _p1.buyDevelopmentCard("yearOfPlenty",game);
    _p1.useYearOfPlenty("brick","lumber",game); // should be able to use a Development card in the same turn he bought it.
    game.endTurn();
    _p2.rollDice(4);
    game.distributeResources(4);
    game.endTurn();
    _p3.rollDice(8);
    game.distributeResources(8);
    game.endTurn();
    _p1.useYearOfPlenty("ore","ore",game); // should be able to use it now.
    game.printBoard();
    // game.printBoard();

    return 0;
}
