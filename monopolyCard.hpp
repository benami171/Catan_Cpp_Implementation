#include <string>
#include <iostream>
#include <vector>
#include "developmentCard.hpp" 
#pragma once

using namespace std;

namespace Catan {
    class monopolyCard : public developmentCard {
    public:
        monopolyCard(const string& type, int turnBoughtIn);
        void useCard(Player& owner) const override;
        void useCard(Player& owner,string chosenResource,CatanGame& game) const;
    };

}