#include "roadPlace.hpp"

#include "Player.hpp"
#include "structurePlace.hpp"

using namespace std;
using namespace Catan;

roadPlace::roadPlace() : owner(nullptr), roadNumber(0) {}

roadPlace::roadPlace(Player* owner, int roadNumber) : owner(owner), roadNumber(roadNumber) {}

// Method to get owner
string roadPlace::getOwnerString() {
    if (owner == nullptr) {
        return "initial";
    } else {
        return owner->getName();
    }
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
Player* roadPlace::getRoadOwner() {
    return owner;
}

void roadPlace::setOwner(Player* newOwner) {
    owner = newOwner;
}

bool roadPlace::placedRoad(Player* newOwner) {
    // road already taken.
    if (this->owner != nullptr) {
        cout << "Road in index " << roadNumber << " already has an owner\n";
        return false;
    }

    // road not taken, check if adjacent structures are owned by the same player
    // cout << " check if adjStructs[0]'s owner: " << adjStructs[0]->getOwnerString() << " is the same as newOwner: " << newOwner->getName() << "\n";
    if (adjStructs[0]->getOwnerString() == newOwner->getName()) {
        this->setOwner(newOwner);
        return true;
    }
    // cout << " check if adjStructs[1]'s owner: " << adjStructs[0]->getOwnerString() << " is the same as newOwner: " << newOwner->getName() << "\n";
    if (adjStructs[1]->getOwnerString() == newOwner->getName()) {
        this->setOwner(newOwner);
        return true;
    }

    // road not taken, adjacent structures are not owned by the same player
    // check if adjacent roads are owned by the same player.
    // cout << " check if adjStructs[0]'s owner: " << adjRoads[0]->getOwnerString() << " == initial\n";
    if (adjStructs[0]->getOwnerString() == "initial") {
        // roads in places 0,1 are adjacent to structure in place 0
        // cout << " check if adjRoads[0]'s owner: " << adjRoads[0]->getOwnerString() << " == " << newOwner->getName() << "\n";
        if (adjRoads[0] != nullptr && adjRoads[0]->getOwnerString() == newOwner->getName()) {
            this->setOwner(newOwner);
            return true;
        }
        // cout << " check if adjRoads[1]'s owner: " << adjRoads[1]->getOwnerString() << " == " << newOwner->getName() << "\n";

        if (adjRoads[1] != nullptr && adjRoads[1]->getOwnerString() == newOwner->getName()) {
            this->setOwner(newOwner);
            return true;
        }
    }
    // cout << " check if adjStructs[1]'s owner: " << adjRoads[1]->getOwnerString() << " == initial\n";
    if (adjStructs[1]->getOwnerString() == "initial") {
        // roads in places 2,3 are adjacent to structure in place 1
        // cout << " check if adjRoads[2]'s owner: " << adjRoads[2]->getOwnerString() << " == " << newOwner->getName() << "\n";
        if (adjRoads[2] != nullptr && adjRoads[2]->getOwnerString() == newOwner->getName()) {
            this->setOwner(newOwner);
            return true;
        }
        // cout << " check if adjRoads[3]'s owner: " << adjRoads[3]->getOwnerString() << " == " << newOwner->getName() << "\n";
        if (adjRoads[3] != nullptr && adjRoads[3]->getOwnerString() == newOwner->getName()) {
            this->setOwner(newOwner);
            return true;
        }
    }
    return false;
}

bool roadPlace::canPlaceRoad(Player* newOwner) {
    if (this->owner != nullptr) {
        return false;
    }

    if (adjStructs[0]->getOwnerString() == newOwner->getName()) {
        return true;
    }
    if (adjStructs[1]->getOwnerString() == newOwner->getName()) {
        return true;
    }

    if (adjStructs[0]->getOwnerString() == "") {
        if (adjRoads[0] != nullptr && adjRoads[0]->getOwnerString() == newOwner->getName()) {
            return true;
        }
        if (adjRoads[1] != nullptr && adjRoads[1]->getOwnerString() == newOwner->getName()) {
            return true;
        }
    }
    if (adjStructs[1]->getOwnerString() == "") {
        if (adjRoads[2] != nullptr && adjRoads[2]->getOwnerString() == newOwner->getName()) {
            return true;
        }
        if (adjRoads[3] != nullptr && adjRoads[3]->getOwnerString() == newOwner->getName()) {
            return true;
        }
    }
    return false;
}

int roadPlace::getRoadNumber() {
    return roadNumber;
}

string roadPlace::getPrintableString() {
    if (owner == nullptr) {
        return "\033[1;37m";
    }
    return owner->getPlayerColor();
}