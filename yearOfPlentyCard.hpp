#include "developmentCard.hpp" 
#pragma once

using namespace std;

namespace Catan {
    class yearOfPlentyCard : public developmentCard {
    public:
        yearOfPlentyCard(const string& type, int turnBoughtIn);
        void useCard() const override;
    };

}
