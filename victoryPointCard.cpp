#include "victoryPointCard.hpp"
#include "Player.hpp"

using namespace std;
using namespace Catan;

victoryPointCard::victoryPointCard(const string& type, int turnBoughtIn)
    : developmentCard("Victory Point", turnBoughtIn) {}

void victoryPointCard::useCard(Player& owner) const {
    cout << owner.getName() << " used a Victory Point card!" << endl;
}
