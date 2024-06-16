#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
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
    CHECK_THROWS(_p3.placeSettlement(12, game));
    CHECK_THROWS(_p2.placeRoad(11, game));
    CHECK_THROWS(_p2.tradeWithBank({{"wheat", 1}}, {{"ore", 1}}, game));
    CHECK_THROWS(_p2.trade({{"brick", 1}, {"lumber", 1}}, {{"wheat", 1}, {"wool", 1}}, _p3));
    CHECK_THROWS(_p3.buyDevelopmentCard("knight", game));
    CHECK_THROWS(_p3.rollDice(6));
}

TEST_CASE("Invalid INITIAL settlement/road placement"){
    game.startTurn("P1");
    _p1.placeInitialSettlement(2, game);
    CHECK_THROWS(_p1.placeInitialRoad(8, game)); // too far from settlement
    _p1.placeInitialRoad(5, game);
    game.endTurn();
    CHECK_THROWS(_p2.placeInitialSettlement(5, game)); // too close to P1's settlement
    CHECK_THROWS(_p2.placeInitialSettlement(54, game)); // OUT OF BOUNDS
    _p2.placeInitialSettlement(10, game);

}