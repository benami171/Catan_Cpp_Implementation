#include "knightCard.hpp"

using namespace std;
using namespace Catan;

knightCard::knightCard(const string& type, int turnBoughtIn)
    : developmentCard("Knight", turnBoughtIn) {}

void knightCard::useCard() const {
    cout << "Knight card used" << endl;
}
