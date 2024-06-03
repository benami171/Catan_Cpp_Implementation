#include "Player.hpp"
#include "Board.hpp"
#include <array>
#include <string>

using namespace std;
using namespace Catan;

Player::Player() : name(""), victoryPoints(0), roads_placed_counter(0), settlements_placed_counter(0), cities_placed_counter(0) {
    resourceCards["brick"] = 0;
    resourceCards["lumber"] = 0;
    resourceCards["wool"] = 0;
    resourceCards["grain"] = 0;
    resourceCards["ore"] = 0;
    developmentCards["victoryPoint"] = 0;
    developmentCards["roadBuilding"] = 0;
    developmentCards["yearOfPlenty"] = 0;
    developmentCards["monopoly"] = 0;
}

Player::Player(string name) {
    this->name = name;
    victoryPoints = 0;
    roads_placed_counter = 0;
    settlements_placed_counter = 0;
    cities_placed_counter = 0;
    resourceCards["brick"] = 0;
    resourceCards["lumber"] = 0;
    resourceCards["wool"] = 0;
    resourceCards["grain"] = 0;
    resourceCards["ore"] = 0;
    developmentCards["victoryPoint"] = 0;
    developmentCards["roadBuilding"] = 0;
    developmentCards["yearOfPlenty"] = 0;
    developmentCards["monopoly"] = 0;
}

string Player::getName() {
    return name;
}

int Player::getVictoryPoints() {
    return victoryPoints;
}

void Player::addVictoryPoints(int points) {
    victoryPoints += points;
}

void Player::removeVictoryPoints(int points) {
    victoryPoints -= points;
}

// the resources are brick, lumber, wool, grain, ore
void Player::addResourceCard(string resource, int amount) {
    resourceCards[resource] += amount;
}

void Player::removeResourceCard(string resource, int amount) {
    resourceCards[resource] -= amount;
}

// the development cards are victoryPoint, roadBuilding, yearOfPlenty, monopoly
// wasnt asked to implement the knight card.
void Player::addDevelopmentCard(string developmentCard, int amount) {
    developmentCards[developmentCard] += amount;
}

void Player::removeDevelopmentCard(string developmentCard, int amount) {
    developmentCards[developmentCard] -= amount;
}

int Player::getResourceCardAmount(string resource) {
    return resourceCards[resource];
}

int Player::getDevelopmentCardAmount(string developmentCard) {
    return developmentCards[developmentCard];
}

// iterator goes through the resource cards and prints the amount of each resource
void Player::printResources() {
    cout << "Resource Cards: " << endl;
    for (auto it = resourceCards.begin(); it != resourceCards.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
}

void Player::printDevelopmentCards() {
    cout << "Development Cards: " << endl;
    for (auto it = developmentCards.begin(); it != developmentCards.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
}

void Player::printPlayerInfo() {
    cout << "Player: " << name << endl;
    cout << "Victory Points: " << victoryPoints << endl;
    printDevelopmentCards();
    printResources();
}

void Player::placeRoad(int road_index) {
    if (roads_placed_counter < 15 && this->getResourceCardAmount("brick") >= 1 && this->getResourceCardAmount("lumber") >= 1) {
        
}