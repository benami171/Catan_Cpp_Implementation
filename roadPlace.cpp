#include "roadPlace.hpp"

#include <string.h>

#include <array>
#include <iostream>
#include <set>
#include <unordered_map>

#include "Catan_Piece.hpp"
#include "Player.hpp"

using namespace std;
using namespace Catan;

roadPlace::roadPlace(string owner = "", int roadNumber = 0) {
    this->owner = owner;
    this->roadNumber = roadNumber;
}

// Method to get owner
string roadPlace::getOwner() {
    return owner;
}

// Method to set adjacent structures
void roadPlace::setAdjStructs(array<structurePlace*, 2> adjStructs) {
    this->adjStructs = adjStructs;
}

// Method to set adjacent roads
void roadPlace::setAdjRoads(array<roadPlace*, 4> adjRoads) {
    this->adjRoads = adjRoads;
}
