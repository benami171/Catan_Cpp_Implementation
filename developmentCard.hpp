#pragma once

#include <iostream>
#include <string>
using namespace std;
namespace Catan {

class developmentCard {
public:
    developmentCard();
    developmentCard(const string& category);
    virtual ~developmentCard();
    
    string getCardCategory() const;
    virtual void useCard() const = 0; // Pure virtual function to make developmentCard abstract

protected:
    string cardCategory;
};

}