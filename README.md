# Catan implementation in C++

## Board Class:

My catan board is represented by two vectors.
The first one is a vector of structurePlace objects of size 54 and vector roadPlaces of size 72. the structurePlaces vector represents the nodes and the roadPlaces vector represents the edges of the board.
Each node and edge on the board were assigned a number, and the road/structure that represents them will be accessed through the vector in their matching number in the vectors, for example if i want to access node number 12 i will go to structurePlaces[12].
The board is hard-coded, theres no randomization.

### Understanding the Board Representation in the Code:
- each `Yellow` number represents the number of the node in the structurePlace vector.
- each `Blue` number represents the number of the edge in the roadPlace vector.
![image](https://github.com/benami171/System_Programming2_Exe3/assets/102553622/fca93a22-6bbf-4340-90fd-3be06fadc4de)

### Inheritance and Development Cards:
In this assignment,I have implemented a hierarchy of development cards in the Catan game using inheritance. The base class developmentCard provides a common interface and shared functionality for all specific types of development cards. The derived classes, such as knightCard, monopolyCard, roadBuildingCard, victoryPointCard, and yearOfPlentyCard, each extend the base class to provide specific behavior for each card type.

### Rules Adaptations in My Implementation
- `trade`: The current player selects the resources they want to give and receive and the player they want to trade with. If both players have the required resources, the trade is executed.
- `knight`: According to the assignment guidelines, the knight is only used to gather knights for the largest army card.
- `knight cards amount`: based on the task readme, we have 3 knight cards in the game deck.

## Usage Guidance
- To compile and run the program use `make catan`
- To compile and run the tests use `make test`

## Future Improvements:
- Would like to make the game interactive between the cpu and a user.
- Reorganize the dependancies in the game, there is actually no need in tiles representation if we really think about it..
- Currently the game board is predetermined, would like to make it random.

## Contributions:
Feel free to suggest any improvements, you can contact me via massages on Github or through my E-mail: benami171@gmail.com.
