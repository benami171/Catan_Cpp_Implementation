#include "knightCard.hpp"
#include "Player.hpp"

using namespace std;
using namespace Catan;

knightCard::knightCard(const string& type, int turnBoughtIn)
    : developmentCard("Knight", turnBoughtIn) {}

void knightCard::useCard(Player& owner) const {
    return;
}
