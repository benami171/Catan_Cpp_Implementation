# Catan implementation in C++

## Board Class:

My catan board is represented by two vectors.
The first one is a vector of structurePlace objects of size 54 and vector roadPlaces of size 72. the structurePlaces vector represents the nodes and the roadPlaces vector represents the edges of the board.
Each node and edge on the board were assigned a number, and the road/structure that represents them will be accessed through the vector in their matching number in the vectors, for example if i want to access node number 12 i will go to structurePlaces[12].
The board is hard-coded, theres no randomization.

### Understanding the board representation in the code:
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

## CatanGame Class:
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

## Player Class:
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
- `Player(string name)`: Constructor initializing the player with a given name.
- `string getPlayerColor()`: Returns the player's color, determined by their name.
- `string getName()`: Returns the player's name.
- `void addVictoryPoints(int points)`: Adds a specified number of victory points to the player.
- `void addFreeRoads(int roads)`: Adds a specified number of free roads to the player.
- `void removeVictoryPoints(int points)`: Removes a specified number of victory points from the player.
- `void addResourceCard(string resource, int amount)`: Adds a specified amount of a resource card to the player's inventory.
- `void removeResourceCard(string resource, int amount)`: Removes a specified amount of a resource card from the player's inventory.
- `void addDevelopmentCard(string developmentCard, int amount)`: Adds a specified amount of a development card to the player's inventory.
- `void removeDevelopmentCard(string developmentCard, int amount)`: Removes a specified amount of a development card from the player's inventory.
- `int getResourceCardAmount(string resource)`: Returns the amount of a specific resource card the player possesses.
- `int getDevelopmentCardAmount(string developmentCard)`: Returns the amount of a specific development card the player possesses.
- `int getVictoryPoints()`: Returns the player's current victory points.
- `int getFreeRoads()`: Returns the number of free roads the player can place.
- `int getSettlementsPlacedCounter()`: Returns the number of settlements the player has placed.
- `int getCitiesPlacedCounter()`: Returns the number of cities the player has placed.
- `int getRoadsPlacedCounter()`: Returns the number of roads the player has placed.
- `int getInitialSettlementsCounter()`: Returns the number of initial settlements placed by the player.
- `int getInitialRoadsCounter()`: Returns the number of initial roads placed by the player.
- `void printResources()`: Prints the player's current resource inventory.
- `void printDevelopmentCards()`: Prints the player's current development card inventory.
- `void printPlayerInfo()`: Prints all relevant information about the player.
- `void placeRoad(int roadPlace_index, CatanGame& game)`: Places a road at the specified index within the game.
- `bool placeFreeRoad(int roadPlace_index, CatanGame& game)`: Places a free road at the specified index within the game.
- `void placeInitialRoad(int roadPlace_index, CatanGame& game)`: Places an initial road at the specified index within the game.
- `void placeSettlement(int structurePlace_index, CatanGame& game)`: Places a settlement at the specified index within the game.
- `void placeInitialSettlement(int structurePlace_index, CatanGame& game)`: Places an initial settlement at the specified index within the game.
- `void placeCity(int structurePlace_index, CatanGame& game)`: Places a city at the specified index within the game.
- `int rollDice()`: Simulates rolling two dice and returns the result.
- `int rollDice(int wantedNumber)`: Simulates rolling dice to get a specific number (used for testing).
- `void setTurn(bool turn)`: Sets the player's turn status.
- `bool isMyTurn()`: Checks if it's currently the player's turn.
- `void getResources(int diceRoll, Board& board)`: Distributes resources to the player based on the dice roll and the current state of the board.
- `void getInitResourcesFromTile(Tile* tile)`: Acquires initial resources from a specific tile.
- `void getInitResources(Board& board)`: Acquires initial resources from the board.
- `void payToll()`: Enforces resource card penalties if a 7 is rolled.
- `bool buyDevelopmentCard(string card, CatanGame& game)`: Purchases a development card from the game.
- `bool useMonopoly(string chosenResource, CatanGame& game)`: Uses a monopoly card to collect all of a chosen resource from other players.
- `bool useYearOfPlenty(string resource1, string resource2, CatanGame& game)`: Uses a year of plenty card to gain two specified resources.
- `bool useRoadBuilding(int road1, int road2, CatanGame& game)`: Uses a road building card to place two roads.
- `bool trade(unordered_map<string, int> giveResources, unordered_map<string, int> receiveResources, Player& otherPlayer)`: Trades resources with another player.
- `bool tradeWithBank(unordered_map<string, int> giveResources, unordered_map<string, int> receiveResources, CatanGame& game)`: Trades resources with the bank based on a fixed ratio.

