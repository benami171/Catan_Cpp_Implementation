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
        {23, 24, 34, 40, 39, 33}, {25, 26, 35, 42, 41, 34}, {27, 28, 36, 44, 43, 35}, {29, 30, 37, 46, 45, 36}, {31, 32, 38, 48, 47, 37},     
                        {40, 41, 50, 55, 54, 49}, {42, 43, 51, 57, 56, 50}, {44, 45, 52, 59, 58, 51}, {46, 47, 53, 61, 60, 52},           
                                            {55, 56, 63, 67, 66, 62}, {57, 58, 64, 69, 68, 63}, {59, 60, 65, 71, 70, 64}       
    };

    for (int i = 0; i < 19; ++i) {
        array<structurePlace*, 6> sPlaces;
        array<roadPlace*, 6> rPlaces;

        for (int j = 0; j < 6; ++j) {
            sPlaces[j] = &structurePlaces[tileStructureIndices[i][j]];
            rPlaces[j] = &roadPlaces[tileRoadIndices[i][j]];
        }

        tiles[i] = Tile(landTypes[i], activationNumbers[i], sPlaces, rPlaces); 
    }


    // defining the neihbors of each structure and road place

    structurePlaces[0].setAdjStructs({&structurePlaces[2], &structurePlaces[3]});
    structurePlaces[0].setAdjRoads({&roadPlaces[0], &roadPlaces[1]});
    structurePlaces[1].setAdjStructs({&structurePlaces[4], &structurePlaces[5]});
    structurePlaces[1].setAdjRoads({&roadPlaces[2], &roadPlaces[3]});
    structurePlaces[2].setAdjStructs({&structurePlaces[5], &structurePlaces[6]});
    structurePlaces[2].setAdjRoads({&roadPlaces[4], &roadPlaces[5]});
    structurePlaces[3].setAdjStructs({&structurePlaces[0], &structurePlaces[7]});
    structurePlaces[3].setAdjRoads({&roadPlaces[0], &roadPlaces[6]});
    structurePlaces[4].setAdjStructs({&structurePlaces[0], &structurePlaces[1], &structurePlaces[8]});
    structurePlaces[4].setAdjRoads({&roadPlaces[1], &roadPlaces[2], &roadPlaces[7]});
    structurePlaces[5].setAdjStructs({&structurePlaces[1], &structurePlaces[2], &structurePlaces[9]});
    structurePlaces[5].setAdjRoads({&roadPlaces[3], &roadPlaces[4], &roadPlaces[8]});
    structurePlaces[6].setAdjStructs({&structurePlaces[2], &structurePlaces[10]});
    structurePlaces[6].setAdjRoads({&roadPlaces[5], &roadPlaces[9]});
    structurePlaces[7].setAdjStructs({&structurePlaces[3], &structurePlaces[12], &structurePlaces[11]});
    structurePlaces[7].setAdjRoads({&roadPlaces[6], &roadPlaces[11], &roadPlaces[10]});
    structurePlaces[8].setAdjStructs({&structurePlaces[4], &structurePlaces[13], &structurePlaces[12]});
    structurePlaces[8].setAdjRoads({&roadPlaces[7], &roadPlaces[13], &roadPlaces[12]});
    structurePlaces[9].setAdjStructs({&structurePlaces[5], &structurePlaces[14], &structurePlaces[13]});
    structurePlaces[9].setAdjRoads({&roadPlaces[8], &roadPlaces[15], &roadPlaces[14]});
    structurePlaces[10].setAdjStructs({&structurePlaces[6], &structurePlaces[15]});
    structurePlaces[10].setAdjRoads({&roadPlaces[9], &roadPlaces[17], &roadPlaces[16]});
    



    // tiles[0].setResourceAndNumber("Mountains", 10);
    // tiles[1].setResourceAndNumber("Pasture", 2);
    // tiles[2].setResourceAndNumber("Forrest", 9);
    // tiles[3].setResourceAndNumber("Fields", 12);
    // tiles[4].setResourceAndNumber("Hills", 6);
    // tiles[5].setResourceAndNumber("Pasture", 4);
    // tiles[6].setResourceAndNumber("Hills", 10);
    // tiles[7].setResourceAndNumber("Fields", 9);
    // tiles[8].setResourceAndNumber("Forrest", 11);
    // tiles[9].setResourceAndNumber("Desert", 0);
    // tiles[10].setResourceAndNumber("Forrest", 3);
    // tiles[11].setResourceAndNumber("Mountains", 8);
    // tiles[12].setResourceAndNumber("Forrest", 8);
    // tiles[13].setResourceAndNumber("Mountains", 3);
    // tiles[14].setResourceAndNumber("Fields", 4);
    // tiles[15].setResourceAndNumber("Pasture", 5);
    // tiles[16].setResourceAndNumber("Hills", 5);
    // tiles[17].setResourceAndNumber("Fields", 6);
    // tiles[18].setResourceAndNumber("Pasture", 11);

  /*
                    mountains -  pasture - forrest
                        10          2         9  
                fields  -  hills  -  pasture  -  hills 
                  12         6          4          10
        fields  -  forrest  -  desert  -  forrest  -  mountains
            9        11          0           3            8
                forrest  -  mountains  -  fields -  pasture
                   8            3           4          5
                    hills  -  fields  -  pasture     
                      5         6          11
  */            



}

roadPlace* Board::getRoadPlace(int roadNumber) {
    return &roadPlaces[roadNumber];
}

structurePlace* Board::getStructurePlace(int structNumber) {
    return &structurePlaces[structNumber];
}

} // namespace Catan


