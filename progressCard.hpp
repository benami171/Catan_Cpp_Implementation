#pragma once

#include "developmentCard.hpp"

using namespace std;
namespace Catan {

class progressCard : public developmentCard {
public:
    string type;
    progressCard(const string& type, int turnBoughtIn);
    void useCard() const override;
};

}