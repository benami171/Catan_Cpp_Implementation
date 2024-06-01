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
    class structurePlace; // Forward declaration of structurePlace

    class roadPlace {
    private:
        string owner;
        int roadNumber;
        array<structurePlace*, 2> adjStructs; // 
        array<roadPlace*, 4> adjRoads; //

    public:
        roadPlace() : owner(""), roadNumber(0) {} // Default constructor
        roadPlace(string owner, int roadNumber) {
            this->owner = owner;
            this->roadNumber = roadNumber;
        }

        string getOwner() {
            return owner;
        }

        void setAdjStructs(array<structurePlace*, 2> adjStructs) {
            this->adjStructs = adjStructs;
        }

        void setAdjRoads(array<roadPlace*, 4> adjRoads) {
            this->adjRoads = adjRoads;
        }
    };
}

#endif  // ROADPLACE_HPP