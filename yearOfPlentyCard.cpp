#include "yearOfPlentyCard.hpp"

using namespace std;
using namespace Catan;

Catan::yearOfPlentyCard::yearOfPlentyCard(const string& type, int turnBoughtIn)
    : developmentCard("YearOfPlenty", turnBoughtIn) {}

void Catan::yearOfPlentyCard::useCard(Player& owner) const {
    cout << "Year of Plenty card used" << endl;
}