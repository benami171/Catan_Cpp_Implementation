#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include "Tile.hpp"
#include "roadPlace.hpp"
#include "structurePlace.hpp"

#ifndef BOARD_HPP
#define BOARD_HPP

using namespace std;

namespace Catan {
class Board {
   private:
    array<structurePlace, 54> structurePlaces;
    array<roadPlace, 72> roadPlaces;
    array<Tile, 19> tiles;
    array<string,19> landTypes;
    array<int,19> activationNumbers;
    void initBoard();
    void initTiles();
    void initStructurePlaces();
    void initRoadPlaces();
    void setupAdjacencies();


   public:
    Board();
    roadPlace* getRoadPlace(int roadNumber); // returns the ith roadPlace in the roadPlaces array
    structurePlace* getStructurePlace(int structNumber); // returns the ith structurePlace in the structurePlaces array
    void printBoard();

};
}  // namespace Catan

#endif  // BOARD_HPP