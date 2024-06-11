#include "progressCard.hpp"


using namespace std;
using namespace Catan;

progressCard::progressCard(const string& category) : developmentCard(category) {}

void progressCard::useCard() const {
    cout << "Progress card " << cardCategory << " used" << endl;
}

