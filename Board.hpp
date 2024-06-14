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
   
    vector<structurePlace> structurePlaces;
    vector<roadPlace> roadPlaces;
    vector<Tile> tiles;
    vector<string> landTypes;
    void initStructurePlaces();
    void initRoadPlaces();
    void setupAdjacencies();
    void initTiles();

   public:

    // the constructor of the Board class uses the following methods to initialize the board:
    // initStructurePlaces() - initializes the structurePlaces vector with 54 structurePlaces
    // initRoadPlaces() - initializes the roadPlaces vector with 72 roadPlaces
    // initTiles() - initializes the tiles vector with 19 tiles
    // setupAdjacencies() - sets up the adjacencies of the structurePlaces and roadPlaces

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

#endif  // BOARD_HPP