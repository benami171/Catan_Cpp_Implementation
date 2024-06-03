#include <iostream>
#include <string>
#ifndef CATAN_PIECE_HPP
#define CATAN_PIECE_HPP

using namespace std;

namespace Catan {

class Catan_Piece {
   private:
    string owner;

   public:
    Catan_Piece() : owner("") {}  // Default constructor
    Catan_Piece(const string& owner) : owner(owner){};
    string getOwner() const { return owner; };
};

}  // namespace Catan

#endif  // CATANPIECE_HPP