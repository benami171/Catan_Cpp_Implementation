#include "victoryPointCard.hpp"
#include "Player.hpp"

using namespace std;
using namespace Catan;

victoryPointCard::victoryPointCard(const string& type, int turnBoughtIn)
    : developmentCard("Victory Point", turnBoughtIn) {}

void victoryPointCard::useCard(Player& owner) const {
    cout << "Victory Point card used" << endl;
}
