#include <array>
#include <string>

#include "Player.hpp"
#include "roadPlace.hpp"
#include "structurePlace.hpp"

#ifndef TILE_HPP
#define TILE_HPP

using namespace std;

namespace Catan {
class Tile {
   private:
    array<structurePlace*, 6> structurePlaces;
    array<roadPlace*, 6> roadPlaces;
    string resourceType;
    int activationNumber;
    int tileNumber;
    vector<Player*> attachedPlayers;

   public:
    Tile() : resourceType(""), activationNumber(0),tileNumber(0) {}  // Default constructor
    Tile(const string& resourceType,int tileNumber, int activationNumber, array<structurePlace*, 6> structurePlaces, array<roadPlace*, 6> roadPlaces);
    string getResourceType() const;
    void setResourceType(string resourceType);
    int getActivationNumber() const;
    void setActivationNumber(int activationNumber);
    void setResourceAndNumber(string resourceType, int activationNumber);
    array<structurePlace*, 6> getStructurePlaces() const;
    array<roadPlace*, 6> getRoadPlaces() const;
    roadPlace* getRoadPlace(int roadNumber);
    structurePlace* getStructurePlace(int structNumber);
    vector<Player*> getAttachedPlayers() const;
    void addAttachedPlayer(Player* player);
    Tile& operator=(const Tile& other);
    int getTileNumber() const;
};

}  // namespace Catan

#endif  // TILE_HPP