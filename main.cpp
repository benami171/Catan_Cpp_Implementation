#include "Tile.hpp" 
#include <array>
#include <string>
#include <iostream>
#include "Board.hpp"
#include "CatanGame.hpp"

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

    cout << "Board created" << endl;
    Player player1("P1");
    Player player2("P2");
    Player player3("P3");
    CatanGame game(player1,player2,player3);
    Board& board = game.getBoard();


    cout << "Players created" << endl;
    player1.placeSettlement(2,board);
    player1.placeRoad(5,board);
    player1.placeSettlement(12,board);
    player1.placeRoad(12,board);
    player1.getInitResources(board);
    player1.printPlayerInfo();


    return 0;
}




//                    OLD MAIN BELOW                      //
// #include "Tile.hpp" 
// #include <array>
// #include <string>
// #include <iostream>
// #include "Board.hpp"

// using namespace std;
// using namespace Catan;

// int main() {

//    Board board = Board();

// /*                       THE BOARD
//                 mountains -  pasture - forrest
//                     10          2         9
//             fields  -  hills  -  pasture  -  hills
//               12         6          4          10
//     fields  -  forrest  -  desert  -  forrest  -  mountains
//         9        11          0           3            8
//             forrest  -  mountains  -  fields -  pasture
//                8            3           4          5
//                 hills  -  fields  -  pasture
//                   5         6          11
// */

//     cout << "Board created" << endl;
//     Player player1("P1");
//     Player player2("P2");
//     Player player3("P3");




//     cout << "Players created" << endl;
//     player1.placeSettlement(2,board);
//     player1.placeRoad(5,board);
//     player1.placeSettlement(12,board);
//     player1.placeRoad(12,board);
//     player1.getInitResources(board);
//     player1.printPlayerInfo();


//     return 0;
// }