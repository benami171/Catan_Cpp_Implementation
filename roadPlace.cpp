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

roadPlace::roadPlace() {
    this->owner = nullptr;
    this->roadNumber = 0;
}

roadPlace::roadPlace(Player* owner = nullptr, int roadNumber = 0) {
    this->owner = owner;
    this->roadNumber = roadNumber;
}

// Method to get owner
string roadPlace::getOwnerString() {
    return owner->getName();
}

// Method to set adjacent structures
void roadPlace::setAdjStructs(array<structurePlace*, 2> adjStructs) {
    this->adjStructs = adjStructs;
}

// Method to set adjacent roads
void roadPlace::setAdjRoads(array<roadPlace*, 4> adjRoads) {
    this->adjRoads = adjRoads;
}

// Method to get owner
Player* roadPlace::getOwner() {
    return owner;
}

void roadPlace::setOwner(Player* newOwner) {
    owner = newOwner;
}

