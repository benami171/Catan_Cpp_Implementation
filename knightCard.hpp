#pragma once

#include "developmentCard.hpp"

using namespace std;
namespace Catan {

class knightCard : public developmentCard {
public:
    knightCard();
    void useCard() const override;
};

} 



