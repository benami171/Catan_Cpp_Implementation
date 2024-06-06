#include <string.h>
#include <iostream>
#include <set>
#include <unordered_map>
#include <array>
#include "Catan_Piece.hpp"
#include "Player.hpp"
#ifndef ROADPLACE_HPP
#define ROADPLACE_HPP

using namespace std;

namespace Catan {
    class structurePlace; // Forward declaration of structurePlace, used to avoid circular dependencies.
    class roadPlace {
    private:
        string owner;
        int roadNumber;
        array<structurePlace*, 2> adjStructs; 
        array<roadPlace*, 4> adjRoads;

    public:
        roadPlace(string owner, int roadNumber);
        string getOwner(); // Method to get owner
        void setAdjStructs(array<structurePlace*, 2> adjStructs); // Method to set adjacent structures
        void setAdjRoads(array<roadPlace*, 4> adjRoads); // Method to set adjacent roads
    };

}

#endif  // ROADPLACE_HPP