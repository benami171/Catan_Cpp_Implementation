#ifndef CATAN_CITY_HPP
#define CATAN_CITY_HPP

#include "Catan_Settlement.hpp"

namespace Catan {

    class Catan_City : public Catan_Settlement {

    private:
        int resourceAmount;
        int victoryPoints;

    public:
        Catan_City(const string& owner, int structId)
            : Catan_Settlement(owner, structId), resourceAmount(2), victoryPoints(2) {};

        int getResourceAmount() const { return resourceAmount; };
        int getVictoryPoints() const { return victoryPoints; };
    };  

}

#endif  // CATAN_CITY_HPP