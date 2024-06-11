#include "Tile.hpp"

#include <array>
#include <string>

using namespace std;
using namespace Catan;

enum class ResourceType {
    WOOD,
    BRICK,
    SHEEP,
    WHEAT,
    ORE,
    DESERT
};

Tile::Tile(const string& resourceType,int tileNumber, int activationNumber, vector<structurePlace*> structurePlaces, vector<roadPlace*> roadPlaces)
    : structurePlaces(6), roadPlaces(6), resourceType(resourceType), activationNumber(activationNumber) {
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

vector<structurePlace*> Tile::getStructurePlaces() const {
    return structurePlaces;
}

vector<roadPlace*> Tile::getRoadPlaces() const {
    return roadPlaces;
}

vector<Player*> Tile::getAttachedPlayers() const {
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

void Tile::addAttachedPlayer(Player* player) {
    this->attachedPlayers.push_back(player);
}

roadPlace* Tile::getRoadPlace(int roadNumber) {
    return roadPlaces[roadNumber];
}

structurePlace* Tile::getStructurePlace(int structNumber) {
    return structurePlaces[structNumber];
}

int Tile::getTileNumber() const {
    return tileNumber;
}