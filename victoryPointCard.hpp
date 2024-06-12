#pragma once

#include "developmentCard.hpp"

using namespace std;
namespace Catan {

class victoryPointCard : public developmentCard {
   public:
    victoryPointCard(const string& type, int turnBoughtIn);
    void useCard() const override;
};

}  // namespace Catan