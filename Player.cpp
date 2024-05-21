#include "Player.hpp"
using namespace std;

namespace ariel
{
    Player::Player(string name) : name(name)
    {
        this->name = name;
        this->points = 0;
        this->citiesAvailable = 4;
        this->settlementsAvailable = 5;
        this->roadsAvailable = 15;
        this->resources["wood"] = 0;
        this->resources["bricks"] = 0;
        this->resources["ore"] = 0;
        this->resources["wool"] = 0;
        this->resources["wheat"] = 0;

    }

    void Player::placeSettelemnt(vector<string> places, vector<int> placesNum, Board &board)
    {
        // Implement the logic to place a settlement on the board
    }

    void Player::placeRoad(vector<string> places, vector<int> placesNum, Board &board)
    {
        // Implement the logic to place a road on the board
    }

    void Player::rollDice()
    {
        // Implement the logic to roll the dice and give resources to the player
    }

    void Player::trade(Player player, string give, string take, int giveAmount, int takeAmount)
    {
        // Implement the logic to trade resources with another player
    }

    void Player::endTurn()
    {
        // Implement the logic to end the turn of the player
    }

    string Player::getName()
    {
        return this->name;
    }

    map<string, int> Player::getResources()
    {
        return this->resources;
    }

    int Player::getPoints()
    {
        return this->points;
    }
} // namespace ariel