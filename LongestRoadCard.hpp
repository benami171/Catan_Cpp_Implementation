class LongestRoadCard {
private:
    int playerID;
    int roadSize;

public:
    LongestRoadCard(int playerID, int roadSize) {
        this->playerID = playerID;
        this->roadSize = roadSize;
    }

    int getPlayerID() const {
        return playerID;
    }

    int getRoadSize() const {
        return roadSize;
    }

    void setPlayerID(int playerID) {
        this->playerID = playerID;
    }

    void setRoadSize(int armySize) {
        this->roadSize = roadSize;
    }
};