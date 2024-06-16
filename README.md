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



## הסבר על התאמת החוקים למימוש שלי
- `trade`: השחקן בעל התור הנוכחי בוחר איזה משאבים הוא רוצה לתת ולקבל ועם איזה שחקן לבצע את ההחלפה ובמידה ולשני השחקנים יש את המשאבים הנדרשים הטרייד יתבצע

- `knight`: בהתאם להנחיות במטלה, אין שימוש באביר אלא על מנת לאסוף אותו כדי לקבל את קלף הצבא הכי גדול
