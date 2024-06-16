#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "CatanGame.hpp"
#include "Player.hpp"
#include "doctest.h"

using namespace std;
using namespace Catan;

Player _p1("P1");
Player _p2("P2");
Player _p3("P3");
CatanGame game(_p1, _p2, _p3);

void before_each() {
    _p1 = Player("P1");
    _p2 = Player("P2");
    _p3 = Player("P3");
    game = CatanGame(_p1, _p2, _p3);
    game.startTurn("P1");
    _p1.placeInitialSettlement(2, game);
    _p1.placeInitialRoad(5, game);
    game.endTurn();
    _p2.placeInitialSettlement(10, game);
    _p2.placeInitialRoad(17, game);
    game.endTurn();
    _p3.placeInitialSettlement(34, game);
    _p3.placeInitialRoad(41, game);
    game.endTurn();
    _p1.placeInitialSettlement(25, game);
    _p1.placeInitialRoad(31, game);
    game.endTurn();
    _p2.placeInitialSettlement(13, game);
    _p2.placeInitialRoad(13, game);
    game.endTurn();
    _p3.placeInitialSettlement(45, game);
    _p3.placeInitialRoad(59, game);
    game.endTurn();
    game.giveResources(); // ONLY USED FOR TESTING.
    game.printBoard();
}


TEST_CASE("Invalid INITIAL settlement/road placement") {
    before_each();
    

    SUBCASE("placing road too far from settlement") {
        CHECK_THROWS(_p1.placeInitialRoad(8, game));  // too far from settlement
    }

    SUBCASE("placing road too close to settlement") {
        CHECK_THROWS(_p2.placeInitialSettlement(5, game));  // too close to P1's settlement
    }

    SUBCASE("placing 3rd initial settlement") {
        CHECK_THROWS(_p2.placeInitialSettlement(22, game));  // already placed 2 initial settlements.
    }

    CHECK_THROWS(_p2.placeInitialSettlement(54, game));  // OUT OF BOUNDS
}

TEST_CASE("Invalid settlement/city/road placements"){
    before_each();
    SUBCASE("placing settlement on top of another settlement") {
        CHECK_THROWS(_p1.placeSettlement(25, game));
    }
    SUBCASE("placing settlement too close to another settlement") {
        CHECK_THROWS(_p1.placeSettlement(20, game));
    }
    SUBCASE("placing settlement too far from road") {
        CHECK_THROWS(_p1.placeSettlement(26, game));
    }
    SUBCASE("placing settlement on top of another city") {
        _p1.placeCity(25, game);
        CHECK_THROWS(_p1.placeSettlement(25, game));
    }
    SUBCASE("placing city on top of another city") {
        _p1.placeCity(25, game);
        CHECK_THROWS(_p1.placeCity(25, game));
    }
    SUBCASE("placing city on top of another player's settlement") {
        _p1.placeCity(25, game);
        game.endTurn();
        CHECK_THROWS(_p2.placeCity(25, game));
    }
    SUBCASE("placing road on top of another road") {
        CHECK_THROWS(_p1.placeRoad(31, game));
    }
    SUBCASE("placing road too far from settlement") {
        CHECK_THROWS(_p1.placeRoad(47, game));
    }
   // game.printPlayersStats();
    SUBCASE("trying to build without resources") {
        _p1.placeRoad(32, game);
        _p1.placeSettlement(26, game);
        // _p1.placeRoad(38,game);
        // CHECK_THROWS(_p1.placeCity(26, game));
    }
}

// TEST_CASE("Playing out of turn") {
//     before_each();
//     CHECK_THROWS(_p2.placeInitialSettlement(13, game));
//     CHECK_THROWS(_p3.placeSettlement(12, game));
//     CHECK_THROWS(_p2.placeRoad(11, game));
//     CHECK_THROWS(_p2.tradeWithBank({{"wheat", 1}}, {{"ore", 1}}, game));
//     CHECK_THROWS(_p2.trade({{"brick", 1}, {"lumber", 1}}, {{"wheat", 1}, {"wool", 1}}, _p3));
//     CHECK_THROWS(_p3.buyDevelopmentCard("knight", game));
//     CHECK_THROWS(_p3.rollDice(6));
// }