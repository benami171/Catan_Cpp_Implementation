#include <string>
#include <iostream>


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