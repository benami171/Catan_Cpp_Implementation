#include "developmentCard.hpp"

using namespace std;
using namespace Catan;

developmentCard::developmentCard() {
    cardsCategory = "";
}

developmentCard::developmentCard(string category) {
    cardsCategory = category;
}

developmentCard::~developmentCard() {
}

string developmentCard::getCardCategory() {
    return this->cardsCategory;
}

void developmentCard::useCard() {
    cout << "Developement card " << this->cardsCategory << " used" << endl;
}