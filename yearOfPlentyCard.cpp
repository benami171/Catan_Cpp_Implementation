#include "yearOfPlentyCard.hpp"
#include "Player.hpp"

using namespace std;
using namespace Catan;

yearOfPlentyCard::yearOfPlentyCard(const string& type, int turnBoughtIn)
    : developmentCard("YearOfPlenty", turnBoughtIn) {}

void yearOfPlentyCard::useCard(Player& owner) const {
    cout << "Year of Plenty card used" << endl;
}