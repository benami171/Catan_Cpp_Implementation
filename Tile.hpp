#include <string>
#include <array>
#include "Player.hpp"
#include "structurePlace.hpp"
#include "roadPlace.hpp"
#include "Catan_Piece.hpp"
#include "Catan_Settlement.hpp"


#ifndef TILE_HPP
#define TILE_HPP

using namespace std;

namespace Catan {
class Tile {
   private:
    array<structurePlace,6> structurePlaces;
    array<roadPlace,6> roadPlaces;
    string resourceType;
    int activationNumber;
    array<Player,3> attachedPlayers;
   
   public:
    Tile(const string& resourceType, int activationNumber, array<structurePlace,6> structurePlaces, array<roadPlace,6> roadPlaces);
    string getResourceType() const { return resourceType; }
    int getActivationNumber() const { return activationNumber; }
    array<structurePlace,6> getStructurePlaces() const { return structurePlaces; }
    array<roadPlace,6> getRoadPlaces() const { return roadPlaces; }
    array<Player,3> getAttachedPlayers() const { return attachedPlayers; }


};

}  // namespace Catan

#endif  // TILE_HPP