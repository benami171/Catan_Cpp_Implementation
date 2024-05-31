
#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;

namespace Catan{

    class Player{

        private:
        string name;
        int victoryPoints;
        unordered_map<string, int> resourceCards;
        unordered_map<string, int> developmentCards;



        public:
        Player(string name){
            this->name = name;
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

        void addResourceCard(string resource, int amount){
            resourceCards[resource] += amount;
        }

        void removeResourceCard(string resource, int amount){
            resourceCards[resource] -= amount;
        }

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

        void printPlayerInfo(){
            cout << "Player: " << name << endl;
            cout << "Victory Points: " << victoryPoints << endl;
            cout << "Resource Cards: " << endl;
            for(auto it = resourceCards.begin(); it != resourceCards.end(); it++){
                cout << it->first << ": " << it->second << endl;
            }
            cout << "Development Cards: " << endl;
            for(auto it = developmentCards.begin(); it != developmentCards.end(); it++){
                cout << it->first << ": " << it->second << endl;
            }
        }

        
    };
}