#include "roadBuildingCard.hpp" 

using namespace std;
using namespace Catan;

Catan::roadBuildingCard::roadBuildingCard(const string& type, int turnBoughtIn) 
: developmentCard(type, turnBoughtIn) {}

void Catan::roadBuildingCard::useCard(Player& owner) const {
    cout << "You have used a road building card!" << endl;
}