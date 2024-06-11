#include <string.h>
#include <iostream>
#include <set>
#include <unordered_map>
#include <array>

#include "Player.hpp"

#ifndef ROADPLACE_HPP
#define ROADPLACE_HPP

using namespace std;

namespace Catan {
    class structurePlace; // Forward declaration of structurePlace, used to avoid circular dependencies.
    class roadPlace {
    private:
        Player* owner;
        int roadNumber;
        array<structurePlace*, 2> adjStructs; 
        array<roadPlace*, 4> adjRoads;

    public:
        roadPlace(); // Default constructor
        roadPlace(Player* owner, int roadNumber);
        Player* getOwner(); // Method to get owner
        void setOwner(Player* newOwner); // Method to set owner
        string getOwnerString(); // gets the name of the Player who owns the road (using Player* owner)
        void setAdjStructs(array<structurePlace*, 2> adjStructs); // Method to set adjacent structures
        void setAdjRoads(array<roadPlace*, 4> adjRoads); // Method to set adjacent roads
        bool placedRoad(Player* newOwner); // checks the validity of the road placement, if valid, sets the owner of the road to newOwner
    };

}

#endif  // ROADPLACE_HPP