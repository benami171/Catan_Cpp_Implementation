// this class representes a tile on the catan board it hase a type of land
// and a number that representes the number that will give resources to the players

#ifndef CATANTILE_HPP
#define CATANTILE_HPP

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

namespace CatanGame
{
    class CatanTile
    {
    private:
        string landType;
        int activationNumber;

    public:
        CatanTile(string landType, int activationNumber);
        string getLandType();
        int getNumber();
        vector<string> getPlayersOnTile(int activationNumber);
    };
}
#endif