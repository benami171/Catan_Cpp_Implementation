#include "roadBuildingCard.hpp"
#include "Player.hpp"

using namespace std;
using namespace Catan;

roadBuildingCard::roadBuildingCard(const string& type, int turnBoughtIn) 
: developmentCard(type, turnBoughtIn) {}

void roadBuildingCard::useCard(Player& owner) const {
    owner.addFreeRoads(2);
}