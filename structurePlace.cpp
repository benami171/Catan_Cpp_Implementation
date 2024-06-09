#include "structurePlace.hpp"
#include "Tile.hpp"

using namespace std;
using namespace Catan;

class Player;

structurePlace::structurePlace() 
    : owner(nullptr), structType(""), structNumber(0), adjStructs{nullptr, nullptr, nullptr}, adjRoads{nullptr, nullptr, nullptr}, adjTiles(3, nullptr) {
    cout << "Default structurePlace created: " << structNumber << ", structType: " << this->structType << ", adjStructs and adjRoads initialized to nullptr." << endl;
    cout << "Default structurePlace created: " << structNumber << ", adjTiles size: " << adjTiles.size() << endl;
}

structurePlace::structurePlace(Player* owner, string structType, int structNumber) 
    : owner(owner), structType(structType), structNumber(structNumber), adjStructs{nullptr, nullptr, nullptr}, adjRoads{nullptr, nullptr, nullptr}, adjTiles(3, nullptr) {
// cout << "structurePlace created: " << structNumber << ", structType: " << this->structType << ", adjStructs and adjRoads initialized to nullptr." << endl;
// cout << "structurePlace created: " << structNumber << ", adjTiles size: " << adjTiles.size() << endl;
}

// Deep copy constructor
structurePlace::structurePlace(const structurePlace& other)
    : owner(other.owner), structType(other.structType), structNumber(other.structNumber) {
    adjStructs = other.adjStructs;
    adjRoads = other.adjRoads;
}

string structurePlace::getOwnerString() {
    if (owner == nullptr) {
        return "No owner";
    } else {
        return owner->getName();
    }
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
    if (newOwner == nullptr) {
        cout << "New owner is null" << endl;
        return false;
    }
    if (this->owner != nullptr) {
        cout << "Owner is not null" << endl;
        return false;
    }

    for (size_t i = 0; i < adjStructs.size(); i++) {
        if (adjStructs[i] != nullptr && adjStructs[i]->getOwnerString() != "No owner") {
            cout << "Adjacent structure is not null and has an owner" << endl;
            cout << "Owner of adjacent structure: " << adjStructs[i]->getOwnerString() << endl;
            return false;
        }
    }

    // the adjecent settLments are not owned by anyone.
    // check if at least one of the adjacent roads is owned by the player.
    for (size_t i = 0; i < adjRoads.size(); i++) {
        cout << "adjRoads[i] Owner: " << adjRoads[i]->getOwnerString() << endl; // FOR DEBUGGING
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

bool structurePlace::placedInitialSettlement(Player* newOwner){
// place already taken.
    if (newOwner == nullptr) {
        cout << "New owner is null" << endl;
        return false;
    }
    if (this->owner != nullptr) {
        cout << "Owner is not null" << endl;
        return false;
    }

    for (size_t i = 0; i < adjStructs.size(); i++) {
        if (adjStructs[i] != nullptr && adjStructs[i]->getOwnerString() != "No owner") {
            cout << "Adjacent structure is not null and has an owner" << endl;
            cout << "Owner of adjacent structure: " << adjStructs[i]->getOwnerString() << endl;
            return false;
        }
    }

    // the adjecent settLments are not owned by anyone.
    // check if at least one of the adjacent roads is owned by the player.
    for (size_t i = 0; i < adjRoads.size(); i++) {
            this->owner = newOwner;
            this->structType = "SETTLEMENT";
            for ( int j = 0 ; j < 3 ; j++) {
                if (adjTiles.at(j) != nullptr) {
                    cout << "Adding attached player to tile" << endl;
                    adjTiles.at(j)->addAttachedPlayer(newOwner);
                }
            }
            return true;

    }
    return false;

}

bool structurePlace::placedCity(Player* newOwner) {
    if (this->owner == nullptr || this->owner->getName() != newOwner->getName()) {
        return false;
    }

    if (this->structType == "SETTLEMENT") {
        this->structType = "CITY";
        return true;
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
        return playerColor + "S\033[0m"; // after the color code, the color is reset back to default
    } else {
        return playerColor + "C\033[0m";
    }
}

void structurePlace::addResource(string resource) {
    attachedResources.insert(resource);
}

void structurePlace::addAdjTile(Tile* tile) {
    adjTiles.push_back(tile);
}

const vector<Tile*>& structurePlace::getAdjTiles() const {
    return adjTiles;
}