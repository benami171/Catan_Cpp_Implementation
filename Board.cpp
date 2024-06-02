#include "Board.hpp"

#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

#include "roadPlace.hpp"
#include "structurePlace.hpp"

using namespace std;

namespace Catan {
Board::Board() {
    for (size_t i = 0; i < structurePlaces.size(); i++) {
        structurePlaces[i] = structurePlace("", "", i);
    }
    for (size_t i = 0; i < roadPlaces.size(); i++) {
        roadPlaces[i] = roadPlace("", i);
    }
}

void Board::printBoard() {
    
}

void Board::initBoard() {
    // Initialize structurePlaces and roadPlaces using their default constructors
    structurePlaces.fill(structurePlace());
    roadPlaces.fill(roadPlace());

    // Define the structure and road place indices for each tile
    const int tileStructureIndices[19][6] = {
                                            {0, 4, 8, 12, 7, 3}, {1, 5, 9, 13, 8, 4}, {2, 6, 10, 14, 9, 5},                 
                        {7, 12, 17, 22, 16, 11}, {8, 13, 18,23,17,12}, {9, 14, 19, 24, 18, 13}, {10, 15, 20, 25, 19, 14},            
        {16, 22, 28, 33, 27, 21}, {17, 23, 29, 34, 28, 22}, {18, 24, 30, 35, 29, 23}, {19, 25, 31, 36, 30, 24}, {20, 26, 32, 37, 31, 35},             
                        {28, 34, 39, 43, 38, 33}, {29, 35, 40, 44, 39, 34}, {30, 36, 41, 45, 40, 35},{31, 37, 42, 46, 41, 36},                   
                                            {39, 44, 48, 51, 47, 43}, {40, 45, 49, 52, 48, 44}, {41, 46, 50, 53, 49, 45}                             
    };

    const int tileRoadIndices[19][6] = {
                                            {0, 1, 7, 12, 11, 6}, {2, 3, 8, 14, 13, 7}, {4, 5, 9, 16, 15, 8},
                        {10, 11, 19, 25, 24, 18}, {12, 13, 20, 27, 26, 19}, {14, 15, 21, 29, 28, 20}, {16, 17, 22, 31, 30, 21}, 
        {23, 24, 34,40,39,33}, {25,26,35,42,41,34}, {27,28,36,44,43,35}, {29, 30, 37, 46, 45, 36,}, {52, 58, 64, 63, 69, 70},
                        {55, 61, 67, 66, 72, 73}, {57, 63, 69, 75, 70, 64}, {62, 68, 74, 80, 75, 69}, {65, 71, 77, 83, 78, 72}, 
                                            {66, 72, 78, 84, 79, 73}, {73, 79, 85, 91, 86, 80}, {74, 80, 86, 92, 87, 81}
    };

    for (int i = 0; i < 19; ++i) {
        array<structurePlace*, 6> sPlaces;
        array<roadPlace*, 6> rPlaces;

        for (int j = 0; j < 6; ++j) {
            sPlaces[j] = &structurePlaces[tileStructureIndices[i][j]];
            rPlaces[j] = &roadPlaces[tileRoadIndices[i][j]];
        }

        tiles[i] = Tile("resourceType", i + 2, sPlaces, rPlaces);  // Example initialization
    }
}
} // namespace Catan


