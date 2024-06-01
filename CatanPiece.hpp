#include <string>
#include <iostream>
#ifndef CATANPIECE_HPP
#define CATANPIECE_HPP

using namespace std;
class CatanPiece {
    
public:
    CatanPiece(const string& owner);
    string getOwner() const;

private:
    string owner;
    int structId;
};

CatanPiece::CatanPiece(const string& owner)
    : owner(owner){}

string CatanPiece::getOwner() const {
    return owner;
}

#endif  // CATANPIECE_HPP