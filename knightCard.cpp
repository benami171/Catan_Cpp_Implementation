#include "knightCard.hpp"


using namespace std;
using namespace Catan;

knightCard::knightCard() : developmentCard("Knight") {}

void knightCard::useCard() const {
    cout << "Knight card used" << endl;
}

