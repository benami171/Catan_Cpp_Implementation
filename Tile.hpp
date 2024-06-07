#include <array>
#include <string>

#include "Catan_Piece.hpp"
#include "Catan_Settlement.hpp"
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
    vector<Player*> attachedPlayers;

   public:
    Tile() : resourceType(""), activationNumber(0) {}  // Default constructor
    Tile(const string& resourceType, int activationNumber, array<structurePlace*, 6> structurePlaces, array<roadPlace*, 6> roadPlaces);
    string getResourceType() const;
    void setResourceType(string resourceType);
    int getActivationNumber() const;
    void setActivationNumber(int activationNumber);
    void setResourceAndNumber(string resourceType, int activationNumber);
    array<structurePlace*, 6> getStructurePlaces() const;
    array<roadPlace*, 6> getRoadPlaces() const;
    vector<Player*> getAttachedPlayers() const;
    void addAttachedPlayer(Player* player);
    Tile& operator=(const Tile& other);
};

}  // namespace Catan

#endif  // TILE_HPP