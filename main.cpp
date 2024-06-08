#include "Tile.hpp" 
#include <array>
#include <string>
#include <iostream>
#include "Board.hpp"

using namespace std;
using namespace Catan;

int main() {
   Catan::Board board;
    cout << "Board created" << endl;
    Player player1("Player 1");
    Player player2("Player 2");
    Player player3("Player 3");
    cout << "Players created" << endl;
    player1.placeInitialSettlement(2,board);
    player1.placeInitialRoad(5,board);



    
    

    return 0;
}