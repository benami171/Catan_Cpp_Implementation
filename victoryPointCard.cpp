#include "victoryPointCard.hpp"

using namespace std;
using namespace Catan;

victoryPointCard::victoryPointCard() : developmentCard("Victory Point") {}

void victoryPointCard::useCard() const {
    cout << "Victory Point card used" << endl;
}

