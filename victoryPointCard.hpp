#pragma once

#include "developmentCard.hpp"

using namespace std;
namespace Catan {

class victoryPointCard : public developmentCard {
public:
    victoryPointCard();
    void useCard() const override;
};

}