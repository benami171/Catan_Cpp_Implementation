#pragma once

#include "developmentCard.hpp"

using namespace std;

namespace Catan {

class Player;  // Forward declaration

class yearOfPlentyCard : public developmentCard {
   public:
    yearOfPlentyCard(const string& type, int turnBoughtIn);
    void useCard(Player& owner) const override;
};

}  // namespace Catan
