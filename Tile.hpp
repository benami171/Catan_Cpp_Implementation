#pragma once

#include <array>
#include <string>
#include <vector>
#include "Player.hpp"
#include "roadPlace.hpp"
#include "structurePlace.hpp"

using namespace std;

namespace Catan {
class Tile {
   private:
    vector<structurePlace*> structurePlaces;
    vector<roadPlace*> roadPlaces;
    string resourceType;
    int activationNumber;
    int tileNumber;
    vector<Player*> attachedPlayers;

   public:
    Tile() : resourceType(""), activationNumber(0),tileNumber(0) {}  // Default constructor
    Tile(const string& resourceType,int tileNumber, int activationNumber, vector<structurePlace*> structurePlaces, vector<roadPlace*> roadPlaces);
    string getResourceType() const;
    void setResourceType(string resourceType);
    int getActivationNumber() const;
    void setActivationNumber(int activationNumber);
    void setResourceAndNumber(string resourceType, int activationNumber);
    vector<structurePlace*> getStructurePlaces() const;
    vector<roadPlace*> getRoadPlaces() const;
    roadPlace* getRoadPlace(int roadNumber);
    structurePlace* getStructurePlace(int structNumber);
    vector<Player*> getAttachedPlayers() const;
    void addAttachedPlayer(Player* player);
    Tile& operator=(const Tile& other);
    int getTileNumber() const;
};

}  // namespace Catan