## structurePlace Class:
represents each node on the board.

### structurePlace fields:
- `Player* owner`: a pointer to the Player who build a settlment/city on the node.
- `string identifierString`: N FOR NONE, S FOR SETTLEMENT, C FOR CITY, also adds the player color to the string so we could use it in the board printing method.
- `string structType`: either a settlment or a city.
- `int structNumber`: each struct has his own number as we said.
- `array<structurePlace*, 3> adjStructs`: pointers to the adjacent nodes to check when player wants to build a settlement.
- `array<roadPlace*, 3> adjRoads`: pointers to adjacent edges, used as above.
- `vector<Tile*> adjTiles`: pointers to the adjacent Tiles.
- `vector<pair<string, int>> resource_activationNumber`: each node is attached to hard-coded resource type and matching activation number. 
### structurePlace methods:
- `structurePlace()`: Default constructor initializing the structure with no owner and default settings.
- `structurePlace(Player* owner, string structType, int structNumber)`: Constructor initializing the structure with a specific owner, type, and number.
- `string getOwnerString()`: Returns the name of the player who owns the structure or "initial" if it has no owner.
- `string getStructType()`: Returns the type of the structure (e.g., "SETTLEMENT", "CITY").
- `string getPrintableString()`: Returns a string representation of the structure for display purposes.
- `int getStructNumber()`: Returns the unique number assigned to the structure.
- `void addAdjTile(Tile* tile)`: Adds a tile to the list of adjacent tiles.
- `void addResourceAndActivationNumber(const string& resource, int activationNumber)`: Adds a resource and its corresponding activation number to the structure.
- `const vector<pair<string,int>>& getResourceActivationNumber() const`: Returns the list of resources and their activation numbers associated with the structure.
- `const vector<Tile*>& getAdjTiles() const`: Returns the list of adjacent tiles.
- `void setAdjStructs(array<structurePlace*, 3> adjStructs)`: Sets the adjacent structures.
- `void setAdjRoads(array<roadPlace*, 3> adjRoads)`: Sets the adjacent roads.
- `bool placedCity(Player* newOwner)`: Places a city on the structure if the conditions are met.
- `bool placedSettlement(Player* newOwner)`: Places a settlement on the structure if the conditions are met.
- `bool placedInitialSettlement(Player* newOwner)`: Places an initial settlement on the structure if the conditions are met.

## roadPlace Class:
represents an edge on the catan board.

### roadPlace fields:
- `Player* owner`:
- `int roadNumber`:
- `array<structurePlace*, 2> adjStructs`: 
- `array<roadPlace*, 4> adjRoads`:
### roadPlace methods:
- `roadPlace()`: Default constructor initializing the road with no owner and default settings.
- `roadPlace(Player* owner, int roadNumber)`: Constructor initializing the road with a specific owner and number.
- `Player* getRoadOwner()`: Returns a pointer to the player who owns the road.
- `void setOwner(Player* newOwner)`: Sets the owner of the road to the specified player.
- `string getOwnerString()`: Returns the name of the player who owns the road or "initial" if it has no owner.
- `void setAdjStructs(array<structurePlace*, 2> adjStructs)`: Sets the adjacent structures for the road.
- `void setAdjRoads(array<roadPlace*, 4> adjRoads)`: Sets the adjacent roads for the road.
- `bool placedRoad(Player* newOwner)`: Checks if the road can be placed by the specified player, and if so, sets the owner to the player.
- `bool canPlaceRoad(Player* newOwner)`: Checks if the road can be placed by the specified player.
- `int getRoadNumber()`: Returns the unique number of the road.
- `string getPrintableString()`: Returns a string representation of the road for display purposes, including the owner's color if it has an owner.

