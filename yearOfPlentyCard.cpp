#include "yearOfPlentyCard.hpp"

using namespace std;
using namespace Catan;

yearOfPlentyCard::yearOfPlentyCard(const string& type, int turnBoughtIn)
    : developmentCard("YearOfPlenty", turnBoughtIn) {}

void yearOfPlentyCard::useCard() const {
    cout << "Year of Plenty card used" << endl;
}