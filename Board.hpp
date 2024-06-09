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
    void initStructurePlaces();
    void initRoadPlaces();
    void setupAdjacencies();
    void initTiles();

   public:
    Board();
    roadPlace* getRoadAt(int roadNumber); // returns the ith roadPlace in the roadPlaces array
    structurePlace* getStructureAt(int structNumber); // returns the ith structurePlace in the structurePlaces array
    Tile* getTileAt(int tileNumber); // returns the ith tile in the tiles array
    const array<structurePlace, 54>& getStructurePlaces() const;
    const array<roadPlace, 72>& getRoadPlaces() const;
    const array<Tile, 19>& getTiles() const; 

};
}  // namespace Catan

#endif  // BOARD_HPP