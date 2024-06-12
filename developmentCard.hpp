#pragma once

#include <iostream>
#include <string>
using namespace std;
namespace Catan {

class developmentCard {
public:
    int turnBoughtIn;

    developmentCard();
    developmentCard(const string& category, int turnBoughtIn);
    virtual ~developmentCard();
    string getCardCategory() const;
    virtual void useCard() const = 0; // Pure virtual function to make developmentCard abstract
    string cardCategory;
};

}