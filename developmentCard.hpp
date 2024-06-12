#pragma once

#include <iostream>
#include <string>
using namespace std;
namespace Catan {

class developmentCard {
public:
    int turnBoughtIn;
    string type;

    developmentCard();
    developmentCard(const string& type, int turnBoughtIn);
    virtual ~developmentCard();
    string getCardCategory() const;
    virtual void useCard() const = 0; // Pure virtual function to make developmentCard abstract

    int getTurnBoughtIn() const;
};

}