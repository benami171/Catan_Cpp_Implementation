#include "Board.hpp"
#include "Tile.hpp"
#include "roadPlace.hpp"
#include "structurePlace.hpp"
#include "Player.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace Catan;

Board::Board() : structurePlaces(54), roadPlaces(72), tiles(19) {
    initStructurePlaces();
    initRoadPlaces();
    initTiles();
    setupAdjacencies();
}

/*                       THE BOARD
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

void Board::initStructurePlaces() {
    // Initialize structurePlaces and roadPlaces
    cout << "Initializing structure places..." << endl;
    for (size_t i = 0; i < structurePlaces.size(); i++) {
        structurePlaces[i] = structurePlace(nullptr, "initial", i);
    }
}

void Board::initRoadPlaces() {
    cout << "Initializing road places..." << endl;
    for (size_t i = 0; i < roadPlaces.size(); i++) {
        roadPlaces[i] = roadPlace(nullptr, i);
    }
}

void Board::initTiles() {
 cout << "Initializing tiles..." << endl;
    // Define the structure and road place indices for each tile
    const int tileStructureIndices[19][6] = {
        {0, 4, 8, 12, 7, 3}, {1, 5, 9, 13, 8, 4}, {2, 6, 10, 14, 9, 5}, {7, 12, 17, 22, 16, 11}, {8, 13, 18, 23, 17, 12}, {9, 14, 19, 24, 18, 13}, {10, 15, 20, 25, 19, 14}, {16, 22, 28, 33, 27, 21}, {17, 23, 29, 34, 28, 22}, {18, 24, 30, 35, 29, 23}, {19, 25, 31, 36, 30, 24}, {20, 26, 32, 37, 31, 35}, {28, 34, 39, 43, 38, 33}, {29, 35, 40, 44, 39, 34}, {30, 36, 41, 45, 40, 35}, {31, 37, 42, 46, 41, 36}, {39, 44, 48, 51, 47, 43}, {40, 45, 49, 52, 48, 44}, {41, 46, 50, 53, 49, 45}};

    const int tileRoadIndices[19][6] = {
        {0, 1, 7, 12, 11, 6}, {2, 3, 8, 14, 13, 7}, {4, 5, 9, 16, 15, 8}, {10, 11, 19, 25, 24, 18}, {12, 13, 20, 27, 26, 19}, {14, 15, 21, 29, 28, 20}, {16, 17, 22, 31, 30, 21}, {23, 24, 34, 40, 39, 33}, {25, 26, 35, 42, 41, 34}, {27, 28, 36, 44, 43, 35}, {29, 30, 37, 46, 45, 36}, {31, 32, 38, 48, 47, 37}, {40, 41, 50, 55, 54, 49}, {42, 43, 51, 57, 56, 50}, {44, 45, 52, 59, 58, 51}, {46, 47, 53, 61, 60, 52}, {55, 56, 63, 67, 66, 62}, {57, 58, 64, 69, 68, 63}, {59, 60, 65, 71, 70, 64}};

    for (int i = 0; i < 19; ++i) {
        vector<structurePlace*> sPlaces(6);
        vector<roadPlace*> rPlaces(6);

        // hard coding the land types and activation number for each tile.
        vector<string> landTypes = {"Mountains", "Pasture", "Forrest", "Fields", "Hills", "Pasture", "Hills", "Fields", "Forrest", "Desert", "Forrest", "Mountains", "Forrest", "Mountains", "Fields", "Pasture", "Hills", "Fields", "Pasture"};
        vector<int> activationNumbers = {10, 2, 9, 12, 6, 4, 10, 9, 11, 0, 3, 8, 8, 3, 4, 5, 5, 6, 11};

        for (int j = 0; j < 6; ++j) {
            // assigning the right structurePlaces and roadPlaces pointers array for each tile.
            // also adding the right resource to the structurePlaces.
            sPlaces[j] = &structurePlaces[tileStructureIndices[i][j]];
            // structurePlaces[tileStructureIndices[i][j]].addResource(landTypes[i]);
            // structurePlaces[tileStructureIndices[i][j]].addActivationNumber(activationNumbers[i]);
            structurePlaces[tileStructureIndices[i][j]].addResourceAndActivationNumber(landTypes[i], activationNumbers[i]);
            if (tileStructureIndices[i][j] == 25){
                cout << "To structurePlace 25 added resource: " << landTypes[i] << " and activation number: " << activationNumbers[i] << endl;
            }
            // cout << " StructPlace's index: " << tileStructureIndices[i][j] << " adjecent Tile added is Tile number: " << i << endl;
            rPlaces[j] = &roadPlaces[tileRoadIndices[i][j]];
        }

        // the arrays sPlaces and rPlaces are passed to the Tile constructor by value
        // and thats ok because these are pointers and the pointers are copied, not the objects they point to.
        tiles[i] = Tile(landTypes[i], i, activationNumbers[i], sPlaces, rPlaces);
    }
}


/*
this method sets up the adjacent structurePlaces, roadPlaces and tiles for each structurePlace
and adjacent structurePlaces and roadPlaces for each roadPlace.
*/
void Board::setupAdjacencies() {
    cout << "Setting up adjacencies..." << endl;
    structurePlaces[0].setAdjStructs({&structurePlaces[2], &structurePlaces[3], nullptr});
    structurePlaces[0].setAdjRoads({&roadPlaces[0], &roadPlaces[1]});
    structurePlaces[0].addAdjTile(&tiles[0]);
    structurePlaces[1].setAdjStructs({&structurePlaces[4], &structurePlaces[5]});
    structurePlaces[1].setAdjRoads({&roadPlaces[2], &roadPlaces[3]});
    structurePlaces[1].addAdjTile(&tiles[1]);
    structurePlaces[2].setAdjStructs({&structurePlaces[5], &structurePlaces[6]});
    structurePlaces[2].setAdjRoads({&roadPlaces[4], &roadPlaces[5]});
    structurePlaces[2].addAdjTile(&tiles[2]);
    structurePlaces[3].setAdjStructs({&structurePlaces[0], &structurePlaces[7]});
    structurePlaces[3].setAdjRoads({&roadPlaces[0], &roadPlaces[6]});
    structurePlaces[3].addAdjTile(&tiles[0]);
    structurePlaces[4].setAdjStructs({&structurePlaces[0], &structurePlaces[1], &structurePlaces[8]});
    structurePlaces[4].setAdjRoads({&roadPlaces[1], &roadPlaces[2], &roadPlaces[7]});
    structurePlaces[4].addAdjTile(&tiles[0]);
    structurePlaces[4].addAdjTile(&tiles[1]);
    structurePlaces[5].setAdjStructs({&structurePlaces[1], &structurePlaces[2], &structurePlaces[9]});
    structurePlaces[5].setAdjRoads({&roadPlaces[3], &roadPlaces[4], &roadPlaces[8]});
    structurePlaces[5].addAdjTile(&tiles[1]);
    structurePlaces[5].addAdjTile(&tiles[2]);
    structurePlaces[6].setAdjStructs({&structurePlaces[2], &structurePlaces[10]});
    structurePlaces[6].setAdjRoads({&roadPlaces[5], &roadPlaces[9]});
    structurePlaces[6].addAdjTile(&tiles[2]);
    structurePlaces[7].setAdjStructs({&structurePlaces[3], &structurePlaces[12], &structurePlaces[11]});
    structurePlaces[7].setAdjRoads({&roadPlaces[6], &roadPlaces[11], &roadPlaces[10]});
    structurePlaces[7].addAdjTile(&tiles[0]);
    structurePlaces[7].addAdjTile(&tiles[3]);
    structurePlaces[8].setAdjStructs({&structurePlaces[4], &structurePlaces[13], &structurePlaces[12]});
    structurePlaces[8].setAdjRoads({&roadPlaces[7], &roadPlaces[13], &roadPlaces[12]});
    structurePlaces[8].addAdjTile(&tiles[0]);
    structurePlaces[8].addAdjTile(&tiles[1]);
    structurePlaces[8].addAdjTile(&tiles[4]);
    structurePlaces[9].setAdjStructs({&structurePlaces[5], &structurePlaces[14], &structurePlaces[13]});
    structurePlaces[9].setAdjRoads({&roadPlaces[8], &roadPlaces[15], &roadPlaces[14]});
    structurePlaces[9].addAdjTile(&tiles[1]);
    structurePlaces[9].addAdjTile(&tiles[2]);
    structurePlaces[9].addAdjTile(&tiles[5]);
    structurePlaces[10].setAdjStructs({&structurePlaces[6], &structurePlaces[15]});
    structurePlaces[10].setAdjRoads({&roadPlaces[9], &roadPlaces[17], &roadPlaces[16]});
    structurePlaces[10].addAdjTile(&tiles[2]);
    structurePlaces[10].addAdjTile(&tiles[6]);
    structurePlaces[11].setAdjStructs({&structurePlaces[7], &structurePlaces[16]});
    structurePlaces[11].setAdjRoads({&roadPlaces[10], &roadPlaces[18]});
    structurePlaces[11].addAdjTile(&tiles[3]);
    structurePlaces[12].setAdjStructs({&structurePlaces[7], &structurePlaces[8], &structurePlaces[17]});
    structurePlaces[12].setAdjRoads({&roadPlaces[11], &roadPlaces[12], &roadPlaces[19]});
    structurePlaces[12].addAdjTile(&tiles[0]);
    structurePlaces[12].addAdjTile(&tiles[3]);
    structurePlaces[12].addAdjTile(&tiles[4]);
    structurePlaces[13].setAdjStructs({&structurePlaces[8], &structurePlaces[9], &structurePlaces[18]});
    structurePlaces[13].setAdjRoads({&roadPlaces[13], &roadPlaces[14], &roadPlaces[20]});
    structurePlaces[13].addAdjTile(&tiles[1]);
    structurePlaces[13].addAdjTile(&tiles[4]);
    structurePlaces[13].addAdjTile(&tiles[5]);
    structurePlaces[14].setAdjStructs({&structurePlaces[9], &structurePlaces[10], &structurePlaces[19]});
    structurePlaces[14].setAdjRoads({&roadPlaces[15], &roadPlaces[16], &roadPlaces[21]});
    structurePlaces[14].addAdjTile(&tiles[2]);
    structurePlaces[14].addAdjTile(&tiles[5]);
    structurePlaces[14].addAdjTile(&tiles[6]);
    structurePlaces[15].setAdjStructs({&structurePlaces[10], &structurePlaces[20]});
    structurePlaces[15].setAdjRoads({&roadPlaces[17], &roadPlaces[22]});
    structurePlaces[15].addAdjTile(&tiles[6]);
    structurePlaces[16].setAdjStructs({&structurePlaces[11], &structurePlaces[22], &structurePlaces[21]});
    structurePlaces[16].setAdjRoads({&roadPlaces[18], &roadPlaces[24], &roadPlaces[23]});
    structurePlaces[16].addAdjTile(&tiles[3]);
    structurePlaces[16].addAdjTile(&tiles[7]);
    structurePlaces[17].setAdjStructs({&structurePlaces[12], &structurePlaces[23], &structurePlaces[22]});
    structurePlaces[17].setAdjRoads({&roadPlaces[19], &roadPlaces[26], &roadPlaces[25]});
    structurePlaces[17].addAdjTile(&tiles[3]);
    structurePlaces[17].addAdjTile(&tiles[4]);
    structurePlaces[17].addAdjTile(&tiles[8]);
    structurePlaces[18].setAdjStructs({&structurePlaces[13], &structurePlaces[24], &structurePlaces[23]});
    structurePlaces[18].setAdjRoads({&roadPlaces[20], &roadPlaces[28], &roadPlaces[27]});
    structurePlaces[18].addAdjTile(&tiles[4]);
    structurePlaces[18].addAdjTile(&tiles[5]);
    structurePlaces[18].addAdjTile(&tiles[9]);
    structurePlaces[19].setAdjStructs({&structurePlaces[14], &structurePlaces[25], &structurePlaces[24]});
    structurePlaces[19].setAdjRoads({&roadPlaces[21], &roadPlaces[30], &roadPlaces[29]});
    structurePlaces[19].addAdjTile(&tiles[5]);
    structurePlaces[19].addAdjTile(&tiles[6]);
    structurePlaces[19].addAdjTile(&tiles[10]);
    structurePlaces[20].setAdjStructs({&structurePlaces[15], &structurePlaces[26], &structurePlaces[25]});
    structurePlaces[20].setAdjRoads({&roadPlaces[22], &roadPlaces[32], &roadPlaces[31]});
    structurePlaces[20].addAdjTile(&tiles[6]);
    structurePlaces[20].addAdjTile(&tiles[11]);
    structurePlaces[21].setAdjStructs({&structurePlaces[16], &structurePlaces[27]});
    structurePlaces[21].setAdjRoads({&roadPlaces[23], &roadPlaces[33]});
    structurePlaces[21].addAdjTile(&tiles[7]);
    structurePlaces[22].setAdjStructs({&structurePlaces[16], &structurePlaces[17], &structurePlaces[28]});
    structurePlaces[22].setAdjRoads({&roadPlaces[24], &roadPlaces[25], &roadPlaces[34]});
    structurePlaces[22].addAdjTile(&tiles[3]);
    structurePlaces[22].addAdjTile(&tiles[7]);
    structurePlaces[22].addAdjTile(&tiles[8]);
    structurePlaces[23].setAdjStructs({&structurePlaces[17], &structurePlaces[18], &structurePlaces[29]});
    structurePlaces[23].setAdjRoads({&roadPlaces[26], &roadPlaces[27], &roadPlaces[35]});
    structurePlaces[23].addAdjTile(&tiles[4]);
    structurePlaces[23].addAdjTile(&tiles[8]);
    structurePlaces[23].addAdjTile(&tiles[9]);
    structurePlaces[24].setAdjStructs({&structurePlaces[18], &structurePlaces[19], &structurePlaces[30]});
    structurePlaces[24].setAdjRoads({&roadPlaces[28], &roadPlaces[29], &roadPlaces[36]});
    structurePlaces[24].addAdjTile(&tiles[5]);
    structurePlaces[24].addAdjTile(&tiles[9]);
    structurePlaces[24].addAdjTile(&tiles[10]);
    structurePlaces[25].setAdjStructs({&structurePlaces[19], &structurePlaces[20], &structurePlaces[31]});
    structurePlaces[25].setAdjRoads({&roadPlaces[30], &roadPlaces[31], &roadPlaces[37]});
    structurePlaces[25].addAdjTile(&tiles[6]);
    structurePlaces[25].addAdjTile(&tiles[10]);
    structurePlaces[25].addAdjTile(&tiles[11]);
    structurePlaces[26].setAdjStructs({&structurePlaces[20], &structurePlaces[32]});
    structurePlaces[26].setAdjRoads({&roadPlaces[32], &roadPlaces[38]});
    structurePlaces[26].addAdjTile(&tiles[11]);
    structurePlaces[27].setAdjStructs({&structurePlaces[21], &structurePlaces[33]});
    structurePlaces[27].setAdjRoads({&roadPlaces[33], &roadPlaces[39]});
    structurePlaces[27].addAdjTile(&tiles[7]);
    structurePlaces[28].setAdjStructs({&structurePlaces[22], &structurePlaces[34], &structurePlaces[33]});
    structurePlaces[28].setAdjRoads({&roadPlaces[34], &roadPlaces[41], &roadPlaces[40]});
    structurePlaces[28].addAdjTile(&tiles[7]);
    structurePlaces[28].addAdjTile(&tiles[8]);
    structurePlaces[28].addAdjTile(&tiles[12]);
    structurePlaces[29].setAdjStructs({&structurePlaces[23], &structurePlaces[35], &structurePlaces[34]});
    structurePlaces[29].setAdjRoads({&roadPlaces[35], &roadPlaces[43], &roadPlaces[42]});
    structurePlaces[29].addAdjTile(&tiles[8]);
    structurePlaces[29].addAdjTile(&tiles[9]);
    structurePlaces[29].addAdjTile(&tiles[13]);
    structurePlaces[30].setAdjStructs({&structurePlaces[24], &structurePlaces[36], &structurePlaces[35]});
    structurePlaces[30].setAdjRoads({&roadPlaces[36], &roadPlaces[45], &roadPlaces[44]});
    structurePlaces[30].addAdjTile(&tiles[9]);
    structurePlaces[30].addAdjTile(&tiles[10]);
    structurePlaces[30].addAdjTile(&tiles[14]);
    structurePlaces[31].setAdjStructs({&structurePlaces[25], &structurePlaces[37], &structurePlaces[36]});
    structurePlaces[31].setAdjRoads({&roadPlaces[37], &roadPlaces[47], &roadPlaces[46]});
    structurePlaces[31].addAdjTile(&tiles[10]);
    structurePlaces[31].addAdjTile(&tiles[11]);
    structurePlaces[31].addAdjTile(&tiles[15]);
    structurePlaces[32].setAdjStructs({&structurePlaces[26], &structurePlaces[37]});
    structurePlaces[32].setAdjRoads({&roadPlaces[38], &roadPlaces[48]});
    structurePlaces[32].addAdjTile(&tiles[11]);
    structurePlaces[33].setAdjStructs({&structurePlaces[27], &structurePlaces[28], &structurePlaces[38]});
    structurePlaces[33].setAdjRoads({&roadPlaces[39], &roadPlaces[40], &roadPlaces[49]});
    structurePlaces[33].addAdjTile(&tiles[7]);
    structurePlaces[33].addAdjTile(&tiles[12]);
    structurePlaces[34].setAdjStructs({&structurePlaces[28], &structurePlaces[29], &structurePlaces[39]});
    structurePlaces[34].setAdjRoads({&roadPlaces[41], &roadPlaces[42], &roadPlaces[50]});
    structurePlaces[34].addAdjTile(&tiles[8]);
    structurePlaces[34].addAdjTile(&tiles[12]);
    structurePlaces[34].addAdjTile(&tiles[13]);
    structurePlaces[35].setAdjStructs({&structurePlaces[29], &structurePlaces[30], &structurePlaces[40]});
    structurePlaces[35].setAdjRoads({&roadPlaces[43], &roadPlaces[44], &roadPlaces[51]});
    structurePlaces[35].addAdjTile(&tiles[9]);
    structurePlaces[35].addAdjTile(&tiles[13]);
    structurePlaces[35].addAdjTile(&tiles[14]);
    structurePlaces[36].setAdjStructs({&structurePlaces[30], &structurePlaces[31], &structurePlaces[41]});
    structurePlaces[36].setAdjRoads({&roadPlaces[45], &roadPlaces[46], &roadPlaces[52]});
    structurePlaces[36].addAdjTile(&tiles[10]);
    structurePlaces[36].addAdjTile(&tiles[14]);
    structurePlaces[36].addAdjTile(&tiles[15]);
    structurePlaces[37].setAdjStructs({&structurePlaces[31], &structurePlaces[32], &structurePlaces[42]});
    structurePlaces[37].setAdjRoads({&roadPlaces[47], &roadPlaces[48], &roadPlaces[53]});
    structurePlaces[37].addAdjTile(&tiles[11]);
    structurePlaces[37].addAdjTile(&tiles[15]);
    structurePlaces[38].setAdjStructs({&structurePlaces[33], &structurePlaces[43]});
    structurePlaces[38].setAdjRoads({&roadPlaces[49], &roadPlaces[54]});
    structurePlaces[38].addAdjTile(&tiles[12]);
    structurePlaces[39].setAdjStructs({&structurePlaces[34], &structurePlaces[44], &structurePlaces[43]});
    structurePlaces[39].setAdjRoads({&roadPlaces[50], &roadPlaces[56], &roadPlaces[55]});
    structurePlaces[39].addAdjTile(&tiles[12]);
    structurePlaces[39].addAdjTile(&tiles[13]);
    structurePlaces[39].addAdjTile(&tiles[16]);
    structurePlaces[40].setAdjStructs({&structurePlaces[35], &structurePlaces[45], &structurePlaces[44]});
    structurePlaces[40].setAdjRoads({&roadPlaces[51], &roadPlaces[58], &roadPlaces[57]});
    structurePlaces[40].addAdjTile(&tiles[13]);
    structurePlaces[40].addAdjTile(&tiles[14]);
    structurePlaces[40].addAdjTile(&tiles[17]);
    structurePlaces[41].setAdjStructs({&structurePlaces[36], &structurePlaces[46], &structurePlaces[45]});
    structurePlaces[41].setAdjRoads({&roadPlaces[52], &roadPlaces[60], &roadPlaces[59]});
    structurePlaces[41].addAdjTile(&tiles[14]);
    structurePlaces[41].addAdjTile(&tiles[15]);
    structurePlaces[41].addAdjTile(&tiles[18]);
    structurePlaces[42].setAdjStructs({&structurePlaces[37], &structurePlaces[46]});
    structurePlaces[42].setAdjRoads({&roadPlaces[53], &roadPlaces[61]});
    structurePlaces[42].addAdjTile(&tiles[15]);
    structurePlaces[43].setAdjStructs({&structurePlaces[38], &structurePlaces[39], &structurePlaces[47]});
    structurePlaces[43].setAdjRoads({&roadPlaces[54], &roadPlaces[55], &roadPlaces[62]});
    structurePlaces[43].addAdjTile(&tiles[12]);
    structurePlaces[43].addAdjTile(&tiles[16]);
    structurePlaces[44].setAdjStructs({&structurePlaces[39], &structurePlaces[40], &structurePlaces[48]});
    structurePlaces[44].setAdjRoads({&roadPlaces[56], &roadPlaces[57], &roadPlaces[63]});
    structurePlaces[44].addAdjTile(&tiles[13]);
    structurePlaces[44].addAdjTile(&tiles[16]);
    structurePlaces[44].addAdjTile(&tiles[17]);
    structurePlaces[45].setAdjStructs({&structurePlaces[40], &structurePlaces[41], &structurePlaces[49]});
    structurePlaces[45].setAdjRoads({&roadPlaces[58], &roadPlaces[59], &roadPlaces[64]});
    structurePlaces[45].addAdjTile(&tiles[14]);
    structurePlaces[45].addAdjTile(&tiles[17]);
    structurePlaces[45].addAdjTile(&tiles[18]);
    structurePlaces[46].setAdjStructs({&structurePlaces[41], &structurePlaces[42], &structurePlaces[50]});
    structurePlaces[46].setAdjRoads({&roadPlaces[60], &roadPlaces[61], &roadPlaces[65]});
    structurePlaces[46].addAdjTile(&tiles[15]);
    structurePlaces[46].addAdjTile(&tiles[18]);
    structurePlaces[47].setAdjStructs({&structurePlaces[43], &structurePlaces[51]});
    structurePlaces[47].setAdjRoads({&roadPlaces[62], &roadPlaces[66]});
    structurePlaces[47].addAdjTile(&tiles[16]);
    structurePlaces[48].setAdjStructs({&structurePlaces[44], &structurePlaces[52], &structurePlaces[51]});
    structurePlaces[48].setAdjRoads({&roadPlaces[63], &roadPlaces[68], &roadPlaces[67]});
    structurePlaces[48].addAdjTile(&tiles[16]);
    structurePlaces[48].addAdjTile(&tiles[17]);
    structurePlaces[49].setAdjStructs({&structurePlaces[45], &structurePlaces[53], &structurePlaces[52]});
    structurePlaces[49].setAdjRoads({&roadPlaces[64], &roadPlaces[70], &roadPlaces[69]});
    structurePlaces[49].addAdjTile(&tiles[17]);
    structurePlaces[49].addAdjTile(&tiles[18]);
    structurePlaces[50].setAdjStructs({&structurePlaces[46], &structurePlaces[53]});
    structurePlaces[50].setAdjRoads({&roadPlaces[65], &roadPlaces[71]});
    structurePlaces[50].addAdjTile(&tiles[18]);
    structurePlaces[51].setAdjStructs({&structurePlaces[47], &structurePlaces[48]});
    structurePlaces[51].setAdjRoads({&roadPlaces[66], &roadPlaces[67]});
    structurePlaces[51].addAdjTile(&tiles[16]);
    structurePlaces[52].setAdjStructs({&structurePlaces[48], &structurePlaces[49]});
    structurePlaces[52].setAdjRoads({&roadPlaces[68], &roadPlaces[69]});
    structurePlaces[52].addAdjTile(&tiles[17]);
    structurePlaces[53].setAdjStructs({&structurePlaces[49], &structurePlaces[50]});
    structurePlaces[53].setAdjRoads({&roadPlaces[70], &roadPlaces[71]});
    structurePlaces[53].addAdjTile(&tiles[18]);

    roadPlaces[0].setAdjStructs({&structurePlaces[0], &structurePlaces[3]});
    roadPlaces[0].setAdjRoads({nullptr, &roadPlaces[1], nullptr, &roadPlaces[6]});
    roadPlaces[1].setAdjStructs({&structurePlaces[0], &structurePlaces[4]});
    roadPlaces[1].setAdjRoads({&roadPlaces[0], nullptr, &roadPlaces[7], &roadPlaces[2]});
    roadPlaces[2].setAdjStructs({&structurePlaces[1], &structurePlaces[4]});
    roadPlaces[2].setAdjRoads({&roadPlaces[3], nullptr, &roadPlaces[1], &roadPlaces[7]});
    roadPlaces[3].setAdjStructs({&structurePlaces[1], &structurePlaces[5]});
    roadPlaces[3].setAdjRoads({nullptr, &roadPlaces[2], &roadPlaces[8], &roadPlaces[4]});
    roadPlaces[4].setAdjStructs({&structurePlaces[2], &structurePlaces[5]});
    roadPlaces[4].setAdjRoads({&roadPlaces[5], nullptr, &roadPlaces[3], &roadPlaces[8]});
    roadPlaces[5].setAdjStructs({&structurePlaces[2], &structurePlaces[6]});
    roadPlaces[5].setAdjRoads({nullptr, &roadPlaces[4], nullptr, &roadPlaces[9]});
    roadPlaces[6].setAdjStructs({&structurePlaces[3], &structurePlaces[7]});
    roadPlaces[6].setAdjRoads({&roadPlaces[0], nullptr, &roadPlaces[10], &roadPlaces[11]});
    roadPlaces[7].setAdjStructs({&structurePlaces[4], &structurePlaces[8]});
    roadPlaces[7].setAdjRoads({&roadPlaces[1], &roadPlaces[2], &roadPlaces[12], &roadPlaces[13]});
    roadPlaces[8].setAdjStructs({&structurePlaces[5], &structurePlaces[9]});
    roadPlaces[8].setAdjRoads({&roadPlaces[3], &roadPlaces[4], &roadPlaces[14], &roadPlaces[15]});
    roadPlaces[9].setAdjStructs({&structurePlaces[6], &structurePlaces[10]});
    roadPlaces[9].setAdjRoads({&roadPlaces[5], nullptr, &roadPlaces[16], &roadPlaces[17]});
    roadPlaces[10].setAdjStructs({&structurePlaces[7], &structurePlaces[11]});
    roadPlaces[10].setAdjRoads({&roadPlaces[6], &roadPlaces[11], &roadPlaces[18], nullptr});
    roadPlaces[11].setAdjStructs({&structurePlaces[7], &structurePlaces[12]});
    roadPlaces[11].setAdjRoads({&roadPlaces[10], &roadPlaces[6], &roadPlaces[19], &roadPlaces[12]});
    roadPlaces[12].setAdjStructs({&structurePlaces[8], &structurePlaces[12]});
    roadPlaces[12].setAdjRoads({&roadPlaces[7], &roadPlaces[13], &roadPlaces[11], &roadPlaces[19]});
    roadPlaces[13].setAdjStructs({&structurePlaces[8], &structurePlaces[13]});
    roadPlaces[13].setAdjRoads({&roadPlaces[7], &roadPlaces[12], &roadPlaces[20], &roadPlaces[14]});
    roadPlaces[14].setAdjStructs({&structurePlaces[9], &structurePlaces[13]});
    roadPlaces[14].setAdjRoads({&roadPlaces[8], &roadPlaces[15], &roadPlaces[13], &roadPlaces[20]});
    roadPlaces[15].setAdjStructs({&structurePlaces[9], &structurePlaces[14]});
    roadPlaces[15].setAdjRoads({&roadPlaces[8], &roadPlaces[14], &roadPlaces[21], &roadPlaces[16]});
    roadPlaces[16].setAdjStructs({&structurePlaces[10], &structurePlaces[14]});
    roadPlaces[16].setAdjRoads({&roadPlaces[9], &roadPlaces[17], &roadPlaces[15], &roadPlaces[21]});
    roadPlaces[17].setAdjStructs({&structurePlaces[10], &structurePlaces[15]});
    roadPlaces[17].setAdjRoads({&roadPlaces[9], &roadPlaces[16], nullptr, &roadPlaces[22]});
    roadPlaces[18].setAdjStructs({&structurePlaces[11], &structurePlaces[16]});
    roadPlaces[18].setAdjRoads({&roadPlaces[10], nullptr, &roadPlaces[23], &roadPlaces[24]});
    roadPlaces[19].setAdjStructs({&structurePlaces[12], &structurePlaces[17]});
    roadPlaces[19].setAdjRoads({&roadPlaces[11], &roadPlaces[12], &roadPlaces[25], &roadPlaces[26]});
    roadPlaces[20].setAdjStructs({&structurePlaces[13], &structurePlaces[18]});
    roadPlaces[20].setAdjRoads({&roadPlaces[13], &roadPlaces[14], &roadPlaces[27], &roadPlaces[28]});
    roadPlaces[21].setAdjStructs({&structurePlaces[14], &structurePlaces[19]});
    roadPlaces[21].setAdjRoads({&roadPlaces[15], &roadPlaces[16], &roadPlaces[29], &roadPlaces[30]});
    roadPlaces[22].setAdjStructs({&structurePlaces[15], &structurePlaces[20]});
    roadPlaces[22].setAdjRoads({&roadPlaces[17], nullptr, &roadPlaces[31], &roadPlaces[32]});
    roadPlaces[23].setAdjStructs({&structurePlaces[16], &structurePlaces[21]});
    roadPlaces[23].setAdjRoads({&roadPlaces[18], &roadPlaces[24], &roadPlaces[33], nullptr});
    roadPlaces[24].setAdjStructs({&structurePlaces[16], &structurePlaces[22]});
    roadPlaces[24].setAdjRoads({&roadPlaces[18], &roadPlaces[23], &roadPlaces[34], &roadPlaces[25]});
    roadPlaces[25].setAdjStructs({&structurePlaces[17], &structurePlaces[22]});
    roadPlaces[25].setAdjRoads({&roadPlaces[19], &roadPlaces[26], &roadPlaces[24], &roadPlaces[34]});
    roadPlaces[26].setAdjStructs({&structurePlaces[17], &structurePlaces[23]});
    roadPlaces[26].setAdjRoads({&roadPlaces[19], &roadPlaces[25], &roadPlaces[35], &roadPlaces[27]});
    roadPlaces[27].setAdjStructs({&structurePlaces[18], &structurePlaces[23]});
    roadPlaces[27].setAdjRoads({&roadPlaces[20], &roadPlaces[28], &roadPlaces[26], &roadPlaces[35]});
    roadPlaces[28].setAdjStructs({&structurePlaces[18], &structurePlaces[24]});
    roadPlaces[28].setAdjRoads({&roadPlaces[20], &roadPlaces[27], &roadPlaces[36], &roadPlaces[29]});
    roadPlaces[29].setAdjStructs({&structurePlaces[19], &structurePlaces[24]});
    roadPlaces[29].setAdjRoads({&roadPlaces[21], &roadPlaces[30], &roadPlaces[28], &roadPlaces[36]});
    roadPlaces[30].setAdjStructs({&structurePlaces[19], &structurePlaces[25]});
    roadPlaces[30].setAdjRoads({&roadPlaces[21], &roadPlaces[29], &roadPlaces[37], &roadPlaces[31]});
    roadPlaces[31].setAdjStructs({&structurePlaces[20], &structurePlaces[25]});
    roadPlaces[31].setAdjRoads({&roadPlaces[22], &roadPlaces[32], &roadPlaces[30], &roadPlaces[37]});
    roadPlaces[32].setAdjStructs({&structurePlaces[20], &structurePlaces[26]});
    roadPlaces[32].setAdjRoads({&roadPlaces[22], &roadPlaces[31], &roadPlaces[38], nullptr});
    roadPlaces[33].setAdjStructs({&structurePlaces[21], &structurePlaces[27]});
    roadPlaces[33].setAdjRoads({&roadPlaces[23], nullptr, &roadPlaces[39], nullptr});
    roadPlaces[34].setAdjStructs({&structurePlaces[22], &structurePlaces[28]});
    roadPlaces[34].setAdjRoads({&roadPlaces[24], &roadPlaces[25], &roadPlaces[40], &roadPlaces[41]});
    roadPlaces[35].setAdjStructs({&structurePlaces[23], &structurePlaces[29]});
    roadPlaces[35].setAdjRoads({&roadPlaces[26], &roadPlaces[27], &roadPlaces[42], &roadPlaces[43]});
    roadPlaces[36].setAdjStructs({&structurePlaces[24], &structurePlaces[30]});
    roadPlaces[36].setAdjRoads({&roadPlaces[28], &roadPlaces[29], &roadPlaces[44], &roadPlaces[45]});
    roadPlaces[37].setAdjStructs({&structurePlaces[25], &structurePlaces[31]});
    roadPlaces[37].setAdjRoads({&roadPlaces[30], &roadPlaces[31], &roadPlaces[46], &roadPlaces[47]});
    roadPlaces[38].setAdjStructs({&structurePlaces[26], &structurePlaces[32]});
    roadPlaces[38].setAdjRoads({&roadPlaces[32], nullptr, &roadPlaces[48], nullptr});
    roadPlaces[39].setAdjStructs({&structurePlaces[27], &structurePlaces[33]});
    roadPlaces[39].setAdjRoads({&roadPlaces[33], nullptr, &roadPlaces[40], &roadPlaces[49]});
    roadPlaces[40].setAdjStructs({&structurePlaces[28], &structurePlaces[33]});
    roadPlaces[40].setAdjRoads({&roadPlaces[34], &roadPlaces[41], &roadPlaces[39], &roadPlaces[49]});
    roadPlaces[41].setAdjStructs({&structurePlaces[28], &structurePlaces[34]});
    roadPlaces[41].setAdjRoads({&roadPlaces[34], &roadPlaces[40], &roadPlaces[50], &roadPlaces[42]});
    roadPlaces[42].setAdjStructs({&structurePlaces[29], &structurePlaces[34]});
    roadPlaces[42].setAdjRoads({&roadPlaces[35], &roadPlaces[43], &roadPlaces[41], &roadPlaces[50]});
    roadPlaces[43].setAdjStructs({&structurePlaces[29], &structurePlaces[35]});
    roadPlaces[43].setAdjRoads({&roadPlaces[35], &roadPlaces[42], &roadPlaces[51], &roadPlaces[44]});
    roadPlaces[44].setAdjStructs({&structurePlaces[30], &structurePlaces[35]});
    roadPlaces[44].setAdjRoads({&roadPlaces[36], &roadPlaces[45], &roadPlaces[43], &roadPlaces[51]});
    roadPlaces[45].setAdjStructs({&structurePlaces[30], &structurePlaces[36]});
    roadPlaces[45].setAdjRoads({&roadPlaces[36], &roadPlaces[44], &roadPlaces[52], &roadPlaces[46]});
    roadPlaces[46].setAdjStructs({&structurePlaces[31], &structurePlaces[36]});
    roadPlaces[46].setAdjRoads({&roadPlaces[37], &roadPlaces[47], &roadPlaces[45], &roadPlaces[52]});
    roadPlaces[47].setAdjStructs({&structurePlaces[31], &structurePlaces[37]});
    roadPlaces[47].setAdjRoads({&roadPlaces[37], &roadPlaces[46], &roadPlaces[48], &roadPlaces[53]});
    roadPlaces[48].setAdjStructs({&structurePlaces[32], &structurePlaces[37]});
    roadPlaces[48].setAdjRoads({&roadPlaces[38], nullptr, &roadPlaces[47], &roadPlaces[53]});
    roadPlaces[49].setAdjStructs({&structurePlaces[33], &structurePlaces[38]});
    roadPlaces[49].setAdjRoads({&roadPlaces[39], &roadPlaces[40], nullptr, &roadPlaces[54]});
    roadPlaces[50].setAdjStructs({&structurePlaces[34], &structurePlaces[39]});
    roadPlaces[50].setAdjRoads({&roadPlaces[41], &roadPlaces[42], &roadPlaces[55], &roadPlaces[56]});
    roadPlaces[51].setAdjStructs({&structurePlaces[35], &structurePlaces[40]});
    roadPlaces[51].setAdjRoads({&roadPlaces[43], &roadPlaces[44], &roadPlaces[57], &roadPlaces[58]});
    roadPlaces[52].setAdjStructs({&structurePlaces[36], &structurePlaces[41]});
    roadPlaces[52].setAdjRoads({&roadPlaces[45], &roadPlaces[46], &roadPlaces[59], &roadPlaces[60]});
    roadPlaces[53].setAdjStructs({&structurePlaces[37], &structurePlaces[42]});
    roadPlaces[53].setAdjRoads({&roadPlaces[47], &roadPlaces[48], &roadPlaces[61], nullptr});
    roadPlaces[54].setAdjStructs({&structurePlaces[38], &structurePlaces[43]});
    roadPlaces[54].setAdjRoads({&roadPlaces[49], nullptr, &roadPlaces[55], &roadPlaces[62]});
    roadPlaces[55].setAdjStructs({&structurePlaces[39], &structurePlaces[43]});
    roadPlaces[55].setAdjRoads({&roadPlaces[50], &roadPlaces[56], &roadPlaces[54], &roadPlaces[62]});
    roadPlaces[56].setAdjStructs({&structurePlaces[39], &structurePlaces[44]});
    roadPlaces[56].setAdjRoads({&roadPlaces[50], &roadPlaces[55], &roadPlaces[63], &roadPlaces[57]});
    roadPlaces[57].setAdjStructs({&structurePlaces[40], &structurePlaces[44]});
    roadPlaces[57].setAdjRoads({&roadPlaces[51], &roadPlaces[58], &roadPlaces[56], &roadPlaces[63]});
    roadPlaces[58].setAdjStructs({&structurePlaces[40], &structurePlaces[45]});
    roadPlaces[58].setAdjRoads({&roadPlaces[51], &roadPlaces[57], &roadPlaces[64], &roadPlaces[59]});
    roadPlaces[59].setAdjStructs({&structurePlaces[41], &structurePlaces[45]});
    roadPlaces[59].setAdjRoads({&roadPlaces[52], &roadPlaces[60], &roadPlaces[58], &roadPlaces[64]});
    roadPlaces[60].setAdjStructs({&structurePlaces[41], &structurePlaces[46]});
    roadPlaces[60].setAdjRoads({&roadPlaces[52], &roadPlaces[59], &roadPlaces[65], &roadPlaces[61]});
    roadPlaces[61].setAdjStructs({&structurePlaces[42], &structurePlaces[46]});
    roadPlaces[61].setAdjRoads({&roadPlaces[53], nullptr, &roadPlaces[60], &roadPlaces[65]});
    roadPlaces[62].setAdjStructs({&structurePlaces[43], &structurePlaces[47]});
    roadPlaces[62].setAdjRoads({&roadPlaces[54], &roadPlaces[55], nullptr, &roadPlaces[66]});
    roadPlaces[63].setAdjStructs({&structurePlaces[44], &structurePlaces[48]});
    roadPlaces[63].setAdjRoads({&roadPlaces[56], &roadPlaces[57], &roadPlaces[68], &roadPlaces[67]});
    roadPlaces[64].setAdjStructs({&structurePlaces[45], &structurePlaces[49]});
    roadPlaces[64].setAdjRoads({&roadPlaces[58], &roadPlaces[59], &roadPlaces[69], &roadPlaces[70]});
    roadPlaces[65].setAdjStructs({&structurePlaces[46], &structurePlaces[50]});
    roadPlaces[65].setAdjRoads({&roadPlaces[60], &roadPlaces[61], &roadPlaces[71], nullptr});
    roadPlaces[66].setAdjStructs({&structurePlaces[47], &structurePlaces[51]});
    roadPlaces[66].setAdjRoads({&roadPlaces[62], nullptr, nullptr, &roadPlaces[67]});
    roadPlaces[67].setAdjStructs({&structurePlaces[48], &structurePlaces[51]});
    roadPlaces[67].setAdjRoads({&roadPlaces[63], &roadPlaces[68], &roadPlaces[66], nullptr});
    roadPlaces[68].setAdjStructs({&structurePlaces[48], &structurePlaces[52]});
    roadPlaces[68].setAdjRoads({&roadPlaces[63], &roadPlaces[67], nullptr, &roadPlaces[69]});
    roadPlaces[69].setAdjStructs({&structurePlaces[49], &structurePlaces[52]});
    roadPlaces[69].setAdjRoads({&roadPlaces[64], &roadPlaces[70], &roadPlaces[68], nullptr});
    roadPlaces[70].setAdjStructs({&structurePlaces[49], &structurePlaces[53]});
    roadPlaces[70].setAdjRoads({&roadPlaces[64], &roadPlaces[69], nullptr, &roadPlaces[71]});
    roadPlaces[71].setAdjStructs({&structurePlaces[50], &structurePlaces[53]});
    roadPlaces[71].setAdjRoads({&roadPlaces[65], nullptr, &roadPlaces[70], nullptr});
}

