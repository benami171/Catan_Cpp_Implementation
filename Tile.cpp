#include "Tile.hpp"
#include "Player.hpp"
#include "roadPlace.hpp"
#include "structurePlace.hpp"

using namespace std;
using namespace Catan;


Tile::Tile(const string& resourceType,int tileNumber, int activationNumber, vector<structurePlace*> structurePlaces, vector<roadPlace*> roadPlaces)
    : structurePlaces(6), roadPlaces(6), resourceType(resourceType), activationNumber(activationNumber) {
    for (size_t index = 0; index < structurePlaces.size(); index++) {
        this->structurePlaces[index] = structurePlaces[index];
        this->roadPlaces[index] = roadPlaces[index];
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