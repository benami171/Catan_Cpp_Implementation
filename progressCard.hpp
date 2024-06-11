#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include "developmentCard.hpp"

using namespace std;

namespace Catan {
    class progressCard : public developmentCard {
        public:
        progressCard();
        progressCard(string category) : developmentCard(category) {}
        void useCard() override;

    };

}  // namespace Catan