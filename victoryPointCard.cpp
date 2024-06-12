#include "victoryPointCard.hpp"

using namespace std;
using namespace Catan;

victoryPointCard::victoryPointCard(const string& type, int turnBoughtIn)
    : developmentCard("Victory Point", turnBoughtIn) {}

void victoryPointCard::useCard() const {
    cout << "Victory Point card used" << endl;
}
