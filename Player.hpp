#include <cstdlib>  // for rand() and srand()
#include <iostream>
#include <set>
#include <vector>
#include <array>
#include <string>
#include <unordered_map>
#ifndef PLAYER_HPP
#define PLAYER_HPP

using namespace std;

namespace Catan {

class Tile;
class Board;
class Player {
   private:
    string name;
    string playerColor;
    int initialSettlementNumber;
    int initialRoadNumber;
    int victoryPoints;
    int roads_placed_counter;
    int settlements_placed_counter;
    int cities_placed_counter;
    vector<int> owned_roads_indices;
    vector<int> owned_settlements_indices;
    vector<int> owned_cities_indices;

    unordered_map<string, int> resourceCards;
    unordered_map<string, int> developmentCards;

   public:
   Player();

    Player(string name);

    string getPlayerColor() ;

    string getName();

    void addVictoryPoints(int points);

    void removeVictoryPoints(int points);

    // the resources are brick, lumber, wool, grain, ore
    void addResourceCard(string resource, int amount);

    void removeResourceCard(string resource, int amount);

    // the development cards are victoryPoint, roadBuilding, yearOfPlenty, monopoly
    // wasnt asked to implement the knight card.
    void addDevelopmentCard(string developmentCard, int amount);

    void removeDevelopmentCard(string developmentCard, int amount);

    int getResourceCardAmount(string resource);

    int getDevelopmentCardAmount(string developmentCard);

    int getVictoryPoints();

    int getSettlementsPlacedCounter();

    int getCitiesPlacedCounter();

    int getRoadsPlacedCounter();

    int getInitialSettlementsCounter();

    int getInitialRoadsCounter();

    // iterator goes through the resource cards and prints the amount of each resource
    void printResources();

    void printDevelopmentCards();

    void printPlayerInfo();

    void placeRoad(int roadPlace_index,Board& board);

    void placeInitialRoad(int roadPlace_index,Board& board);

    void placeSettlement(int structPlace_index,Board& board);

    void placeInitialSettlement(int structPlace_index,Board& board);

    void placeCity(int structPlace_index,Board& board);

    int rollDice();

    void getResouces(int diceRoll,Board& board);

    void getInitResourcesFromTile(Tile* tile);

    void getInitResources(Board& board);
};

}  // namespace Catan

#endif  // PLAYER_HPP