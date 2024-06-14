#include "Player.hpp"

#include "Board.hpp"
#include "CatanGame.hpp"
#include "Tile.hpp"
#include "developmentCard.hpp"
#include "knightCard.hpp"
#include "monopolyCard.hpp"
#include "roadBuildingCard.hpp"
#include "victoryPointCard.hpp"
#include "yearOfPlentyCard.hpp"

using namespace std;
using namespace Catan;

Player::Player() : name(""), myTurn(false), initialSettlementNumber(1), initialRoadNumber(1), victoryPoints(0), roads_placed_counter(0), settlements_placed_counter(0), cities_placed_counter(0), freeRoads(0), hasLargestArmy(false) {
    resourceCards["brick"] = 0;
    resourceCards["lumber"] = 0;
    resourceCards["wool"] = 0;
    resourceCards["wheat"] = 0;
    resourceCards["ore"] = 0;
    developmentCards["victoryPoint"] = 0;
    developmentCards["roadBuilding"] = 0;
    developmentCards["yearOfPlenty"] = 0;
    developmentCards["knight"] = 0;
    developmentCards["monopoly"] = 0;
    developmentCards["largestArmy"] = 0;
}

Player::Player(string name) : name(name), myTurn(false), playerColor(""), initialSettlementNumber(1), initialRoadNumber(1), victoryPoints(0), roads_placed_counter(0), settlements_placed_counter(0), cities_placed_counter(0), freeRoads(0), hasLargestArmy(false) {
    this->name = name;
    victoryPoints = 0;
    roads_placed_counter = 0;
    settlements_placed_counter = 0;
    cities_placed_counter = 0;
    initialSettlementNumber = 1;
    initialRoadNumber = 1;
    resourceCards["brick"] = 0;
    resourceCards["lumber"] = 0;
    resourceCards["wool"] = 0;
    resourceCards["wheat"] = 0;
    resourceCards["ore"] = 0;
    developmentCards["victoryPoint"] = 0;
    developmentCards["roadBuilding"] = 0;
    developmentCards["yearOfPlenty"] = 0;
    developmentCards["knight"] = 0;
    developmentCards["monopoly"] = 0;
    developmentCards["largestArmy"] = 0;
}

bool Player::trade(unordered_map<string, int> giveResources, unordered_map<string, int> receiveResources, Player& otherPlayer) {
    if (!myTurn) {
        cout << name << " Can't trade, it is not your turn." << endl;
        return false;
    }
    // Check if current player has enough resources to give
    for (auto& resource : giveResources) {
        // goes over each resource in the giveResources map and checks if the player has enough of that resource
        // in his own resourceCards map.
        if (resourceCards[resource.first] < resource.second) {
            return false;
        }
    }

    // Check if other player has enough resources to give
    for (auto& resource : receiveResources) {
        if (otherPlayer.resourceCards[resource.first] < resource.second) {
            return false;
        }
    }

    // Subtract resources to give and add resources to receive for current player
    for (auto& resource : giveResources) {
        resourceCards[resource.first] -= resource.second;
    }
    for (auto& resource : receiveResources) {
        resourceCards[resource.first] += resource.second;
    }

    // Subtract resources to give and add resources to receive for other player
    for (auto& resource : receiveResources) {
        otherPlayer.resourceCards[resource.first] -= resource.second;
    }
    for (auto& resource : giveResources) {
        otherPlayer.resourceCards[resource.first] += resource.second;
    }

    return true;
}

bool Player::tradeWithBank(unordered_map<string, int> giveResources, unordered_map<string, int> receiveResources, CatanGame& game) {
    if (!myTurn) {
        cout << "It is not your turn" << endl;
        return false;
    }
    // Calculate total resources to give and receive
    int totalGive = 0;
    for (auto& resource : giveResources) {
        totalGive += resource.second;
    }

    int totalReceive = 0;
    for (auto& resource : receiveResources) {
        totalReceive += resource.second;
    }

    // Check trading ratio
    if (totalGive != 4 * totalReceive) {
        return false;
    }

    // Check if current player has enough resources to give
    for (auto& resource : giveResources) {
        if (resourceCards[resource.first] < resource.second) {
            return false;
        }
    }

    // Subtract resources to give and add resources to receive for current player
    for (auto& resource : giveResources) {
        resourceCards[resource.first] -= resource.second;
    }
    for (auto& resource : receiveResources) {
        resourceCards[resource.first] += resource.second;
    }

    return true;
}

