#pragma once

#include "developmentCard.hpp"

using namespace std;
namespace Catan {

class Player;

class victoryPointCard : public developmentCard {
   public:
    victoryPointCard(const string& type, int turnBoughtIn);
    void useCard(Player& owner) const override;
};

}  // namespace Catan