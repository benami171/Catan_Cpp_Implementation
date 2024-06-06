#include <string.h>

#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

#include "Catan_Piece.hpp"
#include "Player.hpp"
#include "roadPlace.hpp"
#ifndef STRUCTUREPLACE_HPP
#define STRUCTUREPLACE_HPP

using namespace std;

namespace Catan {
class structurePlace {
   private:
    string owner;
    string identifierString; // N FOR NONE, S FOR SETTLEMENT, C FOR CITY
    string structType;
    int structNumber;
    array<structurePlace*, 3> adjStructs;  
    array<roadPlace*, 3> adjRoads;  
    vector<string> attachedResources;      

   public:
   // Default constructor
    structurePlace() : owner(""), structType(""), structNumber(0) {}  

    structurePlace(string owner, string structType, int structNumber=0);

    // Deep copy constructor
    structurePlace(const structurePlace& other);
    
    string getOwner();
    string getStructType();
    int getStructNumber();
    void setAdjStructs(array<structurePlace*, 3> adjStructs);
    void setAdjRoads(array<roadPlace*, 3> adjRoads);
    bool validSettlementPlacement(string newOwner);
    structurePlace& operator=(const structurePlace& other) ;
    string getIdentifierString();
};

}  // namespace Catan

#endif  // STRUCTUREPLACE_HPP