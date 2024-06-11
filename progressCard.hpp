#pragma once

#include "developmentCard.hpp"

namespace Catan {

class progressCard : public developmentCard {
public:
    progressCard(const std::string& category);
    void useCard() const override;
};

}