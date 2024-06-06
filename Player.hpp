
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#ifndef PLAYER_HPP
#define PLAYER_HPP

using namespace std;

namespace Catan {

class Player {
   private:
    string name;
    string playerColor;
    int victoryPoints;
    int roads_placed_counter;
    int settlements_placed_counter;
    int cities_placed_counter;

    unordered_map<string, int> resourceCards;
    unordered_map<string, int> developmentCards;

   public:
    Player();

    Player(string name);

    string getPlayerColor() {
        return playerColor;
    }

    string getName() {
        return name;
    }

    int getVictoryPoints() {
        return victoryPoints;
    }

    void addVictoryPoints(int points) {
        victoryPoints += points;
    }

    void removeVictoryPoints(int points) {
        victoryPoints -= points;
    }

    // the resources are brick, lumber, wool, grain, ore
    void addResourceCard(string resource, int amount) {
        resourceCards[resource] += amount;
    }

    void removeResourceCard(string resource, int amount) {
        resourceCards[resource] -= amount;
    }

    // the development cards are victoryPoint, roadBuilding, yearOfPlenty, monopoly
    // wasnt asked to implement the knight card.
    void addDevelopmentCard(string developmentCard, int amount) {
        developmentCards[developmentCard] += amount;
    }

    void removeDevelopmentCard(string developmentCard, int amount) {
        developmentCards[developmentCard] -= amount;
    }

    int getResourceCardAmount(string resource) {
        return resourceCards[resource];
    }

    int getDevelopmentCardAmount(string developmentCard) {
        return developmentCards[developmentCard];
    }

    // iterator goes through the resource cards and prints the amount of each resource
    void printResources() {
        cout << "Resource Cards: " << endl;
        for (auto it = resourceCards.begin(); it != resourceCards.end(); it++) {
            cout << it->first << ": " << it->second << endl;
        }
    }

    void printDevelopmentCards() {
        cout << "Development Cards: " << endl;
        for (auto it = developmentCards.begin(); it != developmentCards.end(); it++) {
            cout << it->first << ": " << it->second << endl;
        }
    }

    void printPlayerInfo() {
        cout << "Player: " << name << endl;
        cout << "Victory Points: " << victoryPoints << endl;
        printDevelopmentCards();
        printResources();
    }

    void placeRoad(int road_index) {
    }
};
}  // namespace Catan

#endif  // PLAYER_HPP