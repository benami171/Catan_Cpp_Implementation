#include "Player.hpp"
#include "Board.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "City.hpp"
#include "Catan.hpp"
// #include "Road.hpp"
// #include "Settlement.hpp"

using namespace std;

namespace CatanGame
{
    Player::Player(string name) : name(name), points(0), citiesAvailable(4), settlementsAvailable(5),roadsAvailable(15)
    {
        this->resources["wood"] = 0;
        this->resources["bricks"] = 0;
        this->resources["ore"] = 0;
        this->resources["wool"] = 0;
        this->resources["wheat"] = 0;
    }

    void Player::placeSettelemnt(vector<string> places, vector<int> placesNum, Board &board)
    {
        if (this->myTurn)
        // Implement the logic to place a settlement on the board
    }

    void Player::placeRoad(vector<string> places, vector<int> placesNum, Board &board)
    {
        if (this->myTurn)
        // Implement the logic to place a road on the board
    }

    void Player::rollDice()
    {
        if (this->myTurn)
        {
            /* code */
        }
        

    }

    bool Player::offerTrade(Player player, string give, string take, int giveAmount, int getAmount)
    {
        if (this->myTurn)
        // offer a trade to another player and wait for his response
        cout << "Player " << this->name << " offered << " << giveAmount << " " << give << " for " << getAmount << " " << take << " to player " << player.getName() << endl;
        if (player.ansTrade(*this, give, take, giveAmount, getAmount))
        {
            cout << "Player " << player.getName() << " accepted the trade" << endl;
            return true;
        }
        else
        {
            cout << "Player " << player.getName() << " declined the trade" << endl;
            return false;
        }
    }

    bool Player::ansTrade(Player player, string give, string take, int giveAmount, int getAmount)
    {
        // accept the trade from another player
        cout << "Player " << this->name << " received an offer from player " << player.getName() << " to give " << giveAmount << " " << give << " for " << getAmount << " " << take << endl;
        cout << "Do you accept the trade? (y/n)" << endl;
        char response;
        cin >> response;
        if (response == 'y')
        {
            cout << "Trade accepted" << endl;
            return true;
        }
        else
        {
            cout << "Trade declined" << endl;
            return false;
        }
    }

    void Player::endTurn()
    {
        if (this->myTurn){
            this->myTurn = false;
            catan.nextTurn();
        }
    
        
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