void Player::placeRoad(int road_index, Board& board) {
    if (!myTurn) {
        cout << "It is not your turn." << endl;
        return;
    }
    if (initialRoadNumber < 3) {
        placeInitialRoad(road_index, board);
        return;
    }
    if (roads_placed_counter < 15 && this->getResourceCardAmount("brick") >= 1 && this->getResourceCardAmount("lumber") >= 1) {
        roadPlace* road = board.getRoadAt(road_index);
        if (road->placedRoad(this)) {
            roads_placed_counter++;
            this->removeResourceCard("brick", 1);
            this->removeResourceCard("lumber", 1);
            owned_roads_indices.push_back(road_index);
            cout << name << " Placed a road at index " << road_index << endl;
        } else {
            cout << "Invalid road placement" << endl;
        }
    } else {
        cout << "Player " << name << " does not have enough resources to place a road" << endl;
    }
}

void Player::placeInitialRoad(int road_index, Board& board) {
    roadPlace* road = board.getRoadAt(road_index);
    if (road->placedRoad(this)) {
        roads_placed_counter++;
        initialRoadNumber++;
        owned_roads_indices.push_back(road_index);
        cout << "Player " << name << " placed a road at index " << road_index << endl;
    } else {
        cout << "Invalid road placement" << endl;
    }
}

bool Player::placeFreeRoad(int road_index, Board& board) {
    if (freeRoads > 0) {
        roadPlace* road = board.getRoadAt(road_index);
        if (road->placedRoad(this)) {
            freeRoads--;
            owned_roads_indices.push_back(road_index);
            roads_placed_counter++;
            cout << name << " Placed a road at index " << road_index << endl;
            return true;
        } else {
            cout << "Invalid road placement" << endl;
            return false;
        }
    } else {
        cout << "Player " << name << " does not have any free roads" << endl;
        return false;
    }
}

void Player::placeSettlement(int structurePlace_index, Board& board) {
    // first check if its the players turn
    if (!myTurn) {
        cout << "It is not your turn." << endl;
        return;
    }
    if (initialSettlementNumber < 3) {
        placeInitialSettlement(structurePlace_index, board);
        return;
    }
    if (settlements_placed_counter < 5 && this->getResourceCardAmount("brick") >= 1 && this->getResourceCardAmount("lumber") >= 1 && this->getResourceCardAmount("wool") >= 1 && this->getResourceCardAmount("wheat") >= 1) {
        structurePlace* settlement = board.getStructureAt(structurePlace_index);
        if (settlement == nullptr) {
            cout << "Invalid structurePlace_index" << endl;
            return;
        }
        vector<Tile*> adjTiles = settlement->getAdjTiles();
        if (settlement->placedSettlement(this)) {
            settlements_placed_counter++;
            this->addVictoryPoints(1);
            this->removeResourceCard("brick", 1);
            this->removeResourceCard("lumber", 1);
            this->removeResourceCard("wool", 1);
            this->removeResourceCard("wheat", 1);
            for (int i = 0; i < 3; i++) {
                if (adjTiles[i] != nullptr) {
                    adjTiles[i]->addAttachedPlayer(this);
                }
            }

            owned_structures_indices.push_back(structurePlace_index);
            cout << name << " Placed a settlement at index " << structurePlace_index << endl;
        } else {
            cout << "Invalid settlement placement" << endl;
        }
    } else {
        cout << "Player " << name << " does not have enough resources to place a settlement" << endl;
    }
}

void Player::placeInitialSettlement(int structurePlace_index, Board& board) {
    structurePlace* settlement = board.getStructureAt(structurePlace_index);
    if (settlement == nullptr) {
        throw invalid_argument("Invalid structure index");
    }
    vector<Tile*> adjTiles = settlement->getAdjTiles();
    if (initialSettlementNumber < 3) {
        if (settlement->placedInitialSettlement(this)) {
            settlements_placed_counter++;
            this->addVictoryPoints(1);
            for (size_t i = 0; i < adjTiles.size(); i++) {
                if (adjTiles[i] != nullptr) {
                    adjTiles[i]->addAttachedPlayer(this);
                    if (initialSettlementNumber == 2) {
                        this->getInitResourcesFromTile(adjTiles[i]);
                    }
                }
            }
            initialSettlementNumber++;
            owned_structures_indices.push_back(structurePlace_index);
            cout << "Player " << name << " placed a settlement at index " << structurePlace_index << endl;
        } else {
            cout << "Invalid settlement placement" << endl;
        }
    } else {
        cout << "Player " << name << " has already placed 2 settlements" << endl;
    }
}

