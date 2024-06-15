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
    int dice = _p1.rollDice(6);
    _p1.getResources(dice, board);  // shouldn't get any resources
    _p2.getResources(dice, board);  // should get 1 brick
    _p3.getResources(dice, board);  // should get 1 wheat
    game.endTurn();
    _p1.printResources();  // should have 1 brick, 1 ore, 1 lumber.
    _p2.printResources();  // should have 2 wheat, 1 lumber, 1 brick.
    _p3.printResources();  // should have 3 wheat, 1 wool.
    _p2.rollDice(8);

    _p1.getResources(dice, board);
    _p2.getResources(dice, board);
    _p3.getResources(dice, board);
    game.endTurn();
    _p3.rollDice(9);
    _p1.getResources(dice, board);
    _p2.getResources(dice, board);
    _p3.getResources(dice, board);
    game.endTurn();
    cout << " " << endl;
    // _p2.printResources();
    unordered_map<string, int> giveResources = {{"brick", 1}, {"lumber", 1}};
    unordered_map<string, int> receiveResources = {{"wheat", 1}, {"wool", 1}};
    _p2.trade({{"brick", 1}, {"lumber", 1}}, {{"wheat", 1}, {"wool", 1}}, _p3);  // should not be allowed, its P1's turn.
    _p1.printResources(); // should have [ore, 1] - [wheat, 0] - [lumber, 1] - [wool, 0] - [brick, 1]
    _p2.printResources();
    _p1.trade({{"lumber",1},{"brick",1}}, {{"wheat",1},{"wool",1}}, _p3);  
    _p1.printResources(); // should have [ore, 1] - [wheat, 1] - [lumber, 0] - [wool, 1] - [brick, 0]
    _p2.printResources();
    //game.printBoard();

    return 0;
}
