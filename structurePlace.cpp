#include "structurePlace.hpp"

using namespace std;
using namespace Catan;

class Player;

structurePlace::structurePlace(Player* owner=nullptr, string structType="N", int structNumber=0) 
    : owner(owner), structType(structType), structNumber(structNumber) {
    for (auto& ptr : adjStructs) { // Initialize all pointers to nullptr
        ptr = nullptr;
    }
    for (auto& ptr : adjRoads) {
        ptr = nullptr;
    }
}

// Deep copy constructor
structurePlace::structurePlace(const structurePlace& other)
    : owner(other.owner), structType(other.structType), structNumber(other.structNumber) {
    adjStructs = other.adjStructs;
    adjRoads = other.adjRoads;
}

string structurePlace::getOwnerString() {
    return owner->getName();
}

string structurePlace::getStructType() {
    return structType;
}

int structurePlace::getStructNumber() {
    return structNumber;
}

void structurePlace::setAdjStructs(array<structurePlace*, 3> adjStructs) {
    this->adjStructs = adjStructs;
}

void structurePlace::setAdjRoads(array<roadPlace*, 3> adjRoads) {
    this->adjRoads = adjRoads;
}

bool structurePlace::validSettlementPlacement(Player* newOwner) {
    if (this->owner != nullptr) {
        return false;
    }
    for (int i = 0; i < adjStructs.size(); i++) {
        if (adjStructs[i] != nullptr && adjStructs[i]->getOwnerString() != "") {
            return false;
        }
    }
    for (int i = 0; i < adjRoads.size(); i++) {
        if (adjRoads[i] != nullptr && adjRoads[i]->getOwnerString() == newOwner->getName()) {
            return true;
        }
    }
    return false;
}

structurePlace& structurePlace::operator=(const structurePlace& other) {
    if (this != &other) {
        owner = other.owner;
        structType = other.structType;
        structNumber = other.structNumber;
        adjStructs = other.adjStructs;
        adjRoads = other.adjRoads;
    }
    return *this;
}

string structurePlace::getIdentifierString() {
    if(owner->getName() == "") {
        return "N";
    }

    string playerColor = owner->getPlayerColor();
    if (structType == "SETTLEMENT") {
        return playerColor + "S\033[0m" + "\033[0m";
    } else {
        return playerColor + "C\033[0m" + "\033[0m";
    }
}
