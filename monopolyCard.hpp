#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "developmentCard.hpp"

using namespace std;

namespace Catan {

class Player;     // Forward declaration
class CatanGame;  // Forward declaration

class monopolyCard : public developmentCard {
   public:
    monopolyCard(const string& type, int turnBoughtIn);
    void useCard(Player& owner) const override;
    void useCard(Player& owner, string chosenResource, CatanGame& game) const;
};

}  // namespace Catan