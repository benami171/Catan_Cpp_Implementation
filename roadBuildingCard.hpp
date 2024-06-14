#include "developmentCard.hpp"
#pragma once

using namespace std;
namespace Catan {
    class roadBuildingCard : public developmentCard {
    public:
        roadBuildingCard(const string& type, int turnBoughtIn);
        void useCard(Player& owner) const override;
    };
}