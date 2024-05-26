#include <vector>
#include <string>
#include "Player.hpp"
#include "ResourceCard.hpp"
#include "DevelopmentCard.hpp"

class Catan {
private:
    std::vector<Player> players; // List of existing players
    std::vector<ResourceCard> resourceBank; // Bank with resource cards
    std::vector<DevelopmentCard> developmentBank; // Bank with development cards

public:
    Catan() {
        // Initialize the players, resource bank, and development bank
        // You can use the constructors of Player, ResourceCard, and DevelopmentCard classes here
    }

    void initializeBoard() {
        // Initialize the game board
    }

    void rollDice() {
        // Generate a random number between 2 and 12
    }

    void distributeCards(int diceNumber) {
        // Distribute resource cards to players based on the dice number
    }

    void addPlayer(const Player& player) {
        // Add a player to the list of existing players
        // You can check the maximum number of players (3) before adding
    }

    void removePlayer(const Player& player) {
        // Remove a player from the list of existing players
    }

    void addResourceCard(const ResourceCard& card) {
        // Add a resource card to the resource bank
    }

    void removeResourceCard(const ResourceCard& card) {
        // Remove a resource card from the resource bank
    }

    void addDevelopmentCard(const DevelopmentCard& card) {
        // Add a development card to the development bank
    }

    void removeDevelopmentCard(const DevelopmentCard& card) {
        // Remove a development card from the development bank
    }

    // Add more methods and fields according to the rules of the Catan game
};