void Player::placeCity(int structurePlace_index, Board& board) {
    if (!myTurn) {
        cout << "It is not your turn." << endl;
        return;
    }
    if (cities_placed_counter < 4 && this->getResourceCardAmount("wheat") >= 2 && this->getResourceCardAmount("ore") >= 3) {
        structurePlace* city = board.getStructureAt(structurePlace_index);
        if (city->placedCity(this)) {
            cities_placed_counter++;
            settlements_placed_counter--;
            this->addVictoryPoints(1);
            this->removeResourceCard("wheat", 2);
            this->removeResourceCard("ore", 3);
            owned_structures_indices.push_back(structurePlace_index);
            cout << "Player " << name << " placed a city at index " << structurePlace_index << endl;
        } else {
            cout << "Invalid city placement" << endl;
        }
    } else {
        cout << "Player " << name << " does not have enough resources to place a city" << endl;
    }
}

int Player::rollDice() {
    if (!myTurn) {
        cout << "It is not your turn" << endl;
        return false;
    }
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    cout << "Player " << name << " rolled: " << dice1 + dice2 << endl;
    return dice1 + dice2;
}

int Player::rollDice(int wantedNumber) {
    if (!myTurn) {
        cout << "It is not your turn" << endl;
        return false;
    }
    if (wantedNumber < 2 || wantedNumber > 12) {
        cout << "Invalid dice roll" << endl;
        return -1;
    }
    return wantedNumber;
}

// this function gets called by getRecources() when the player rolls a 7.
void Player::payToll() {
    int totalCards = 0;
    for (auto& resource : resourceCards) {
        totalCards += resource.second;
    }
    if (totalCards >= 7) {  // in this case, the player must give up half of his cards.
        int halfAmount = totalCards / 2;
        for (auto& resource : resourceCards) {
            // as long as the player still has to give up cards, the loop will continue.
            if (halfAmount == 0) {
                break;
            }
            // checks for each type of resource if the player own more or equal amount of cards than the halfAmount.
            // If so, the player will give up halfAmount of that resource.
            if (resource.second >= halfAmount) {
                resource.second -= halfAmount;
                halfAmount = 0;
            } else {
                // else, we reduce the amount of cards the player has to give up by the amount of cards he has of that resource.
                halfAmount -= resource.second;
                resource.second = 0;
            }
        }
    }
}

/**
 * @brief This function is used to add resource cards to the player's hand based on the dice roll.
 *
 * @param diceRoll The number rolled on the dice.
 * @param board The game board.
 *
 * If the dice roll is 7, the player pays a toll and the function returns.
 *
 * The function then iterates over the indices of the structures owned by the player.
 * For each structure, it retrieves the resource_activationNumber vector, which contains pairs of resource types and their corresponding activation numbers.
 *
 * It then iterates over this vector. If the activation number of a pair matches the dice roll and the structure is a settlement, it adds one resource card of the corresponding type to the player's hand.
 * If the activation number of a pair matches the dice roll and the structure is a city, it adds two resource cards of the corresponding type to the player's hand.
 */
void Player::getResources(int diceRoll, Board& board) {
    if (diceRoll == 7) {
        return payToll();
    }
    for (int i = 0; i < owned_structures_indices.size(); i++) {
        structurePlace* settlement = board.getStructureAt(owned_structures_indices[i]);
        const vector<pair<string, int>> resources_activation_numbers = settlement->getResourceActivationNumber();
        for (int i = 0; i < resources_activation_numbers.size(); i++) {
            if (resources_activation_numbers[i].second == diceRoll && settlement->getStructType() == "SETTLEMENT") {
                addResourceCard(resources_activation_numbers[i].first, 1);
            } else if (resources_activation_numbers[i].second == diceRoll && settlement->getStructType() == "CITY") {
                addResourceCard(resources_activation_numbers[i].first, 2);
            }
        }
    }
}

