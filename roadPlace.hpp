#pragma once

#include <array>
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

namespace Catan {

    class Player; // Forward declaration of Player, used to avoid circular dependencies.
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
        Player* getRoadOwner(); // Method to get owner
        void setOwner(Player* newOwner); // Method to set owner
        string getOwnerString(); // gets the name of the Player who owns the road (using Player* owner)
        void setAdjStructs(array<structurePlace*, 2> adjStructs); // Method to set adjacent structures
        void setAdjRoads(array<roadPlace*, 4> adjRoads); // Method to set adjacent roads
        bool placedRoad(Player* newOwner); // checks the validity of the road placement, if valid, sets the owner of the road to newOwner.
        bool canPlaceRoad(Player* newOwner); // Method to check if a road can be placed will be used in freeRoadPlacement.
        int getRoadNumber(); // Method to get road number
        string getPrintableString();
    };

}

