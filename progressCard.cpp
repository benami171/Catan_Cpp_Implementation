#include "progressCard.hpp"


using namespace std;
using namespace Catan;

progressCard::progressCard(const string& type, int turnBoughtIn) 
: developmentCard(type,turnBoughtIn){}

void progressCard::useCard() const {
    cout << "Progress card " << cardCategory << " used" << endl;
}