void Player::getInitResourcesFromTile(Tile* tile) {
    // cout << "Player " << name << " is getting resources from tile " << tile->getTileNumber() << endl;
    // cout << "The tile type is: " << tile->getResourceType() << endl;
    if (tile->getResourceType() == "Desert") {
        return;
    }
    if (tile->getResourceType() == "Mountains") {
        addResourceCard("ore", 1);
        cout << name << " received an ore card" << endl;
    } else if (tile->getResourceType() == "Hills") {
        addResourceCard("brick", 1);
        cout << name << " received a brick card" << endl;
    } else if (tile->getResourceType() == "Fields") {
        addResourceCard("wheat", 1);
        cout << name << " received a wheat card" << endl;
    } else if (tile->getResourceType() == "Pasture") {
        addResourceCard("wool", 1);
        cout << name << " received a wool card" << endl;
    } else if (tile->getResourceType() == "Forrest") {
        addResourceCard("lumber", 1);
        cout << name << " received a lumber card" << endl;
    }
}

void Player::getInitResources(Board& board) {
    for (size_t i = 0; i < owned_structures_indices.size(); i++) {
        structurePlace* settlement = board.getStructureAt(owned_structures_indices[i]);
        vector<Tile*> adjTiles = settlement->getAdjTiles();
        for (int j = 0; j < 3; j++) {
            if (adjTiles[j] != nullptr) {
                getInitResourcesFromTile(adjTiles[j]);
            }
        }
    }
}

int Player::getSettlementsPlacedCounter() {
    return this->settlements_placed_counter;
}

int Player::getCitiesPlacedCounter() {
    return this->cities_placed_counter;
}

int Player::getRoadsPlacedCounter() {
    return this->roads_placed_counter;
}

int Player::getInitialSettlementsCounter() {
    return this->initialSettlementNumber;
}

int Player::getInitialRoadsCounter() {
    return this->initialRoadNumber;
}

bool Player::buyDevelopmentCard(string card, CatanGame& game, int turnBoughtIn) {
    if (!myTurn) {
        cout << "It is not your turn" << endl;
        return false;
    }
    if (game.buyDevelopmentCard(card, *this)) {
        if (card == "victoryPoint") {
            victoryPointCard newCard(card, turnBoughtIn);
            victoryPointCards.push_back(newCard);
            addDevelopmentCard("vicotryPoint", 1);
        } else if (card == "roadBuilding") {
            roadBuildingCard newCard(card, turnBoughtIn);
            roadBuildingCards.push_back(newCard);
            addDevelopmentCard("roadBuilding", 1);
        } else if (card == "yearOfPlenty") {
            yearOfPlentyCard newCard(card, turnBoughtIn);
            yearOfPlentyCards.push_back(newCard);
            addDevelopmentCard("yearOfPlenty", 1);
        } else if (card == "knight") {
            knightCard newCard(card, turnBoughtIn);
            knightCards.push_back(newCard);
            addDevelopmentCard("knight", 1);

        } else if (card == "monopoly") {
            monopolyCard newCard(card, turnBoughtIn);
            monopolyCards.push_back(newCard);
            addDevelopmentCard("monopoly", 1);
        }
        return true;
    } else {
        return false;
    }
}

bool Player::useMonopoly(string chosenResource, CatanGame& game) {
    vector<monopolyCard> mCards = this->monopolyCards;
    for (auto it = mCards.begin(); it != mCards.end(); ++it) {
        if (game.getTurnCounter() > it->getTurnBoughtIn()) {
            it->useCard(*this, chosenResource, game);
            mCards.erase(it);
            return true;
        }
    }
    return false;
}

bool Player::useYearOfPlenty(string resource1, string resource2, CatanGame& game) {
    vector<yearOfPlentyCard> yCards = this->yearOfPlentyCards;
    for (auto it = yCards.begin(); it != yCards.end(); ++it) {
        if (game.getTurnCounter() > it->getTurnBoughtIn()) {
            it->useCard(*this);
            yCards.erase(it);
            return true;
        }
    }
    return false;
}