## Inheritance and development cards:
In this assignment,I have implemented a hierarchy of development cards in the Catan game using inheritance. The base class developmentCard provides a common interface and shared functionality for all specific types of development cards. The derived classes, such as knightCard, monopolyCard, roadBuildingCard, victoryPointCard, and yearOfPlentyCard, each extend the base class to provide specific behavior for each card type.

## developmentCard Class:
This is the abstract base class for all development cards in the game.

### developmentCard fields:
- `string type`: The type of the development card.
- `int turnBoughtIn`: The turn in which the card was bought.
### developmentCard methods:
- `developmentCard()`: Default constructor initializing the development card.
- `developmentCard(const string& type, int turnBoughtIn)`: Constructor initializing the development card with a specific type and turn.
- `virtual ~developmentCard()`: Virtual destructor to allow proper cleanup of derived classes.
- `string getCardCategory() const`: Returns the category of the card.
- `virtual void useCard(Player& owner) const = 0`: Pure virtual function to be implemented by derived classes, defining how the card is used.
- `int getTurnBoughtIn() const`: Returns the turn the card was bought in.


## knightCard Class:
Inherits from developmentCard and represents a knight card.

### knightCard methods:
- `knightCard(const string& type, int turnBoughtIn)`: Constructor initializing the knight card with a specific type and turn.
- `void useCard(Player& owner) const override`: Overrides the useCard method to define how the knight card is used by a player.

## monopolyCard Class:
Inherits from developmentCard and represents a monopoly card.

### monopolyCard methods:
- `monopolyCard(const string& type, int turnBoughtIn)`: Constructor initializing the monopoly card with a specific type and turn.
- `void useCard(Player& owner) const override`: Overrides the useCard method to define how the monopoly card is used by a player.
- `void useCard(Player& owner, string chosenResource, CatanGame& game) const`: Overloaded method to use the monopoly card with additional parameters for chosen resource and game context.

## roadBuildingCard Class:
Inherits from developmentCard and represents a road building card.

### roadBuildingCard methods:
- `roadBuildingCard(const string& type, int turnBoughtIn)`: Constructor initializing the road building card with a specific type and turn.
- `void useCard(Player& owner) const override`: Overrides the useCard method to define how the road building card is used by a player.

## victoryPointCard Class:
Inherits from developmentCard and represents a victory point card.

### victoryPointCard methods:
- `victoryPointCard(const string& type, int turnBoughtIn)`: Constructor initializing the victory point card with a specific type and turn.
- `void useCard(Player& owner) const override`: Overrides the useCard method to define how the victory point card is used by a player.

## yearOfPlentyCard Class:
inherits from `developmentCard` and represents a year of plenty card.

### yearOfPlentyCard methods:
- `yearOfPlentyCard(const string& type, int turnBoughtIn)`: Constructor initializing the year of plenty card with a specific type and turn.
- `void useCard(Player& owner) const override`: Overrides the useCard method to define how the year of plenty card is used by a player.

## Explanation of Rule Adaptations for My Implementation
- `trade`: The current player selects the resources they want to give and receive and the player they want to trade with. If both players have the required resources, the trade is executed.
- `knight`: According to the assignment guidelines, the knight is only used to gather knights for the largest army card.
- `knight cards amount`: based on the task readme, we have 3 knight cards in the game deck.

## Usage Guidance:
- To compile and run the program use `make catan`
- To compile and run the tests use `make test`

## future improvements:
- Would like to make the game interactive between the cpu and a user.
- Reorganize the dependancies in the game, there is actually no need in tiles representation if we really think about it..
- Currently the game board is predetermined, would like to make it random.

## Contributions:
Feel free to suggest any improvements, you can contact me via massages on Github or through my E-mail: benami171@gmail.com.