roadPlace* Board::getRoadAt(int roadNumber) {
    return &roadPlaces[roadNumber];
}

structurePlace* Board::getStructureAt(int structNumber) {
    if (structNumber < 0 || structNumber >= structurePlaces.size()) {
        cout << "Invalid structurePlace_index" << endl;
        return nullptr;
    }
    return &structurePlaces[structNumber];
}

Tile* Board::getTileAt(int tileNumber) {
    return &tiles[tileNumber];
}

const vector<structurePlace>& Board::getStructurePlaces() const {
    return structurePlaces;
}

const vector<roadPlace>& Board::getRoadPlaces() const {
    return roadPlaces;
}

const vector<Tile>& Board::getTiles() const {
    return tiles;
}



void Board::printBoard() { 
    cout <<"             "<< "     " << structurePlaces[0].getPrintableString() << "         " << structurePlaces[1].getPrintableString() << "         " << structurePlaces[2].getPrintableString() << endl;
    cout <<"             "<< " " << roadPlaces[0].getPrintableString() << " /    " << roadPlaces[1].getPrintableString() << " \\  " << roadPlaces[2].getPrintableString() << " /    " << roadPlaces[3].getPrintableString() << " \\  " << roadPlaces[4].getPrintableString() << " /    " << roadPlaces[5].getPrintableString() << " \\\033[0m" << endl;
    cout <<"             "<< " " << structurePlaces[3].getPrintableString() << "   10   " << structurePlaces[4].getPrintableString() << "         " << structurePlaces[5].getPrintableString() << "        " << structurePlaces[6].getPrintableString() << endl;
    cout <<"             "<< " " << roadPlaces[6].getPrintableString() << "|   " << "🪨   " << roadPlaces[7].getPrintableString() << " |" << endl;
}