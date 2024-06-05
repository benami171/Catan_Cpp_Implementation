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

// void Board::printBoard() {
   
//     // print first row
//     cout << "            " << structurePlaces[0].get_settlement_string() << "      " << structurePlaces[1].get_settlement_string() << "       " << structurePlaces[2].get_settlement_string() << "\n"
//          << "          " << roadPlaces[0].get_color_code() << "/   " << roadPlaces[1].get_color_code() << "\\  " << roadPlaces[2].get_color_code() << "/   " << roadPlaces[3].get_color_code() << "\\   " << roadPlaces[4].get_color_code() << "/   " << roadPlaces[5].get_color_code() << "\\\033[0m\n"
//          << "         " << structurePlaces[3].get_settlement_string() << "     " << structurePlaces[4].get_settlement_string() << "       " << structurePlaces[5].get_settlement_string() << "      " << structurePlaces[6].get_settlement_string() << "\n"
//          << "         " << roadPlaces[6].get_color_code() << "| " << structurePlaces[0].get_resources()[0].first.get_emoji() << roadPlaces[7].get_color_code() << "  |" << "  " << structurePlaces[1].get_resources()[0].first.get_emoji() << roadPlaces[8].get_color_code() << "   |  " << structurePlaces[2].get_resources()[0].first.get_emoji() << "  " << roadPlaces[9].get_color_code() << "|\033[0m\n"
//          << "         " << structurePlaces[7].get_settlement_string() << " " << structurePlaces[0].get_resources()[0].second << "  " << structurePlaces[8].get_settlement_string() << "   " << structurePlaces[1].get_resources()[0].second << "   " << structurePlaces[9].get_settlement_string() << "   " << structurePlaces[2].get_resources()[0].second << "  " << structurePlaces[10].get_settlement_string() << "\n"
//          << "       " << roadPlaces[10].get_color_code() << "/   " << roadPlaces[11].get_color_code() << "\\ " << roadPlaces[12].get_color_code() << "/   " << roadPlaces[13].get_color_code() << "\\   " << roadPlaces[14].get_color_code() << "/   " << roadPlaces[15].get_color_code() << "\\  " << roadPlaces[16].get_color_code() << "/   " << roadPlaces[17].get_color_code() << "\\\033[0m\n"
//          << "      " << structurePlaces[11].get_settlement_string() << "     " << structurePlaces[12].get_settlement_string() << "      " << structurePlaces[13].get_settlement_string() << "      " << structurePlaces[14].get_settlement_string() << "      " << structurePlaces[15].get_settlement_string() << "\n"
//          << "      " << roadPlaces[18].get_color_code() << "| " << structurePlaces[7].get_resources()[0].first.get_emoji() << roadPlaces[19].get_color_code() << "  |  " << structurePlaces[8].get_resources()[0].first.get_emoji() << roadPlaces[20].get_color_code() << "  |  " << structurePlaces[9].get_resources()[0].first.get_emoji() << roadPlaces[21].get_color_code() << "  |  " << structurePlaces[10].get_resources()[0].first.get_emoji() << "  " << roadPlaces[22].get_color_code() << "|\033[0m\n"
//          << "      " << structurePlaces[16].get_settlement_string() << " " << structurePlaces[7].get_resources()[0].second << "  " << structurePlaces[17].get_settlement_string() << "   " << structurePlaces[8].get_resources()[0].second << "   " << structurePlaces[18].get_settlement_string() << "  " << structurePlaces[9].get_resources()[0].second << "  " << structurePlaces[19].get_settlement_string() << "  " << structurePlaces[10].get_resources()[0].second << "  " << structurePlaces[20].get_settlement_string() << "\n"
//          << "    " << roadPlaces[23].get_color_code() << "/   " << roadPlaces[24].get_color_code() << "\\ " << roadPlaces[25].get_color_code() << "/   " << roadPlaces[26].get_color_code() << "\\   " << roadPlaces[27].get_color_code() << "/   " << roadPlaces[28].get_color_code() << "\\ " << roadPlaces[29].get_color_code() << "/   " << roadPlaces[30].get_color_code() << "\\  " << roadPlaces[31].get_color_code() << "/   " << roadPlaces[32].get_color_code() << "\\\033[0m\n"
//          << "   " << structurePlaces[21].get_settlement_string() << "     " << structurePlaces[22].get_settlement_string() << "      " << structurePlaces[23].get_settlement_string() << "      " << structurePlaces[24].get_settlement_string() << "     " << structurePlaces[25].get_settlement_string() << "      " << structurePlaces[26].get_settlement_string() << "\n"
//          << "   " << roadPlaces[33].get_color_code() << "| " << structurePlaces[16].get_resources()[0].first.get_emoji() << roadPlaces[34].get_color_code() << "  |  " << structurePlaces[17].get_resources()[0].first.get_emoji() << roadPlaces[35].get_color_code() << "  |  " << structurePlaces[18].get_resources()[0].first.get_emoji() << roadPlaces[36].get_color_code() << "   | " << structurePlaces[19].get_resources()[0].first.get_emoji() << roadPlaces[37].get_color_code() << "  | " << structurePlaces[20].get_resources()[0].first.get_emoji() << "   " << roadPlaces[38].get_color_code() << "|\033[0m\n"
//          << "   " << structurePlaces[27].get_settlement_string() << "  " << structurePlaces[16].get_resources()[0].second << "  " << structurePlaces[28].get_settlement_string() << "  " << structurePlaces[17].get_resources()[0].second << "  " << structurePlaces[29].get_settlement_string() << "   " << structurePlaces[18].get_resources()[0].second << "  " << structurePlaces[30].get_settlement_string() << "  " << structurePlaces[19].get_resources()[0].second << "  " << structurePlaces[31].get_settlement_string() << "   " << structurePlaces[20].get_resources()[0].second << "  " << structurePlaces[32].get_settlement_string() << "\n"
//          << "    " << roadPlaces[38].get_color_code() << "\\   " << roadPlaces[40].get_color_code() << "/ " << roadPlaces[41].get_color_code() << "\\    " << roadPlaces[42].get_color_code() << "/   " << roadPlaces[43].get_color_code() << "\\ " << roadPlaces[44].get_color_code() << "/   " << roadPlaces[45].get_color_code() << "\\ " << roadPlaces[46].get_color_code() << "/   " << roadPlaces[47].get_color_code() << "\\   " << roadPlaces[48].get_color_code() << "/\033[0m\n"
//          << "      " << structurePlaces[33].get_settlement_string() << "     " << structurePlaces[34].get_settlement_string() << "      " << structurePlaces[35].get_settlement_string() << "      " << structurePlaces[36].get_settlement_string() << "      " << structurePlaces[37].get_settlement_string() << "\n"
//          << "      " << roadPlaces[49].get_color_code() << "| " << structurePlaces[28].get_resources()[0].first.get_emoji() << roadPlaces[50].get_color_code() << "  |  " << structurePlaces[29].get_resources()[0].first.get_emoji() << roadPlaces[51].get_color_code() << "  |  " << structurePlaces[30].get_resources()[0].first.get_emoji() << roadPlaces[52].get_color_code() << "  |  " << structurePlaces[31].get_resources()[0].first.get_emoji() << roadPlaces[53].get_color_code() << "  |\033[0m\n"
//          << "      " << structurePlaces[38].get_settlement_string() << "  " << structurePlaces[28].get_resources()[0].second << "  " << structurePlaces[39].get_settlement_string() << "   " << structurePlaces[29].get_resources()[0].second << "  " << structurePlaces[40].get_settlement_string() << "   " << structurePlaces[30].get_resources()[0].second << "  " << structurePlaces[41].get_settlement_string() << "   " << structurePlaces[31].get_resources()[0].second << "  " << structurePlaces[42].get_settlement_string() << "\n"
//          << "       " << roadPlaces[54].get_color_code() << "\\   " << roadPlaces[55].get_color_code() << "/  " << roadPlaces[56].get_color_code() << "\\   " << roadPlaces[57].get_color_code() << "/  " << roadPlaces[58].get_color_code() << "\\   " << roadPlaces[59].get_color_code() << "/  " << roadPlaces[60].get_color_code() << "\\   " << roadPlaces[61].get_color_code() << "/\033[0m\n"
//          << "         " << structurePlaces[43].get_settlement_string() << "      " << structurePlaces[44].get_settlement_string() << "      " << structurePlaces[45].get_settlement_string() << "      " << structurePlaces[46].get_settlement_string() << "\n"
//          << "         " << roadPlaces[62].get_color_code() << "|  " << structurePlaces[39].get_resources()[0].first.get_emoji() << roadPlaces[63].get_color_code() << "  |  " << structurePlaces[40].get_resources()[0].first.get_emoji() << roadPlaces[64].get_color_code()<< "  |  " << structurePlaces[41].get_resources()[0].first.get_emoji() << roadPlaces[65].get_color_code() << "  |\033[0m\n"
//          << "         " << structurePlaces[47].get_settlement_string() << "   " << structurePlaces[39].get_resources()[0].second << "  " << structurePlaces[48].get_settlement_string() << "   " << structurePlaces[40].get_resources()[0].second << "  " << structurePlaces[49].get_settlement_string() << "   " << structurePlaces[41].get_resources()[0].second << " " << structurePlaces[50].get_settlement_string() << "\n"
//          << "           " << roadPlaces[66].get_color_code() << "\\   " << roadPlaces[67].get_color_code() << "/  " << roadPlaces[68].get_color_code() << "\\   " << roadPlaces[69].get_color_code() << "/  " << roadPlaces[70].get_color_code() << "\\   " << roadPlaces[71].get_color_code() << "/\033[0m\n"
//          << "             " << structurePlaces[51].get_settlement_string() << "      " << structurePlaces[52].get_settlement_string() << "       " << structurePlaces[53].get_settlement_string() << "\n";

