#include <string.h>

#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

#include "CatanPiece.hpp"
#include "Player.hpp"
#include "roadPlace.hpp"
#ifndef STRUCTUREPLACE_HPP
#define STRUCTUREPLACE_HPP

using namespace std;

namespace Catan {
class structurePlace {
   private:
    string owner;
    string structType;
    int structNumber;
    array<structurePlace*, 3> adjStructs;  //
    array<roadPlace*, 9> adjRoads;         //

   public:
    structurePlace() : owner(""), structType(""), structNumber(0) {}  // Default constructor

    structurePlace(string owner, string structType, int structNumber) {
        this->owner = owner;
        this->structType = structType;
        this->structNumber = structNumber;
    }

    string getOwner() {
        return owner;
    }

    string getStructType() {
        return structType;
    }

    int getStructNumber() {
        return structNumber;
    }

    void setAdjStructs(array<structurePlace*, 3> adjStructs) {
        this->adjStructs = adjStructs;
    }

    void setAdjRoads(array<roadPlace*, 9> adjRoads) {
        this->adjRoads = adjRoads;
    }

    bool validSettlementPlacement(string newOwner) {
        if (this->owner != "") {
            return false;
        }
        for (int i = 0; i < adjStructs.size(); i++) {
            if (adjStructs[i]->getOwner() != "") {
                return false;
            }
        }
        for (int i = 0; i < adjRoads.size(); i++) {
            if (adjRoads[i]->getOwner() == newOwner) {
                return true;
            }
        }
        return false;
    }
};

}  // namespace Catan

#endif  // STRUCTUREPLACE_HPP