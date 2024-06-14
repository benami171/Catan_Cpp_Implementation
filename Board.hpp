#pragma once

#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include "Tile.hpp"
#include "roadPlace.hpp"
#include "structurePlace.hpp"

using namespace std;

namespace Catan {


class Board {
   private:
   
    vector<structurePlace> structurePlaces;
    vector<roadPlace> roadPlaces;
    vector<Tile> tiles;
    vector<string> landTypes;
    void initStructurePlaces();
    void initRoadPlaces();
    void setupAdjacencies();
    void initTiles();

   public:
    Board();
    roadPlace* getRoadAt(int roadNumber); // returns the ith roadPlace in the roadPlaces array
    structurePlace* getStructureAt(int structNumber); // returns the ith structurePlace in the structurePlaces array
    Tile* getTileAt(int tileNumber); // returns the ith tile in the tiles array
    const vector<structurePlace>& getStructurePlaces() const;
    const vector<roadPlace>& getRoadPlaces() const;
    const vector<Tile>& getTiles() const; 
    void printBoard(); // prints the board

};
}  // namespace Catan

