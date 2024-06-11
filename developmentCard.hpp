#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

namespace Catan {
class developmentCard {
   public:
    string cardsCategory;
    developmentCard();
    developmentCard(string category);
    ~developmentCard();
    string getCardCategory();
    virtual void useCard();
};

}  // namespace Catan