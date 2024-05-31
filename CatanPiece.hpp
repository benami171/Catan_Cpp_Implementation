#include <string>
#include <iostream>


using namespace std;
class CatanPiece {
    
public:
    CatanPiece(const string& owner, int structId);
    string getOwner() const;

private:
    string owner;
    int structId;
};

CatanPiece::CatanPiece(const string& owner, int structId)
    : owner(owner), structId(structId) {}

string CatanPiece::getOwner() const {
    return owner;
}