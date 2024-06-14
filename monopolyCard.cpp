#include "monopolyCard.hpp"
#include "CatanGame.hpp"

using namespace std;
using namespace Catan;

Catan::monopolyCard::monopolyCard(const string& type, int turnBoughtIn) 
: developmentCard("monopoly", 0) {}

void Catan::monopolyCard::useCard(Player& owner) const {
    cout << "You have used a monopoly card!" << endl;
}

void Catan::monopolyCard::useCard(Player& owner,string chosenResource,CatanGame& game) const {
    
}