#pragma once

#include <array>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include "developmentCard.hpp"
#include "knightCard.hpp"
#include "monopolyCard.hpp"
#include "roadBuildingCard.hpp"
#include "victoryPointCard.hpp"
#include "yearOfPlentyCard.hpp"

using namespace std;

namespace Catan {

class Tile;
class Board;
class CatanGame;
class Player {
   private:
    string name;
    bool myTurn;
    string playerColor;
    int initialSettlementNumber;
    int initialRoadNumber;
    int victoryPoints;
    int roads_placed_counter;
    int settlements_placed_counter;
    int cities_placed_counter;
    int freeRoads;
    vector<int> owned_roads_indices;
    vector<int> owned_structures_indices;
    vector<int> owned_cities_indices;

    unordered_map<string, int> resourceCards;
    unordered_map<string, int> developmentCards;
    vector<monopolyCard> monopolyCards;
    vector<roadBuildingCard> roadBuildingCards;
    vector<victoryPointCard> victoryPointCards;
    vector<knightCard> knightCards;
    vector<yearOfPlentyCard> yearOfPlentyCards;

   public:
    Player();
    Player(string name);

    bool hasLargestArmy;
    string getPlayerColor();
    string getName();
    void addVictoryPoints(int points);
    void addFreeRoads(int roads);
    void removeVictoryPoints(int points);

    // the resources are brick, lumber, wool, wheat, ore
    void addResourceCard(string resource, int amount);

    void removeResourceCard(string resource, int amount);

    // the development cards are victoryPoint, roadBuilding, yearOfPlenty, monopoly
    // wasnt asked to implement the knight card.
    void addDevelopmentCard(string developmentCard, int amount);

    void removeDevelopmentCard(string developmentCard, int amount);

    int getResourceCardAmount(string resource);

    int getDevelopmentCardAmount(string developmentCard);

    int getVictoryPoints();

    int getFreeRoads();

    int getSettlementsPlacedCounter();

    int getCitiesPlacedCounter();

    int getRoadsPlacedCounter();

    int getInitialSettlementsCounter();

    int getInitialRoadsCounter();

    // iterator goes through the resource cards and prints the amount of each resource
    void printResources();

    void printDevelopmentCards();

    void printPlayerInfo();

    void placeRoad(int roadPlace_index, Board& board);

    bool placeFreeRoad(int roadPlace_index, Board& board);

    void placeInitialRoad(int roadPlace_index, Board& board);

    void placeSettlement(int structPlace_index, Board& board);

    void placeInitialSettlement(int structPlace_index, Board& board);

    void placeCity(int structPlace_index, Board& board);

    int rollDice();
    int rollDice(int wantedNumber); // this will be used in tests.

    void setTurn(bool turn);

    bool isMyTurn();

    void getResources(int diceRoll, Board& board);

    void getInitResourcesFromTile(Tile* tile);

    void getInitResources(Board& board);
    void payToll();
    bool buyDevelopmentCard(string card, CatanGame& game, int turnBoughtIn);

    bool useDevelopmentCard(string card,string chosenResource, CatanGame& game);
    
    template <typename T>
    bool useCardIfEligible(vector<T>& cards, CatanGame& game);
    bool useMonopoly(string chosenResource,CatanGame& game); // seperated monopoly because it needs access to be used differentley.
    bool useYearOfPlenty(string resource1,string resource2, CatanGame& game);
    bool useRoadBuilding(int road1, int road2,CatanGame& game);
    bool trade(unordered_map<string, int> giveResources, unordered_map<string, int> receiveResources, Player& otherPlayer);
    bool tradeWithBank(unordered_map<string, int> giveResources, unordered_map<string, int> receiveResources, CatanGame& game);
};

}  // namespace Catan

