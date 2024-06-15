#include "structurePlace.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include "roadPlace.hpp"

using namespace std;
using namespace Catan;

class Player;

structurePlace::structurePlace() 
    : owner(nullptr), structType(""), structNumber(0), adjStructs{nullptr, nullptr, nullptr}, adjRoads{nullptr, nullptr, nullptr}, adjTiles(), attachedResources(), activationNumbers() {
}

structurePlace::structurePlace(Player* owner, string structType, int structNumber) 
    : owner(owner), structType(structType), structNumber(structNumber), adjStructs{nullptr, nullptr, nullptr}, adjRoads{nullptr, nullptr, nullptr}, adjTiles(), attachedResources(), activationNumbers(){
}

// // Deep copy constructor
// structurePlace::structurePlace(const structurePlace& other)
//     : owner(other.owner), structType(other.structType), structNumber(other.structNumber) {
//     adjStructs = other.adjStructs;
//     adjRoads = other.adjRoads;
// }

string structurePlace::getOwnerString() {
    if (owner == nullptr) {
        return "initial";
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
        if (adjStructs[i] != nullptr && adjStructs[i]->getOwnerString() != "initial") {
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
        if (adjStructs[i] != nullptr && adjStructs[i]->getOwnerString() != "initial") {
            cout << "Could not place initial settlement, adjacent structure has an owner" << endl;
            return false;
        }
    }

    // the adjecent settLments are not owned by anyone.
    // check if at least one of the adjacent roads is owned by the player.
    for (size_t i = 0; i < adjRoads.size(); i++) {
            this->owner = newOwner;
            this->structType = "SETTLEMENT";
            for ( size_t j = 0 ; j < adjTiles.size() ; j++) {
                if (adjTiles.at(j) != nullptr) {
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

// structurePlace& structurePlace::operator=(const structurePlace& other) {
//     if (this != &other) {
//         owner = other.owner;
//         structType = other.structType;
//         structNumber = other.structNumber;
//         adjStructs = other.adjStructs;
//         adjRoads = other.adjRoads;
//     }
//     return *this;
// }


void structurePlace::addResource(string resource) {
    attachedResources.insert(resource);
}

void structurePlace::addActivationNumber(int activationNumber) {
    activationNumbers.insert(activationNumber);
}

void structurePlace::addAdjTile(Tile* tile) {
    adjTiles.push_back(tile);
}

void structurePlace::addResourceAndActivationNumber(const string& resource, int activationNumber) {
    resource_activationNumber.push_back(make_pair(resource, activationNumber));
}

const vector<pair<string, int>>& structurePlace::getResourceActivationNumber() const {
    return resource_activationNumber;
}

const vector<Tile*>& structurePlace::getAdjTiles() const {
    return adjTiles;
}

string structurePlace::getPrintableString(){
    if  (owner == nullptr) {
        return "O";
    }
    string playerPrintableString = owner->getPlayerColor();
    if (structType == "SETTLEMENT") {
        return playerPrintableString + "S\033[0m";
    } else {
        return playerPrintableString + "C\033[0m";
    }
}

// TODO - DELETE THIS VERSION OF THE ABOVE FUNCTION.
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