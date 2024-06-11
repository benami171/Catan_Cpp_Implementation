#include "progressCard.hpp"

using namespace std;
using namespace Catan;

progressCard::progressCard() {
    cardsCategory = "";
}

progressCard::progressCard(string category) {
    cardsCategory = category;
}

void progressCard::useCard() {
    cout << "Progress card " << this->cardsCategory << " used" << endl;
}