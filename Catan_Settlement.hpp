#include <string>
#include <iostream>
#include <set>
#include <unordered_map>
#include <array>
#include "Player.hpp"
#include "roadPlace.hpp"
#include "Catan_Piece.hpp"
#ifndef CATAN_SETTLEMENT_HPP
#define CATAN_SETTLEMENT_HPP

using namespace std;

namespace Catan {

    class Catan_Settlement : public Catan_Piece {

    private:
        int structId;
        int resource_amount_granting;
        array<roadPlace*, 3> adjRoads;
        array<structurePlace*, 3> adjStructs;
    

    public:
        Catan_Settlement(const string& owner, int structId): Catan_Piece(owner), structId(structId), resource_amount_granting(1) {};
        int getStructId() const { return structId; };
        void setAdjRoads(array<roadPlace*, 3> adjRoads) { this->adjRoads = adjRoads; };
        void setAdjStructs(array<structurePlace*, 3> adjStructs) { this->adjStructs = adjStructs; };
        bool validSettlementPlacement(string newOwner);
    };  

}

#endif  // CATAN_SETTLEMENT_HPP