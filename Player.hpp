
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

    string getPlayerColor() ;

    string getName();

    int getVictoryPoints();

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

    // iterator goes through the resource cards and prints the amount of each resource
    void printResources();

    void printDevelopmentCards();

    void printPlayerInfo();

    void placeRoad(int road_index);
};
}  // namespace Catan

#endif  // PLAYER_HPP