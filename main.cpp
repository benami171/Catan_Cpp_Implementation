#include "Tile.hpp" 
#include <array>
#include <string>
#include <iostream>
#include "Board.hpp"

using namespace std;
using namespace Catan;

int main() {

   Board board = Board();

    cout << "Board created" << endl;
    Player player1("Player 1");
    Player player2("Player 2");
    Player player3("Player 3");


    cout << "Players created" << endl;
    structurePlace structurePlace2 = board.getStructurePlaces()[2];
    cout << "HOO" << endl;
    int size = structurePlace2.getAdjTiles().size();
    cout << "Size of adjecent tiles: " << size << endl;
    Tile* tile1 = structurePlace2.getAdjTiles()[0];
    cout << " HEEE" << endl;
    cout << " structurePlace 2 adjecent Tiles are: " << tile1->getTileNumber() << endl;
    player1.placeSettlement(2,board);
    player1.placeRoad(5,board);
    player1.placeSettlement(12,board);
    player1.placeRoad(12,board);
    player1.getInitResources(board);
    player1.printResources();
    return 0;
}