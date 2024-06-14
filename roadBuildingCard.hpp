#pragma once

#include "developmentCard.hpp"

using namespace std;
namespace Catan {

    class Player; // Forward declaration

    class roadBuildingCard : public developmentCard {
    public:
        roadBuildingCard(const string& type, int turnBoughtIn);
        void useCard(Player& owner) const override;
    };
}