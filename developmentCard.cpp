#include "developmentCard.hpp"

using namespace std;
using namespace Catan;

developmentCard::developmentCard() : cardCategory("") , turnBoughtIn(0) {}

developmentCard::developmentCard(const string& category, int turnBoughtIn) : cardCategory(category) ,turnBoughtIn(turnBoughtIn){}

developmentCard::~developmentCard() {}

string developmentCard::getCardCategory() const {
    return cardCategory;
}