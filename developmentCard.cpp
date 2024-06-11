#include "developmentCard.hpp"

using namespace std;
using namespace Catan;

developmentCard::developmentCard() : cardCategory("") {}

developmentCard::developmentCard(const string& category) : cardCategory(category) {}

developmentCard::~developmentCard() {}

string developmentCard::getCardCategory() const {
    return cardCategory;
}