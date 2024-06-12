#include "developmentCard.hpp"

using namespace std;
using namespace Catan;

developmentCard::developmentCard() : type("") , turnBoughtIn(0) {}

developmentCard::developmentCard(const string& type, int turnBoughtIn) : type(type) ,turnBoughtIn(turnBoughtIn){}

developmentCard::~developmentCard() {}

string developmentCard::getCardCategory() const {
    return type;
}

int developmentCard::getTurnBoughtIn() const {
    return turnBoughtIn;
}