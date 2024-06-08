#include "Player.hpp"
#include "roadPlace.hpp"
#include "Board.hpp"

using namespace std;
using namespace Catan;


Player::Player() : name(""), victoryPoints(0),initialMoveNumber(1), roads_placed_counter(0), settlements_placed_counter(0), cities_placed_counter(0) {
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
    initialMoveNumber = 1;
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

void Player::placeRoad(int road_index,Board& board) {
    if (roads_placed_counter < 15 && this->getResourceCardAmount("brick") >= 1 && this->getResourceCardAmount("lumber") >= 1) {
        roadPlace* road = board.getRoadAt(road_index);
        if (road->placedRoad(this)) {
            roads_placed_counter++;
            this->removeResourceCard("brick", 1);
            this->removeResourceCard("lumber", 1);
            owned_roads_indices.push_back(road_index);
            cout << "Player " << name << " placed a road at index " << road_index << endl;
        } else {
            cout << "Invalid road placement" << endl;
        }
    } else {
        cout << "Player " << name << " does not have enough resources to place a road" << endl;
    } 
}

void Player::placeSettlement(int structurePlace_index,Board& board){
if (settlements_placed_counter < 5 && this->getResourceCardAmount("brick") >= 1 && this->getResourceCardAmount("lumber") >= 1 && this->getResourceCardAmount("wool") >= 1 && this->getResourceCardAmount("grain") >= 1) {
        structurePlace* settlement = board.getStructureAt(structurePlace_index);
        vector<Tile*> adjTiles = settlement->getAdjTiles();
        if (settlement->placedSettlement(this)) {
            settlements_placed_counter++;
            this->addVictoryPoints(1);
            this->removeResourceCard("brick", 1);
            this->removeResourceCard("lumber", 1);
            this->removeResourceCard("wool", 1);
            this->removeResourceCard("grain", 1);
            for (int i = 0 ; i < adjTiles.size() ; i ++){
                adjTiles[i]->addAttachedPlayer(this);
            }
   
            cout << "Player " << name << " placed a settlement at index " << structurePlace_index << endl;
        } else {
            cout << "Invalid settlement placement" << endl;
        }
    } else {
        cout << "Player " << name << " does not have enough resources to place a settlement" << endl;
    }
    
}

void Player::placeCity(int structurePlace_index,Board& board){
    if (cities_placed_counter < 4 && this->getResourceCardAmount("grain") >= 2 && this->getResourceCardAmount("ore") >= 3) {
        structurePlace* city = board.getStructureAt(structurePlace_index);
        if (city->placedCity(this)) {
            cities_placed_counter++;
            settlements_placed_counter--;
            this->addVictoryPoints(1);
            this->removeResourceCard("grain", 2);
            this->removeResourceCard("ore", 3);
            owned_cities_indices.push_back(structurePlace_index);
            cout << "Player " << name << " placed a city at index " << structurePlace_index << endl;
        } else {
            cout << "Invalid city placement" << endl;
        }
    } else {
        cout << "Player " << name << " does not have enough resources to place a city" << endl;
    }
}

string Player::getPlayerColor(){
    if (name == "Player 1") {
        return "\033[1;31m"; // Red
    } else if (name == "Player 2") {
        return "\033[1;34m"; // Blue
    } else if (name == "Player 3") {
        return "\033[1;32m"; // Green
    } else {
        return "\033[1;37m"; // White
    }
}

int Player::rollDice() {
    return rand() % 6 + 1 + rand() % 6 + 1;
}

void Player::getResouces(int diceRoll, Board& board) {
    const array<Tile, 19>& tiles = board.getTiles();
    for (int i = 0; i < tiles.size(); i++) {
        if (tiles[i].getActivationNumber() == diceRoll) {
            const array<structurePlace*, 6>& structurePlaces = tiles[i].getStructurePlaces();
            for (int j = 0; j < 6; j++) {
                if (structurePlaces[j]->getOwnerString() == name) {
                    string resourceType = tiles[i].getResourceType();
                    if (resourceType != "Desert") {
                        string structureType = structurePlaces[j]->getStructType();
                        if (structureType == "SETTLEMENT") {
                            addResourceCard(resourceType, 1);
                            cout << "Player " << name << " received a " << resourceType << " card" << endl;
                        } else if (structureType == "CITY") {
                            addResourceCard(resourceType, 2);
                            cout << "Player " << name << " received two " << resourceType << " cards" << endl;
                        }
                    }
                }
            }
        }
    }
}