bool Player::useRoadBuilding(int road1, int road2, CatanGame& game) {
    vector<roadBuildingCard> rCards = this->roadBuildingCards;
    roadPlace* road1p = game.getBoard().getRoadAt(road1);
    roadPlace* road2p = game.getBoard().getRoadAt(road2);
    bool first_road = false;
    bool second_road = false;
    for (auto it = rCards.begin(); it != rCards.end(); ++it) {
        if (game.getTurnCounter() > it->getTurnBoughtIn()) {
            it->useCard(*this);
            if (road1 >= 0 && road2 >= 0) {
                first_road = road1p->canPlaceRoad(this);
                second_road = road2p->canPlaceRoad(this);
                if (first_road && second_road) {
                    placeFreeRoad(road1, game.getBoard());
                    placeFreeRoad(road2, game.getBoard());
                    rCards.erase(it);
                    return true;
                }
            }
        }
    }
    return false;
}

string Player::getName() {
    return name;
}

void Player::addFreeRoads(int roads) {
    freeRoads += roads;
}

int Player::getFreeRoads() {
    return freeRoads;
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

// the resources are brick, lumber, wool, wheat, ore
void Player::addResourceCard(string resource, int amount) {
    if (resource == "Mountain") {
        resource = "ore";
    } else if (resource == "Hills") {
        resource = "brick";
    } else if (resource == "Fields") {
        resource = "wheat";
    } else if (resource == "Pasture") {
        resource = "wool";
    } else if (resource == "Forrest") {
        resource = "lumber";
    }
    resourceCards[resource] += amount;
}

void Player::removeResourceCard(string resource, int amount) {
    if (resourceCards[resource] >= amount) {
        resourceCards[resource] -= amount;
    } else {
        throw runtime_error("Player " + name + " does not have enough " + resource + " to remove " + to_string(amount));
    }
}

int Player::getResourceCardAmount(string resource) {
    return resourceCards[resource];
}

// the development cards are victoryPoint, roadBuilding, yearOfPlenty, monopoly, Knight.
void Player::addDevelopmentCard(string developmentCard, int amount) {
    if (developmentCard == "victoryPoint") {
        addVictoryPoints(1);
    }

    developmentCards[developmentCard] += amount;

    if (developmentCards["Knight"] >= 3) {
        addVictoryPoints(2);
    }
}

void Player::removeDevelopmentCard(string developmentCard, int amount) {
    developmentCards[developmentCard] -= amount;
}

int Player::getDevelopmentCardAmount(string developmentCard) {
    return developmentCards[developmentCard];
}

void Player::setTurn(bool turn) {
    myTurn = turn;
}

bool Player::isMyTurn() {
    return myTurn;
}

string Player::getPlayerColor() {
    if (name == "P1") {
        return "\033[1;31m";  // Red
    } else if (name == "P2") {
        return "\033[1;34m";  // Blue
    } else if (name == "P3") {
        return "\033[1;32m";  // Green
    } else {
        return "\033[1;37m";  // White
    }
}

// iterator goes through the resource cards and prints the amount of each resource
void Player::printResources() {
    cout << this->getPlayerColor() << name << "\033[0m" << " Resources: ";
    for (auto it = resourceCards.begin(); it != resourceCards.end(); ++it) {
        if (it != resourceCards.begin()) {
            cout << " - ";
        }
        cout << "[" << it->first << ", " << it->second << "]";
    }
    cout << endl;
}

void Player::printDevelopmentCards() {
    cout << "P1 Development Cards: ";
    for (auto it = developmentCards.begin(); it != developmentCards.end(); ++it) {
        if (it != developmentCards.begin()) {
            cout << " - ";
        }
        cout << "[" << it->first << ", " << it->second << "]";
    }
    cout << endl;
}

void Player::printPlayerInfo() {
    cout << this->getPlayerColor() << name << "\033[0m" << "\nResources: ";
    for (auto it = resourceCards.begin(); it != resourceCards.end(); ++it) {
        if (it != resourceCards.begin()) {
            cout << " - ";
        }
        cout << "[" << it->first << ", " << it->second << "]";
    }
    cout << endl;
    cout << "Development Cards: ";
    for (auto it = developmentCards.begin(); it != developmentCards.end(); ++it) {
        if (it != developmentCards.begin()) {
            cout << " - ";
        }
        cout << "[" << it->first << ", " << it->second << "]";
    }
    cout << "[Victory Points: " << victoryPoints << "]" << endl;
    cout << "Roads placed counter: " << roads_placed_counter << "\n";
    cout << "Settlements placed counter: " << settlements_placed_counter << endl;
    cout << "Cities placed counter: " << cities_placed_counter << endl;
}
