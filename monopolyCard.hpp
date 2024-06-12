#include <string>
#include <iostream>
#include <vector>
#include "developmentCard.hpp" 
#pragma once

using namespace std;

namespace Catan {
    class monopolyCard : public developmentCard {
    public:
        monopolyCard();
        void useCard() const override;
    };

}