#include <string.h>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include "CatanPiece.hpp"
#include "Player.hpp"
#include "roadPlace.hpp"

using namespace std;

namespace Catan {
    class structurePlace{
        private:
        string owner;
        string structType;
        int structNumber;
        array<structurePlace*,3> adjStructs; // Use pointers to structurePlace
        array<roadPlace*,3> adjRoads; // Use pointers to roadPlace

        public:
        structurePlace(string owner, string structType, int structNumber){
            this->owner = owner;
            this->structType = structType;
            this->structNumber = structNumber;
        }

        string getOwner(){
            return owner;
        }

        string getStructType(){
            return structType;
        }

        int getStructNumber(){
            return structNumber;
        }

        void setAdjStructs(array<structurePlace*,3> adjStructs){
            this->adjStructs = adjStructs;
        }

        void setAdjRoads(array<roadPlace*,3> adjRoads){
            this->adjRoads = adjRoads;
        }

    };

}