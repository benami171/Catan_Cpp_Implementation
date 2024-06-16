#include "structurePlace.hpp"
#include "Player.hpp"
#include "Tile.hpp"
#include "roadPlace.hpp"

using namespace std;
using namespace Catan;

class Player;

structurePlace::structurePlace() 
    : owner(nullptr), structNumber(0), adjStructs{nullptr, nullptr, nullptr}, adjRoads{nullptr, nullptr, nullptr}  {
}

structurePlace::structurePlace(Player* owner, string structType, int structNumber) 
    : owner(owner), structType(structType), structNumber(structNumber), adjStructs{nullptr, nullptr, nullptr}, adjRoads{nullptr, nullptr, nullptr}{
}


string structurePlace::getOwnerString() {
    if (owner == nullptr) {
        return "initial";
    }
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
    if (newOwner == nullptr) {
        cout << "New owner is null" << endl;
        return false;
    }
    if (this->owner != nullptr) {
        cout << "Owner is not null" << endl;
        return false;
    }

    for (size_t index = 0; index < adjStructs.size(); index++) {
        if (adjStructs[index] != nullptr && adjStructs[index]->getOwnerString() != "initial") {
            return false;
        }
    }

    // the adjecent settLments are not owned by anyone.
    // check if at least one of the adjacent roads is owned by the player.
    for (size_t index = 0; index < adjRoads.size(); index++) {
        if (adjRoads[index] != nullptr && adjRoads[index]->getOwnerString() == newOwner->getName()) {
            this->owner = newOwner;
            this->structType = "SETTLEMENT";
            for ( size_t j = 0 ; j < adjTiles.size() ; j++) {
                if (adjTiles.at(j) != nullptr) {
                    adjTiles.at(j)->addAttachedPlayer(newOwner);
                }
            }
            cout << "can place settlement" << endl;
            return true;
        }
    }
    cout << "Could not place settlement" << endl;
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

    for (size_t index = 0; index < adjStructs.size(); index++) {
        if (adjStructs[index] != nullptr && adjStructs[index]->getOwnerString() != "initial") {
            cout << "Could not place initial settlement, adjacent structure has an owner" << endl;
            return false;
        }
    }

    // the adjecent settLments are not owned by anyone.
    // check if at least one of the adjacent roads is owned by the player.
    for (size_t index = 0; index < adjRoads.size(); index++) {
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
        cout << "Owner is null or owner is not the same as new owner" << endl;
        return false;
    }

    if (this->structType == "SETTLEMENT") {
        this->structType = "CITY";
        return true;
    }
    cout << "Could not place city" << endl;
    return false;
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
        return "O\033[0m";
    }
    string playerPrintableString = owner->getPlayerColor();
    if (structType == "SETTLEMENT") {
        return playerPrintableString + "S\033[0m";
    }
    return playerPrintableString + "C\033[0m";
}
