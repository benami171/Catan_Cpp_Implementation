#include <string.h>
#include <iostream>
#include <set>
#include <unordered_map>
#include <array>
#include "CatanPiece.hpp"
#include "Player.hpp"

using namespace std;

namespace Catan {
    class structurePlace; // Forward declaration of structurePlace

    class roadPlace {
    private:
        string owner;
        array<structurePlace*, 2> adjStructs; // Use pointers to structurePlace
        array<roadPlace*, 3> adjRoads; // Use pointers to roadPlace

    public:
        roadPlace(string owner) {
            this->owner = owner;
        }

        string getOwner() {
            return owner;
        }

        void setAdjStructs(array<structurePlace*, 2> adjStructs) {
            this->adjStructs = adjStructs;
        }

        void setAdjRoads(array<roadPlace*, 3> adjRoads) {
            this->adjRoads = adjRoads;
        }
    };
}