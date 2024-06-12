#include "roadBuildingCard.hpp" 

using namespace std;
using namespace Catan;

roadBuildingCard::roadBuildingCard(const string& type, int turnBoughtIn) 
: developmentCard(type, turnBoughtIn) {}

void roadBuildingCard::useCard() const {
    cout << "You have used a road building card!" << endl;
}