class LargestArmyCard {
private:
    int playerID;
    int armySize;

public:
    LargestArmyCard(int playerID, int armySize) {
        this->playerID = playerID;
        this->armySize = armySize;
    }

    int getPlayerID() const {
        return playerID;
    }

    int getArmySize() const {
        return armySize;
    }

    void setPlayerID(int playerID) {
        this->playerID = playerID;
    }

    void setArmySize(int armySize) {
        this->armySize = armySize;
    }
};