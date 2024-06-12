#pragma once

#include "developmentCard.hpp"

using namespace std;
namespace Catan {

class progressCard : public developmentCard {
    string type;
public:
    progressCard(const string& type);
    void useCard() const override;
};

}