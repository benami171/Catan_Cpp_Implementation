#pragma once

#include "developmentCard.hpp"

using namespace std;
namespace Catan {

class knightCard : public developmentCard {
public:
    knightCard(const string& type, int turnBoughtIn);
    void useCard() const override;
};

} 



