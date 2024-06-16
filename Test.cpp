#include "doctest.h"
#include "Player.hpp"
#include "CatanGame.hpp"


using namespace std;
using namespace Catan;

Player _p1("P1");
Player _p2("P2");
Player _p3("P3");
CatanGame game(_p1, _p2, _p3);

TEST_CASE("Playing out of turn"){
    game.startTurn("P1");
    CHECK_THROWS(_p2.placeInitialSettlement(13, game));
}