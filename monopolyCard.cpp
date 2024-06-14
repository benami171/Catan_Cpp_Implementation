#include "monopolyCard.hpp"
#include "Player.hpp"
#include "CatanGame.hpp"

using namespace std;
using namespace Catan;

monopolyCard::monopolyCard(const string& type, int turnBoughtIn)
    : developmentCard("monopoly", 0) {}

void monopolyCard::useCard(Player& owner) const {
    cout << "You have used a monopoly card!" << endl;
}

void monopolyCard::useCard(Player& owner, string chosenResource, CatanGame& game) const {
    cout << "You have used a monopoly card!" << endl;
    int total = 0;
    vector<Player*> players = game.getPlayers();
    for (auto player : players) {
        if (player->getName() != owner.getName()) {
            int resourceAmount = player->getResourceCardAmount(chosenResource);
            total += resourceAmount;
            player->removeResourceCard(chosenResource, resourceAmount);
        }
    }
    owner.addResourceCard(chosenResource, total);
}
