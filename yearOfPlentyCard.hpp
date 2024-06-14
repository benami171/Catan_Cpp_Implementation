#include "developmentCard.hpp"
#pragma once

using namespace std;

namespace Catan {
class yearOfPlentyCard : public developmentCard {
   public:
    yearOfPlentyCard(const string& type, int turnBoughtIn);
    void useCard(Player& owner) const override;
};

}  // namespace Catan
