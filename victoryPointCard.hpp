#pragma once

#include "developmentCard.hpp"

namespace Catan {

class victoryPointCard : public developmentCard {
public:
    victoryPointCard();
    void useCard() const override;
};

}