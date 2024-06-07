#include "structurePlace.hpp"
#include "Tile.hpp"

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
    for (auto& ptr : adjTiles) {
        ptr = nullptr;
    }
    attachedResources = {};
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

bool structurePlace::placedSettlement(Player* newOwner) {
    // place already taken.
    if (this->owner != nullptr) {
        return false;
    }

    for (int i = 0; i < adjStructs.size(); i++) {
        if (adjStructs[i] != nullptr && adjStructs[i]->getOwnerString() != "") {
            return false;
        }
    }

    // the adjecent settLments are not owned by anyone.
    // check if at least one of the adjacent roads is owned by the player.
    for (int i = 0; i < adjRoads.size(); i++) {
        if (adjRoads[i] != nullptr && adjRoads[i]->getOwnerString() == newOwner->getName()) {
            this->owner = newOwner;
            this->structType = "SETTLEMENT";
            for ( int j = 0 ; j < 3 ; j++) {
                if (adjTiles.at(j) != nullptr) {
                    adjTiles.at(j)->addAttachedPlayer(newOwner);
                }
            }
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

void structurePlace::addResource(string resource) {
    attachedResources.insert(resource);
}

void structurePlace::addAdjTile(Tile* tile) {
    adjTiles.push_back(tile);
}
