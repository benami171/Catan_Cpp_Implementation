#include "Tile.hpp"
#include <string>
#include <array>



using namespace std;
using namespace Catan;

Tile::Tile(const string& resourceType, int activationNumber, array<structurePlace,6> structurePlaces, array<roadPlace,6> roadPlaces)
    : resourceType(resourceType), activationNumber(activationNumber) {
        for (int i = 0; i < 6; i++) {
            this->structurePlaces[i] = structurePlaces[i];
            this->roadPlaces[i] = roadPlaces[i];
        }
    }
