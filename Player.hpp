
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
#ifndef PLAYER_HPP
#define PLAYER_HPP

using namespace std;

namespace Catan{

    class Player{

        private:
        string name;
        int victoryPoints;
        int roadsLeft;
        int settlementsLeft;
        int citiesLeft;
        unordered_map<string, int> resourceCards;
        unordered_map<string, int> developmentCards;



        public:
        Player(string name){
            this->name = name;
            victoryPoints = 0;
            roadsLeft = 15;
            settlementsLeft = 5;
            citiesLeft = 4;
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

        string getName(){
            return name;
        }

        int getVictoryPoints(){
            return victoryPoints;
        }

        void addVictoryPoints(int points){
            victoryPoints += points;
        }

        void removeVictoryPoints(int points){
            victoryPoints -= points;
        }

// the resources are brick, lumber, wool, grain, ore
        void addResourceCard(string resource, int amount){
            resourceCards[resource] += amount;
        }

        void removeResourceCard(string resource, int amount){
            resourceCards[resource] -= amount;
        }

// the development cards are victoryPoint, roadBuilding, yearOfPlenty, monopoly
// wasnt asked to implement the knight card.
        void addDevelopmentCard(string developmentCard, int amount){
            developmentCards[developmentCard] += amount;
        }

        void removeDevelopmentCard(string developmentCard, int amount){
            developmentCards[developmentCard] -= amount;
        }

        int getResourceCardAmount(string resource){
            return resourceCards[resource];
        }


        int getDevelopmentCardAmount(string developmentCard){
            return developmentCards[developmentCard];
        }

// iterator goes through the resource cards and prints the amount of each resource
        void printResources(){
            cout << "Resource Cards: " << endl;
            for(auto it = resourceCards.begin(); it != resourceCards.end(); it++){
                cout << it->first << ": " << it->second << endl;
            }
        }

        void printDevelopmentCards(){
            cout << "Development Cards: " << endl;
            for(auto it = developmentCards.begin(); it != developmentCards.end(); it++){
                cout << it->first << ": " << it->second << endl;
            }
        }
        
        void printPlayerInfo(){
            cout << "Player: " << name << endl;
            cout << "Victory Points: " << victoryPoints << endl;
            printDevelopmentCards();
            printResources();
        }

        
    };
}

#endif // PLAYER_HPP