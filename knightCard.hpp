#pragma once

#include "developmentCard.hpp"

using namespace std;

namespace Catan {

class Player;
class knightCard : public developmentCard {
public:
    knightCard(const string& type, int turnBoughtIn);
    void useCard(Player& owner) const override;
};

} 



