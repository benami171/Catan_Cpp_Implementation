#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace Catan {

class Player;

class developmentCard {
public:
    string type;
    int turnBoughtIn;

    developmentCard();
    developmentCard(const string& type, int turnBoughtIn);
    virtual ~developmentCard();
    string getCardCategory() const;
    virtual void useCard(Player& owner) const = 0; // Pure virtual function to make developmentCard abstract

    int getTurnBoughtIn() const;
};

}