// }

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
    cout << "Tiles were initialized\n";

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
    structurePlaces[11].setAdjStructs({&structurePlaces[7], &structurePlaces[16]});
    structurePlaces[11].setAdjRoads({&roadPlaces[10], &roadPlaces[18]});
    structurePlaces[12].setAdjStructs({&structurePlaces[7], &structurePlaces[8], &structurePlaces[17]});
    structurePlaces[12].setAdjRoads({&roadPlaces[11], &roadPlaces[12], &roadPlaces[19]});
    structurePlaces[13].setAdjStructs({&structurePlaces[8], &structurePlaces[9], &structurePlaces[18]});
    structurePlaces[13].setAdjRoads({&roadPlaces[13], &roadPlaces[14], &roadPlaces[20]});
    structurePlaces[14].setAdjStructs({&structurePlaces[9], &structurePlaces[10], &structurePlaces[19]});
    structurePlaces[14].setAdjRoads({&roadPlaces[15], &roadPlaces[16], &roadPlaces[21]});
    structurePlaces[15].setAdjStructs({&structurePlaces[10], &structurePlaces[20]});
    structurePlaces[15].setAdjRoads({&roadPlaces[17], &roadPlaces[22]});
    structurePlaces[16].setAdjStructs({&structurePlaces[11], &structurePlaces[22], &structurePlaces[21]});
    structurePlaces[16].setAdjRoads({&roadPlaces[18], &roadPlaces[24], &roadPlaces[23]});
    structurePlaces[17].setAdjStructs({&structurePlaces[12], &structurePlaces[23], &structurePlaces[22]});
    structurePlaces[17].setAdjRoads({&roadPlaces[19], &roadPlaces[26], &roadPlaces[25]});
    structurePlaces[18].setAdjStructs({&structurePlaces[13], &structurePlaces[24], &structurePlaces[23]});
    structurePlaces[18].setAdjRoads({&roadPlaces[20], &roadPlaces[28], &roadPlaces[27]});
    structurePlaces[19].setAdjStructs({&structurePlaces[14], &structurePlaces[25], &structurePlaces[24]});
    structurePlaces[19].setAdjRoads({&roadPlaces[21], &roadPlaces[30], &roadPlaces[29]});
    structurePlaces[20].setAdjStructs({&structurePlaces[15], &structurePlaces[26], &structurePlaces[25]});
    structurePlaces[20].setAdjRoads({&roadPlaces[22], &roadPlaces[32], &roadPlaces[31]});
    structurePlaces[21].setAdjStructs({&structurePlaces[16], &structurePlaces[27]});
    structurePlaces[21].setAdjRoads({&roadPlaces[23], &roadPlaces[33]});
    structurePlaces[22].setAdjStructs({&structurePlaces[16], &structurePlaces[17], &structurePlaces[28]});
    structurePlaces[22].setAdjRoads({&roadPlaces[24], &roadPlaces[25], &roadPlaces[34]});
    structurePlaces[23].setAdjStructs({&structurePlaces[17], &structurePlaces[18], &structurePlaces[29]});
    structurePlaces[23].setAdjRoads({&roadPlaces[26], &roadPlaces[27], &roadPlaces[35]});
    structurePlaces[24].setAdjStructs({&structurePlaces[18], &structurePlaces[19], &structurePlaces[30]});
    structurePlaces[24].setAdjRoads({&roadPlaces[28], &roadPlaces[29], &roadPlaces[36]});
    structurePlaces[25].setAdjStructs({&structurePlaces[19], &structurePlaces[20], &structurePlaces[31]});
    structurePlaces[25].setAdjRoads({&roadPlaces[30], &roadPlaces[31], &roadPlaces[37]});
    structurePlaces[26].setAdjStructs({&structurePlaces[20], &structurePlaces[32]});
    structurePlaces[26].setAdjRoads({&roadPlaces[32], &roadPlaces[38]});
    structurePlaces[27].setAdjStructs({&structurePlaces[21], &structurePlaces[33]});
    structurePlaces[27].setAdjRoads({&roadPlaces[33], &roadPlaces[39]});
    structurePlaces[28].setAdjStructs({&structurePlaces[22], &structurePlaces[34], &structurePlaces[33]});
    structurePlaces[28].setAdjRoads({&roadPlaces[34], &roadPlaces[41], &roadPlaces[40]});
    structurePlaces[29].setAdjStructs({&structurePlaces[23], &structurePlaces[35], &structurePlaces[34]});
    structurePlaces[29].setAdjRoads({&roadPlaces[35], &roadPlaces[43], &roadPlaces[42]});
    structurePlaces[30].setAdjStructs({&structurePlaces[24], &structurePlaces[36], &structurePlaces[35]});
    structurePlaces[30].setAdjRoads({&roadPlaces[36], &roadPlaces[45], &roadPlaces[44]});
    structurePlaces[31].setAdjStructs({&structurePlaces[25], &structurePlaces[37], &structurePlaces[36]});
    structurePlaces[31].setAdjRoads({&roadPlaces[37], &roadPlaces[47], &roadPlaces[46]});
    structurePlaces[32].setAdjStructs({&structurePlaces[26], &structurePlaces[37]});
    structurePlaces[32].setAdjRoads({&roadPlaces[38], &roadPlaces[48]});
    structurePlaces[33].setAdjStructs({&structurePlaces[27], &structurePlaces[28], &structurePlaces[38]});
    structurePlaces[33].setAdjRoads({&roadPlaces[39], &roadPlaces[40], &roadPlaces[49]});
    structurePlaces[34].setAdjStructs({&structurePlaces[28], &structurePlaces[29], &structurePlaces[39]});
    structurePlaces[34].setAdjRoads({&roadPlaces[41], &roadPlaces[42], &roadPlaces[50]});
    structurePlaces[35].setAdjStructs({&structurePlaces[29], &structurePlaces[30], &structurePlaces[40]});
    structurePlaces[35].setAdjRoads({&roadPlaces[43], &roadPlaces[44], &roadPlaces[51]});
    structurePlaces[36].setAdjStructs({&structurePlaces[30], &structurePlaces[31], &structurePlaces[41]});
    structurePlaces[36].setAdjRoads({&roadPlaces[45], &roadPlaces[46], &roadPlaces[52]});
    structurePlaces[37].setAdjStructs({&structurePlaces[31], &structurePlaces[32], &structurePlaces[42]});
    structurePlaces[37].setAdjRoads({&roadPlaces[47], &roadPlaces[48], &roadPlaces[53]});
    structurePlaces[38].setAdjStructs({&structurePlaces[33], &structurePlaces[43]});
    structurePlaces[38].setAdjRoads({&roadPlaces[49], &roadPlaces[54]});
    structurePlaces[39].setAdjStructs({&structurePlaces[34], &structurePlaces[44], &structurePlaces[43]});
    structurePlaces[39].setAdjRoads({&roadPlaces[50], &roadPlaces[56], &roadPlaces[55]});
    structurePlaces[40].setAdjStructs({&structurePlaces[35], &structurePlaces[45], &structurePlaces[44]});
    structurePlaces[40].setAdjRoads({&roadPlaces[51], &roadPlaces[58], &roadPlaces[57]});
    structurePlaces[41].setAdjStructs({&structurePlaces[36], &structurePlaces[46], &structurePlaces[45]});
    structurePlaces[41].setAdjRoads({&roadPlaces[52], &roadPlaces[60], &roadPlaces[59]});
    structurePlaces[42].setAdjStructs({&structurePlaces[37], &structurePlaces[46]});
    structurePlaces[42].setAdjRoads({&roadPlaces[53], &roadPlaces[61]});
    structurePlaces[43].setAdjStructs({&structurePlaces[38], &structurePlaces[39], &structurePlaces[47]});
    structurePlaces[43].setAdjRoads({&roadPlaces[54], &roadPlaces[55], &roadPlaces[62]});
    structurePlaces[44].setAdjStructs({&structurePlaces[39], &structurePlaces[40], &structurePlaces[48]});
    structurePlaces[44].setAdjRoads({&roadPlaces[56], &roadPlaces[57], &roadPlaces[63]});
    structurePlaces[45].setAdjStructs({&structurePlaces[40], &structurePlaces[41], &structurePlaces[49]});
    structurePlaces[45].setAdjRoads({&roadPlaces[58], &roadPlaces[59], &roadPlaces[64]});
    structurePlaces[46].setAdjStructs({&structurePlaces[41], &structurePlaces[42], &structurePlaces[50]});
    structurePlaces[46].setAdjRoads({&roadPlaces[60], &roadPlaces[61], &roadPlaces[65]});
    structurePlaces[47].setAdjStructs({&structurePlaces[43], &structurePlaces[51]});
    structurePlaces[47].setAdjRoads({&roadPlaces[62], &roadPlaces[66]});
    structurePlaces[48].setAdjStructs({&structurePlaces[44], &structurePlaces[52], &structurePlaces[51]});
    structurePlaces[48].setAdjRoads({&roadPlaces[63], &roadPlaces[68], &roadPlaces[67]});
    structurePlaces[49].setAdjStructs({&structurePlaces[45], &structurePlaces[53], &structurePlaces[52]});
    structurePlaces[49].setAdjRoads({&roadPlaces[64], &roadPlaces[70], &roadPlaces[69]});
    structurePlaces[50].setAdjStructs({&structurePlaces[46], &structurePlaces[53]});
    structurePlaces[50].setAdjRoads({&roadPlaces[65], &roadPlaces[71]});
    structurePlaces[51].setAdjStructs({&structurePlaces[47], &structurePlaces[48]});
    structurePlaces[51].setAdjRoads({&roadPlaces[66], &roadPlaces[67]});
    structurePlaces[52].setAdjStructs({&structurePlaces[48], &structurePlaces[49]});
    structurePlaces[52].setAdjRoads({&roadPlaces[68], &roadPlaces[69]});
    structurePlaces[53].setAdjStructs({&structurePlaces[49], &structurePlaces[50]});
    structurePlaces[53].setAdjRoads({&roadPlaces[70], &roadPlaces[71]});

    roadPlaces[0].setAdjStructs({&structurePlaces[0], &structurePlaces[3]});
    roadPlaces[0].setAdjRoads({nullptr, &roadPlaces[1], nullptr, &roadPlaces[6]});
    roadPlaces[1].setAdjStructs({&structurePlaces[0], &structurePlaces[4]});
    roadPlaces[1].setAdjRoads({&roadPlaces[0],nullptr, &roadPlaces[7], &roadPlaces[2]});
    roadPlaces[2].setAdjStructs({&structurePlaces[1], &structurePlaces[4]});
    roadPlaces[2].setAdjRoads({&roadPlaces[3],nullptr, &roadPlaces[1], &roadPlaces[7]});
    roadPlaces[3].setAdjStructs({&structurePlaces[1], &structurePlaces[5]});
    roadPlaces[3].setAdjRoads({nullptr, &roadPlaces[2], &roadPlaces[8], &roadPlaces[4]});
    roadPlaces[4].setAdjStructs({&structurePlaces[2], &structurePlaces[5]});
    roadPlaces[4].setAdjRoads({&roadPlaces[5],nullptr, &roadPlaces[3], &roadPlaces[8]});
    roadPlaces[5].setAdjStructs({&structurePlaces[2], &structurePlaces[6]});
    roadPlaces[5].setAdjRoads({nullptr,&roadPlaces[4], nullptr, &roadPlaces[9]});
    roadPlaces[6].setAdjStructs({&structurePlaces[3], &structurePlaces[7]});
    roadPlaces[6].setAdjRoads({&roadPlaces[0],nullptr, &roadPlaces[10], &roadPlaces[11]});
    roadPlaces[7].setAdjStructs({&structurePlaces[4], &structurePlaces[8]});
    roadPlaces[7].setAdjRoads({&roadPlaces[1],&roadPlaces[2], &roadPlaces[12], &roadPlaces[13]});
    roadPlaces[8].setAdjStructs({&structurePlaces[5], &structurePlaces[9]});
    roadPlaces[8].setAdjRoads({&roadPlaces[3],&roadPlaces[4], &roadPlaces[14], &roadPlaces[15]});
    roadPlaces[9].setAdjStructs({&structurePlaces[6], &structurePlaces[10]});
    roadPlaces[9].setAdjRoads({&roadPlaces[5],nullptr, &roadPlaces[16], &roadPlaces[17]});
    roadPlaces[10].setAdjStructs({&structurePlaces[7], &structurePlaces[11]});
    roadPlaces[10].setAdjRoads({&roadPlaces[6],&roadPlaces[11], &roadPlaces[18], nullptr});
    roadPlaces[11].setAdjStructs({&structurePlaces[7], &structurePlaces[12]});
    roadPlaces[11].setAdjRoads({&roadPlaces[10],&roadPlaces[6], &roadPlaces[19], &roadPlaces[12]});
    roadPlaces[12].setAdjStructs({&structurePlaces[8], &structurePlaces[12]});
    roadPlaces[12].setAdjRoads({&roadPlaces[7],&roadPlaces[13], &roadPlaces[11], &roadPlaces[19]});
    roadPlaces[13].setAdjStructs({&structurePlaces[8], &structurePlaces[13]});
    roadPlaces[13].setAdjRoads({&roadPlaces[7],&roadPlaces[12], &roadPlaces[20], &roadPlaces[14]});
    roadPlaces[14].setAdjStructs({&structurePlaces[9], &structurePlaces[13]});
    roadPlaces[14].setAdjRoads({&roadPlaces[8],&roadPlaces[15], &roadPlaces[13], &roadPlaces[20]});
    roadPlaces[15].setAdjStructs({&structurePlaces[9], &structurePlaces[14]});
    roadPlaces[15].setAdjRoads({&roadPlaces[8],&roadPlaces[14], &roadPlaces[21], &roadPlaces[16]});
    roadPlaces[16].setAdjStructs({&structurePlaces[10], &structurePlaces[14]});
    roadPlaces[16].setAdjRoads({&roadPlaces[9],&roadPlaces[17], &roadPlaces[15], &roadPlaces[21]});
    roadPlaces[17].setAdjStructs({&structurePlaces[10], &structurePlaces[15]});
    roadPlaces[17].setAdjRoads({&roadPlaces[9],&roadPlaces[16], nullptr, &roadPlaces[22]});
    roadPlaces[18].setAdjStructs({&structurePlaces[11], &structurePlaces[16]});
    roadPlaces[18].setAdjRoads({&roadPlaces[10],nullptr, &roadPlaces[23], &roadPlaces[24]});
    roadPlaces[19].setAdjStructs({&structurePlaces[12], &structurePlaces[17]});
    roadPlaces[19].setAdjRoads({&roadPlaces[11],&roadPlaces[12], &roadPlaces[25], &roadPlaces[26]});
    roadPlaces[20].setAdjStructs({&structurePlaces[13], &structurePlaces[18]});
    roadPlaces[20].setAdjRoads({&roadPlaces[13],&roadPlaces[14], &roadPlaces[27], &roadPlaces[28]});
    roadPlaces[21].setAdjStructs({&structurePlaces[14], &structurePlaces[19]});
    roadPlaces[21].setAdjRoads({&roadPlaces[15],&roadPlaces[16], &roadPlaces[29], &roadPlaces[30]});
    roadPlaces[22].setAdjStructs({&structurePlaces[15], &structurePlaces[20]});
    roadPlaces[22].setAdjRoads({&roadPlaces[17],nullptr, &roadPlaces[31], &roadPlaces[32]});
    roadPlaces[23].setAdjStructs({&structurePlaces[16], &structurePlaces[21]});
    roadPlaces[23].setAdjRoads({&roadPlaces[18],&roadPlaces[24], &roadPlaces[33], nullptr});
    roadPlaces[24].setAdjStructs({&structurePlaces[16], &structurePlaces[22]});
    roadPlaces[24].setAdjRoads({&roadPlaces[18],&roadPlaces[23], &roadPlaces[34], &roadPlaces[25]});
    roadPlaces[25].setAdjStructs({&structurePlaces[17], &structurePlaces[22]});
    roadPlaces[25].setAdjRoads({&roadPlaces[19],&roadPlaces[26], &roadPlaces[24], &roadPlaces[34]});
    roadPlaces[26].setAdjStructs({&structurePlaces[17], &structurePlaces[23]});
    roadPlaces[26].setAdjRoads({&roadPlaces[19],&roadPlaces[25], &roadPlaces[35], &roadPlaces[27]});
    roadPlaces[27].setAdjStructs({&structurePlaces[18], &structurePlaces[23]});
    roadPlaces[27].setAdjRoads({&roadPlaces[20],&roadPlaces[28], &roadPlaces[26], &roadPlaces[35]});
    roadPlaces[28].setAdjStructs({&structurePlaces[18], &structurePlaces[24]});
    roadPlaces[28].setAdjRoads({&roadPlaces[20],&roadPlaces[27], &roadPlaces[36], &roadPlaces[29]});
    roadPlaces[29].setAdjStructs({&structurePlaces[19], &structurePlaces[24]});
    roadPlaces[29].setAdjRoads({&roadPlaces[21],&roadPlaces[30], &roadPlaces[28], &roadPlaces[36]});
    roadPlaces[30].setAdjStructs({&structurePlaces[19], &structurePlaces[25]});
    roadPlaces[30].setAdjRoads({&roadPlaces[21],&roadPlaces[29], &roadPlaces[37], &roadPlaces[31]});
    roadPlaces[31].setAdjStructs({&structurePlaces[20], &structurePlaces[25]});
    roadPlaces[31].setAdjRoads({&roadPlaces[22],&roadPlaces[32], &roadPlaces[30], &roadPlaces[37]});
    roadPlaces[32].setAdjStructs({&structurePlaces[20], &structurePlaces[26]});
    roadPlaces[32].setAdjRoads({&roadPlaces[22],&roadPlaces[31], &roadPlaces[38], nullptr});
    roadPlaces[33].setAdjStructs({&structurePlaces[21], &structurePlaces[27]});
    roadPlaces[33].setAdjRoads({&roadPlaces[23],nullptr, &roadPlaces[39], nullptr});
    roadPlaces[34].setAdjStructs({&structurePlaces[22], &structurePlaces[28]});
    roadPlaces[34].setAdjRoads({&roadPlaces[24],&roadPlaces[25], &roadPlaces[40], &roadPlaces[41]});
    roadPlaces[35].setAdjStructs({&structurePlaces[23], &structurePlaces[29]});
    roadPlaces[35].setAdjRoads({&roadPlaces[26],&roadPlaces[27], &roadPlaces[42], &roadPlaces[43]});
    roadPlaces[36].setAdjStructs({&structurePlaces[24], &structurePlaces[30]});
    roadPlaces[36].setAdjRoads({&roadPlaces[28],&roadPlaces[29], &roadPlaces[44], &roadPlaces[45]});
    roadPlaces[37].setAdjStructs({&structurePlaces[25], &structurePlaces[31]});
    roadPlaces[37].setAdjRoads({&roadPlaces[30],&roadPlaces[31], &roadPlaces[46], &roadPlaces[47]});
    roadPlaces[38].setAdjStructs({&structurePlaces[26], &structurePlaces[32]});
    roadPlaces[38].setAdjRoads({&roadPlaces[32],nullptr, &roadPlaces[48], nullptr});
    roadPlaces[39].setAdjStructs({&structurePlaces[27], &structurePlaces[33]});
    roadPlaces[39].setAdjRoads({&roadPlaces[33],nullptr, &roadPlaces[40], &roadPlaces[49]});
    roadPlaces[40].setAdjStructs({&structurePlaces[28], &structurePlaces[33]});
    roadPlaces[40].setAdjRoads({&roadPlaces[34],&roadPlaces[41], &roadPlaces[39], &roadPlaces[49]});
    roadPlaces[41].setAdjStructs({&structurePlaces[28], &structurePlaces[34]});
    roadPlaces[41].setAdjRoads({&roadPlaces[34],&roadPlaces[40], &roadPlaces[50], &roadPlaces[42]});
    roadPlaces[42].setAdjStructs({&structurePlaces[29], &structurePlaces[34]});
    roadPlaces[42].setAdjRoads({&roadPlaces[35],&roadPlaces[43], &roadPlaces[41], &roadPlaces[50]});
    roadPlaces[43].setAdjStructs({&structurePlaces[29], &structurePlaces[35]});
    roadPlaces[43].setAdjRoads({&roadPlaces[35],&roadPlaces[42], &roadPlaces[51], &roadPlaces[44]});
    roadPlaces[44].setAdjStructs({&structurePlaces[30], &structurePlaces[35]});
    roadPlaces[44].setAdjRoads({&roadPlaces[36],&roadPlaces[45], &roadPlaces[43], &roadPlaces[51]});
    roadPlaces[45].setAdjStructs({&structurePlaces[30], &structurePlaces[36]});
    roadPlaces[45].setAdjRoads({&roadPlaces[36],&roadPlaces[44], &roadPlaces[52], &roadPlaces[46]});
    roadPlaces[46].setAdjStructs({&structurePlaces[31], &structurePlaces[36]});
    roadPlaces[46].setAdjRoads({&roadPlaces[37],&roadPlaces[47], &roadPlaces[45], &roadPlaces[52]});
    roadPlaces[47].setAdjStructs({&structurePlaces[31], &structurePlaces[37]});
    roadPlaces[47].setAdjRoads({&roadPlaces[37],&roadPlaces[46], &roadPlaces[48], &roadPlaces[53]});
    roadPlaces[48].setAdjStructs({&structurePlaces[32], &structurePlaces[37]});
    roadPlaces[48].setAdjRoads({&roadPlaces[38],nullptr, &roadPlaces[47], &roadPlaces[53]});
    roadPlaces[49].setAdjStructs({&structurePlaces[33], &structurePlaces[38]});
    roadPlaces[49].setAdjRoads({&roadPlaces[39],&roadPlaces[40], nullptr, &roadPlaces[54]});
    roadPlaces[50].setAdjStructs({&structurePlaces[34], &structurePlaces[39]});
    roadPlaces[50].setAdjRoads({&roadPlaces[41],&roadPlaces[42], &roadPlaces[55], &roadPlaces[56]});
    roadPlaces[51].setAdjStructs({&structurePlaces[35], &structurePlaces[40]});
    roadPlaces[51].setAdjRoads({&roadPlaces[43],&roadPlaces[44], &roadPlaces[57], &roadPlaces[58]});
    roadPlaces[52].setAdjStructs({&structurePlaces[36], &structurePlaces[41]});
    roadPlaces[52].setAdjRoads({&roadPlaces[45],&roadPlaces[46], &roadPlaces[59], &roadPlaces[60]});
    roadPlaces[53].setAdjStructs({&structurePlaces[37], &structurePlaces[42]});
    roadPlaces[53].setAdjRoads({&roadPlaces[47],&roadPlaces[48], &roadPlaces[61], nullptr});
    roadPlaces[54].setAdjStructs({&structurePlaces[38], &structurePlaces[43]});
    roadPlaces[54].setAdjRoads({&roadPlaces[49],nullptr, &roadPlaces[55], &roadPlaces[62]});
    roadPlaces[55].setAdjStructs({&structurePlaces[39], &structurePlaces[43]});
    roadPlaces[55].setAdjRoads({&roadPlaces[50],&roadPlaces[56], &roadPlaces[54], &roadPlaces[62]});
    roadPlaces[56].setAdjStructs({&structurePlaces[39], &structurePlaces[44]});
    roadPlaces[56].setAdjRoads({&roadPlaces[50],&roadPlaces[55], &roadPlaces[63], &roadPlaces[57]});
    roadPlaces[57].setAdjStructs({&structurePlaces[40], &structurePlaces[44]});
    roadPlaces[57].setAdjRoads({&roadPlaces[51],&roadPlaces[58], &roadPlaces[56], &roadPlaces[63]});
    roadPlaces[58].setAdjStructs({&structurePlaces[40], &structurePlaces[45]});
    roadPlaces[58].setAdjRoads({&roadPlaces[51],&roadPlaces[57], &roadPlaces[64], &roadPlaces[59]});
    roadPlaces[59].setAdjStructs({&structurePlaces[41], &structurePlaces[45]});
    roadPlaces[59].setAdjRoads({&roadPlaces[52],&roadPlaces[60], &roadPlaces[58], &roadPlaces[64]});
    roadPlaces[60].setAdjStructs({&structurePlaces[41], &structurePlaces[46]});
    roadPlaces[60].setAdjRoads({&roadPlaces[52],&roadPlaces[59], &roadPlaces[65], &roadPlaces[61]});
    roadPlaces[61].setAdjStructs({&structurePlaces[42], &structurePlaces[46]});
    roadPlaces[61].setAdjRoads({&roadPlaces[53],nullptr, &roadPlaces[60], &roadPlaces[65]});
    roadPlaces[62].setAdjStructs({&structurePlaces[43], &structurePlaces[47]});
    roadPlaces[62].setAdjRoads({&roadPlaces[54],&roadPlaces[55], nullptr, &roadPlaces[66]});
    roadPlaces[63].setAdjStructs({&structurePlaces[44], &structurePlaces[48]});
    roadPlaces[63].setAdjRoads({&roadPlaces[56],&roadPlaces[57], &roadPlaces[68], &roadPlaces[67]});
    roadPlaces[64].setAdjStructs({&structurePlaces[45], &structurePlaces[49]});
    roadPlaces[64].setAdjRoads({&roadPlaces[58],&roadPlaces[59], &roadPlaces[69], &roadPlaces[70]});
    roadPlaces[65].setAdjStructs({&structurePlaces[46], &structurePlaces[50]});
    roadPlaces[65].setAdjRoads({&roadPlaces[60],&roadPlaces[61], &roadPlaces[71], nullptr});
    roadPlaces[66].setAdjStructs({&structurePlaces[47], &structurePlaces[51]});
    roadPlaces[66].setAdjRoads({&roadPlaces[62],nullptr, nullptr, &roadPlaces[67]});
    roadPlaces[67].setAdjStructs({&structurePlaces[48], &structurePlaces[51]});
    roadPlaces[67].setAdjRoads({&roadPlaces[63],&roadPlaces[68], &roadPlaces[66], nullptr});
    roadPlaces[68].setAdjStructs({&structurePlaces[48], &structurePlaces[52]});
    roadPlaces[68].setAdjRoads({&roadPlaces[63],&roadPlaces[67], nullptr, &roadPlaces[69]});
    roadPlaces[69].setAdjStructs({&structurePlaces[49], &structurePlaces[52]});
    roadPlaces[69].setAdjRoads({&roadPlaces[64],&roadPlaces[70], &roadPlaces[68], nullptr});
    roadPlaces[70].setAdjStructs({&structurePlaces[49], &structurePlaces[53]});
    roadPlaces[70].setAdjRoads({&roadPlaces[64],&roadPlaces[69], nullptr, &roadPlaces[71]});
    roadPlaces[71].setAdjStructs({&structurePlaces[50], &structurePlaces[53]});
    roadPlaces[71].setAdjRoads({&roadPlaces[65],nullptr, &roadPlaces[70], nullptr});

    
    

    tiles[0].setResourceAndNumber("Mountains", 10);
    tiles[1].setResourceAndNumber("Pasture", 2);
    tiles[2].setResourceAndNumber("Forrest", 9);
    tiles[3].setResourceAndNumber("Fields", 12);
    tiles[4].setResourceAndNumber("Hills", 6);
    tiles[5].setResourceAndNumber("Pasture", 4);
    tiles[6].setResourceAndNumber("Hills", 10);
    tiles[7].setResourceAndNumber("Fields", 9);
    tiles[8].setResourceAndNumber("Forrest", 11);
    tiles[9].setResourceAndNumber("Desert", 0);
    tiles[10].setResourceAndNumber("Forrest", 3);
    tiles[11].setResourceAndNumber("Mountains", 8);
    tiles[12].setResourceAndNumber("Forrest", 8);
    tiles[13].setResourceAndNumber("Mountains", 3);
    tiles[14].setResourceAndNumber("Fields", 4);
    tiles[15].setResourceAndNumber("Pasture", 5);
    tiles[16].setResourceAndNumber("Hills", 5);
    tiles[17].setResourceAndNumber("Fields", 6);
    tiles[18].setResourceAndNumber("Pasture", 11);

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


