// represents a catan playar, should have the following fields:
// - name: string, the name of the player.
// - resources: map<string, int>, the resources the player has, the key is the name of the resource, and the value is the amount of the resource.
// - points: int, the points the player has.
// - citiesAvailable: int, the number of cities the player can build starts from 4.
// - settlementsAvailable: int, the number of settlements the player can build starts from 5.
// - roadsAvailable: int, the number of roads the player can build starts from 15.
// methods:
// - placeSettelemnt(vector<string> places, vector<int> placesNum, Board board): void, places a settlement in the given places with the given numbers.
// - placeRoad(vector<string> places, vector<int> placesNum, Board board): void, places a road in the given places with the given numbers.
// - rollDice(): void, rolls the dice and gives the resources to the player.
// - endTurn(): void, ends the turn of the player.
// - getName(): string, returns the name of the player.
// - getResources(): map<string, int>, returns the resources the player has.
// - getPoints(): int, returns the points the player has.


#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "catanTile.hpp"
#include "Board.hpp"


using namespace std;

namespace CatanGame
{
    class Player
    {
    private:
        string name;
        map<string, int> resources;
        int points;
        int citiesAvailable;
        int settlementsAvailable;
        int roadsAvailable;
        bool myTurn;

    public:
        Player(string name);
        void placeSettelemnt(vector<string> places, vector<int> placesNum, Board &board);
        void placeRoad(vector<string> places, vector<int> placesNum, Board &board);
        void rollDice();
        void endTurn();
        bool offerTrade(Player player,string give, string take, int giveAmount, int getAmount);
        bool ansTrade(Player player,string give, string take, int giveAmount, int getAmount);
        string getName();
        map<string, int> getResources();

        int getPoints();

    };
} // namespace ariel

#endif