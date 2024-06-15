#pragma once

#include <array>
#include <string>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

namespace Catan {

class Player; // Forward declaration
class Tile; // Forward declaration
class roadPlace; // Forward declaration

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
    set<int> activationNumbers;   
    vector<pair<string, int>> resource_activationNumber; 

   public:
    structurePlace();
    structurePlace(Player* owner,string structType, int structNumber);
    // Deep copy constructor
    // structurePlace(const structurePlace& other);
    string getOwnerString();
    string getStructType();
    string getPrintableString();
    int getStructNumber();
    void addResource(string resource);
    void addAdjTile(Tile* tile);
    void addActivationNumber(int activationNumber);
    void addResourceAndActivationNumber(const string& resource, int activationNumber);
    const vector<pair<string,int>>& getResourceActivationNumber() const;
    const vector<Tile*>& getAdjTiles() const;
    void setAdjStructs(array<structurePlace*, 3> adjStructs);
    void setAdjRoads(array<roadPlace*, 3> adjRoads);
    bool placedCity(Player* newOwner);
    bool placedSettlement(Player* newOwner);
    bool placedInitialSettlement(Player* newOwner);
    // structurePlace& operator=(const structurePlace& other) ;
    string getIdentifierString();
    string getColor();
};

}  // namespace Catan

