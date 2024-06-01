#include "structurePlace.hpp"

#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace Catan;

// Default constructor
structurePlace::structurePlace() : owner(""), structType(""), structNumber(0) {}

structurePlace::structurePlace(string owner, string structType, int structNumber) {
    this->owner = owner;
    this->structType = structType;
    this->structNumber = structNumber;
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

void structurePlace::setAdjRoads(array<roadPlace*, 9> adjRoads) {
    this->adjRoads = adjRoads;
}

bool structurePlace::validSettlementPlacement(string newOwner) {
    if (this->owner != "") {
        return false;
    }
    for (int i = 0; i < adjStructs.size(); i++) {
        if (adjStructs[i]->getOwner() != "") {
            return false;
        }
    }
    for (int i = 0; i < adjRoads.size(); i++) {
        if (adjRoads[i]->getOwner() == newOwner) {
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
