#include "knightCard.hpp"


using namespace std;
using namespace Catan;

knightCard::knightCard() : developmentCard("Knight",turnBoughtIn) {}

void knightCard::useCard() const {
    cout << "Knight card used" << endl;
}

