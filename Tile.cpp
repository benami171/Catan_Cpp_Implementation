#include "Tile.hpp"

#include <array>
#include <string>

using namespace std;
using namespace Catan;

Tile::Tile(const string& resourceType, int activationNumber, array<structurePlace*, 6> structurePlaces, array<roadPlace*, 6> roadPlaces)
    : resourceType(resourceType), activationNumber(activationNumber) {
    for (int i = 0; i < 6; i++) {
        this->structurePlaces[i] = structurePlaces[i];
        this->roadPlaces[i] = roadPlaces[i];
    }
}

string Tile::getResourceType() const {
    return resourceType;
}

void Tile::setResourceType(string resourceType) {
    this->resourceType = resourceType;
}

int Tile::getActivationNumber() const {
    return activationNumber;
}

void Tile::setActivationNumber(int activationNumber) {
    this->activationNumber = activationNumber;
}

void Tile::setResourceAndNumber(string resourceType, int activationNumber) {
    this->resourceType = resourceType;
    this->activationNumber = activationNumber;
}

array<structurePlace*, 6> Tile::getStructurePlaces() const {
    return structurePlaces;
}

array<roadPlace*, 6> Tile::getRoadPlaces() const {
    return roadPlaces;
}

array<Player*, 3> Tile::getAttachedPlayers() const {
    return attachedPlayers;
}

Tile& Tile::operator=(const Tile& other) {
    if (this == &other) {
        return *this;
    }

    resourceType = other.resourceType;
    activationNumber = other.activationNumber;
    structurePlaces = other.structurePlaces;
    roadPlaces = other.roadPlaces;
    attachedPlayers = other.attachedPlayers;

    return *this;
}