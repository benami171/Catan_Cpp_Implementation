#include <string.h>
#include <iostream>
#include <array>
#include <set>
#include <unordered_map>
#include <vector>
#include "Player.hpp"
#include "roadPlace.hpp"

#ifndef STRUCTUREPLACE_HPP
#define STRUCTUREPLACE_HPP

using namespace std;

namespace Catan {
class Tile;
class structurePlace {
   private:
    Player* owner;
    string identifierString; // N FOR NONE, S FOR SETTLEMENT, C FOR CITY
    string structType;
    int structNumber;
    array<structurePlace*, 3> adjStructs;  
    array<roadPlace*, 3> adjRoads;
    vector<Tile*> adjTiles;  
    set<string> attachedResources;      

   public:
    structurePlace();
    structurePlace(Player* owner,string structType, int structNumber);
    // Deep copy constructor
    structurePlace(const structurePlace& other);
    
    string getOwnerString();
    string getStructType();
    void addResource(string resource);
    int getStructNumber();
    void addAdjTile(Tile* tile);
    const vector<Tile*>& getAdjTiles() const;
    void setAdjStructs(array<structurePlace*, 3> adjStructs);
    void setAdjRoads(array<roadPlace*, 3> adjRoads);
    bool placedCity(Player* newOwner);
    bool placedSettlement(Player* newOwner);
    bool placedInitialSettlement(Player* newOwner);
    structurePlace& operator=(const structurePlace& other) ;
    string getIdentifierString();
    string getColor();
};

}  // namespace Catan

#endif  // STRUCTUREPLACE_HPP