# Catan implementation in C++

## Board class:

My catan board is represented by two vectors.
The first one is a vector of structurePlace objects of size 54 and vector roadPlaces of size 72. the structurePlaces vector represents the nodes and the roadPlaces vector represents the edges of the board.
Each node and edge on the board were assigned a number, and the road/structure that represents them will be accessed through the vector in their matching number in the vectors, for example if i want to access node number 12 i will go to structurePlaces[12].

this is how the board is referred to:
- each `Yellow` number represents the number of the node in the structurePlace vector.
- each `Blue` number represents the number of the edge in the roadPlace vector.
![image](https://github.com/benami171/System_Programming2_Exe3/assets/102553622/fca93a22-6bbf-4340-90fd-3be06fadc4de)

### Board class fields:
- `vector<structurePlace> structurePlaces` - represents nodes on the board.
- `vector<roadPlace> roadPlaces` - represents edges on the board.
- `vector<Tile> tiles` - represents tiles on the board.

### Board class methods:
- private methods:
 - `void initStructurePlaces()`: initialize structurePlaces vector.
 - `void initRoadPlaces()`: initialize roadPlaces vector.
 - `void setupAdjacencies()`: sets the adjacent nodes and edges to each node and edge.
 - `void initTiles()` : initialize 19 tiles. each tile gets the specific land type, activation number, pointers to the matching nodes and edges in the board.
 - all of the methods that are mention above will be called by the constructor.

- public methods:
 - `Board()`: uses `void initStructurePlaces()`,`void initRoadPlaces()`,`void setupAdjacencies()`,`void initTiles()`. will be called by CatanGame.
 - `roadPlace* getRoadAt(int roadNumber)`: returns the ith roadPlace in the roadPlaces array
 - `structurePlace* getStructureAt(int structNumber)`: returns the ith structurePlace in the structurePlaces array
 - `Tile* getTileAt(int tileNumber)`: returns the ith tile in the tiles array
 - `const vector<structurePlace>& getStructurePlaces() const`: returns a reference to the structurePlaces vector. 
 - `const vector<roadPlace>& getRoadPlaces() const`: returns a reference to the roadPlaces vector.
 - `const vector<Tile>& getTiles() const`: returns a reference to the Tiles vector.
 - `void printBoard()`: prints the board.

## CatanGame class:
this class meant to manage the proccess of the game, look for a winner after certain moves, distribute resources after dice rolls, etc.

### CatanGame fields:
- `int turnCounter`: count turn number, will be used when player buys a deevelopment card, the card gets the turn number he was bought in.
- `string currentPlayerTurn`: the name of the player currently playing.
- `vector<Player*> players`: holds pointer to each player object.
- `Board board`: holds a board to interact with, that board will be played on.
- `unordered_map<string, int> resourceCardsLeft`: the resource cards bank.
- `unordered_map<string, int> developmentCardsLeft`: the development cards bank.

### CatanGame methods:
- `CatanGame(Player& player1, Player& player2, Player& player3)`: constructor gets references to each player object.
- `Board& getBoard()`
- `vector<Player*>& getPlayers()`
- `int getTurnCounter()`: returns the turn number.
- `string getCurrentPlayerTurn()`: return whos playing currently.
- `int developmentCardsRemaining(string card)`: return how many cards left of a specific type.
- `void printBoard()`: uses the Board's print method.
- `void printPlayersStats()`: prints all the available information about each player.
- `void printPlayersResources()`: prints the resources of each player.
- `void distributeResources(int dice)`: distribute the resources each player supposed to get based on the dice roll result.
- `void startTurn(string playerName)`: used one time in the start of the game.
- `void checkLargestArmy()`: check if there is any player with 3 knights.
- `void endTurn()`: sets the current player myTurn flag to false and the next player flag to true.
- `void checkEndGame()`: check if there is any player that reached 10 points.
- `void giveResources()`:ONLY USED FOR TESTING. distribute 5 of each resource to the players.
- `bool buyDevelopmentCard(string card, Player& player)`: If the player has enough resources to buy a development card and if there are any development cards of the preffered type left return true, false otherwise.

## Player class:
represents a player in the game, holds all the functionality needed to play the game.
### Player fields:
- `string name`: The player's name.
- `bool myTurn`: A flag indicating if it's the player's turn.
- `string playerColor`: The color assigned to the player.
- `int initialSettlementNumber`: The number of initial settlements the player has placed.
- `int initialRoadNumber`: The number of initial roads the player has placed.
- `int victoryPoints`: The player's current victory points.
- `int roads_placed_counter`: A counter for the number of roads placed by the player.
- `int settlements_placed_counter`: A counter for the number of settlements placed by the player.
- `int cities_placed_counter`: A counter for the number of cities placed by the player.
- `int freeRoads`: The number of free roads the player can place. used when player uses the roadBuilding development card.
- `vector<int> owned_roads_indices`: The indices of the roads owned by the player.
- `vector<int> owned_structures_indices`: The indices of the structures owned by the player.
- `vector<int> owned_cities_indices`: The indices of the cities owned by the player.
- `unordered_map<string, int> resourceCards`: The amount of resource cards the player holds.
- `unordered_map<string, int> developmentCards`: The amount of development cards the player holds.
- `vector<monopolyCard> monopolyCards`: The monopoly development cards the player holds.
- `vector<roadBuildingCard> roadBuildingCards`: The road building development cards the player holds.
- `vector<victoryPointCard> victoryPointCards`: The victory point development cards the player holds.
- `vector<knightCard> knightCards`: The knight cards the player holds.
- `vector<yearOfPlentyCard> yearOfPlentyCards`: The year of plenty development cards the player holds.

### Player methods:
- `Player()`: Default constructor.
- `Player(string name)`: Constructor with player name.
- `string getPlayerColor()`: Returns the player's color, each player have different color based on his name.
- `string getName()`: Returns the player's name.
- `void addVictoryPoints(int points)`: Adds victory points to the player.
- `void addFreeRoads(int roads)`: Adds free roads to the player.
- `void removeVictoryPoints(int points)`: Removes victory points from the player.
- `void addResourceCard(string resource, int amount)`: Adds resource cards to the player.
- `void removeResourceCard(string resource, int amount)`: Removes resource cards from the player.
- `void addDevelopmentCard(string developmentCard, int amount)`: Adds development cards to the player.
- `void removeDevelopmentCard(string developmentCard, int amount)`: Removes development cards from the player.
- `int getResourceCardAmount(string resource)`: Gets the amount of a specific resource card.
- `int getDevelopmentCardAmount(string developmentCard)`: Gets the amount of a specific development card.
- `int getVictoryPoints()`: Returns the player's victory points.
- `int getFreeRoads()`: Returns the number of free roads the player can place.
- `int getSettlementsPlacedCounter()`: Returns the number of settlements placed by the player.
- `int getCitiesPlacedCounter()`: Returns the number of cities placed by the player.
- `int getRoadsPlacedCounter()`: Returns the number of roads placed by the player.
- `int getInitialSettlementsCounter()`: Returns the number of initial settlements placed by the player.
- `int getInitialRoadsCounter()`: Returns the number of initial roads placed by the player.
- `void printResources()`: Prints the amount of each resource the player holds.
- `void printDevelopmentCards()`: Prints the development cards the player holds.
- `void printPlayerInfo()`: Prints all the player's information.
- `void placeRoad(int roadPlace_index, CatanGame& game)`: Places a road at the specified index.
- `bool placeFreeRoad(int roadPlace_index, CatanGame& game)`: Places a free road at the specified index.
- `void placeInitialRoad(int roadPlace_index, CatanGame& game)`: Places an initial road at the specified index.
- `void placeSettlement(int structurePlace_index, CatanGame& game)`: Places a settlement at the specified index.
- `void placeInitialSettlement(int structurePlace_index, CatanGame& game)`: Places an initial settlement at the specified index.
- `void placeCity(int structurePlace_index, CatanGame& game)`: Places a city at the specified index.
- `int rollDice()`: Rolls the dice.
- `int rollDice(int wantedNumber)`: Rolls the dice to get a specific number (used in tests).
- `void setTurn(bool turn)`: Sets the player's turn.
- `bool isMyTurn()`: Checks if it's the player's turn.
- `void getResources(int diceRoll, Board& board)`: Distributes resources to the player based on the dice roll.
- `void getInitResourcesFromTile(Tile* tile)`: Gets initial resources from the specified tile.
- `void getInitResources(Board& board)`: Gets initial resources from the board.
- `void payToll()`: Pays a toll.
- `bool buyDevelopmentCard(string card, CatanGame& game)`: Buys a development card.
- `bool useMonopoly(string chosenResource, CatanGame& game)`: Uses a monopoly card.
- `bool useYearOfPlenty(string resource1, string resource2, CatanGame& game)`: Uses a year of plenty card.
- `bool useRoadBuilding(int road1, int road2, CatanGame& game)`: Uses a road building card.
- `bool trade(unordered_map<string, int> giveResources, unordered_map<string, int> receiveResources, Player& otherPlayer)`: Trades resources with another player.
- `bool tradeWithBank(unordered_map<string, int> giveResources, unordered_map<string, int> receiveResources, CatanGame& game)`: Trades resources with the bank.

## structurePlace class:
represents each node on the board.

### structurePlace fields:



## Explanation of Rule Adaptations for My Implementation
- `trade`: The current player selects the resources they want to give and receive and the player they want to trade with. If both players have the required resources, the trade is executed.
- `knight`: According to the assignment guidelines, the knight is only used to gather knights for the largest army card.
- `knight cards amount`: based on the task readme, we have 3 knight cards in the game deck.