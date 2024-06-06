#include "structurePlace.hpp"

#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace Catan;


structurePlace::structurePlace(string owner="", string structType="N", int structNumber=0) 
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

string structurePlace::getOwner() {
    return owner;
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

bool structurePlace::validSettlementPlacement(string newOwner) {
    if (this->owner != "") {
        return false;
    }
    for (int i = 0; i < adjStructs.size(); i++) {
        if (adjStructs[i] != nullptr && adjStructs[i]->getOwner() != "") {
            return false;
        }
    }
    for (int i = 0; i < adjRoads.size(); i++) {
        if (adjRoads[i] != nullptr && adjRoads[i]->getOwner() == newOwner) {
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
    if(owner == "") {
        return "N";
    }

    string playerColor = owner.

    if (structType == "SETTLEMENT") {
        return "S";
    } else if (structType == "CITY") {
        return "C";
    } else {
        return "N";
    }
}

string structurePlace::getColor() {
    if (owner == "Player1") {
        return "\033[1;31m"; // Red
    } else if (owner == "Player2") {
        return "\033[1;34m"; // Blue
    } else if (owner == "Player3") {
        return "\033[1;32m"; // Green
    } else {
        return "\033[0m"; 
    }
}
