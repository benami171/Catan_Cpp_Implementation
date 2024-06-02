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

   public:
    Board();
    void printBoard();
};
}  // namespace Catan

#endif  // BOARD_HPP