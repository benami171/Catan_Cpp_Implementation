#include "monopolyCard.hpp"


using namespace std;
using namespace Catan;

monopolyCard::monopolyCard(const string& type, int turnBoughtIn) 
: developmentCard("monopoly", 0) {}

void monopolyCard::useCard() const {
    cout << "You have used a monopoly card!" << endl;
}