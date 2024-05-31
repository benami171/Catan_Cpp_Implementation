#include <string.h>

#include <iostream>
#include <set>
#include <unordered_map>
#include <array>
#include "CatanPiece.hpp"
#include "Player.hpp"
#include "structurePlace.hpp"


using namespace std;

namespace Catan {
class roadPlace {
   private:
    string owner;
    array<structurePlace, 2> adjStructs;
    array<roadPlace, 3> adjRoads;

   public:
    roadPlace(string owner) {
        this->owner = owner;
    }

    string getOwner() {
        return owner;
    }

    void setAdjStructs(array<structurePlace, 2> adjStructs) {
        this->adjStructs = adjStructs;
    }

    void setAdjRoads(array<roadPlace, 3> adjRoads) {
        this->adjRoads = adjRoads;
    }
};

}  // namespace Catan