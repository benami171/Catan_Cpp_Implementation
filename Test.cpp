#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "CatanGame.hpp"
#include "Player.hpp"
#include "doctest.h"

using namespace doctest;
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
    game.endTurn(); // sets the turn to P1
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
    SUBCASE("trying to build without required resources") {
        _p1.placeRoad(32, game);
        _p1.placeSettlement(26, game);
        _p1.placeRoad(38,game);
        _p1.placeCity(26, game);
        _p1.placeCity(2, game);
        CHECK_THROWS(_p1.placeCity(25, game));
    }
    SUBCASE("trying to build on top of a road") {
        _p1.placeRoad(32, game);
        CHECK_THROWS(_p1.placeSettlement(32, game));
        CHECK_THROWS(_p1.placeCity(32, game));
    }
}

TEST_CASE("Invalid development card usage"){
    before_each();
    SUBCASE("trying to play a development card without having one") {
        CHECK(_p1.useYearOfPlenty("wool","lumber" ,game) == false);
    }
    SUBCASE("trying to play a development card in the same turn it was bought") {
        _p1.buyDevelopmentCard("yearOfPlenty", game);
        CHECK(_p1.useYearOfPlenty("wool","lumber", game) == false);
    }
    SUBCASE("trying to play a development card that has already been played") {
        _p1.buyDevelopmentCard("roadBuilding", game);
        _p1.useRoadBuilding(3,4, game);
        CHECK(_p1.useRoadBuilding(3,4, game) == false);
    }
}

TEST_CASE("Invalid trades"){
    before_each();
    SUBCASE("trying to trade with the bank without having enough resources") {
        CHECK(_p1.tradeWithBank({{"wheat", 1}}, {{"ore", 1}}, game) == false);
    }
    SUBCASE("trying to trade with another player without having enough resources") {
        CHECK(_p1.trade({{"brick", 9}}, {{"wheat", 1}, {"wool", 1}}, _p2) == false);
    }
    SUBCASE("trying to trade with another player without him having enough resources") {
        CHECK(_p1.trade({{"brick", 1}}, {{"wheat", 9}, {"wool", 9}}, _p2) == false);
    }
    SUBCASE("trying to trade with myself") {
        CHECK(_p1.trade({{"brick", 1}}, {{"wheat", 1}, {"wool", 1}}, _p1) == false);
    }
}

TEST_CASE("Playing out of turn") {
    before_each();
    SUBCASE("trying to place initial settlement out of turn") {
        CHECK_THROWS(_p1.placeInitialSettlement(13, game));
    }
    SUBCASE("trying to place settlement out of turn") {
        game.endTurn();
        CHECK_THROWS(_p1.placeSettlement(12, game));
    }
    SUBCASE("trying to place road out of turn") {
        game.endTurn();
        CHECK_THROWS(_p1.placeRoad(11, game));
    }
    SUBCASE("trying to trade with bank out of turn") {
        game.endTurn();
        CHECK_THROWS(_p1.tradeWithBank({{"wheat", 1}}, {{"ore", 1}}, game));
    }
    SUBCASE("trying to trade with another player out of turn") {
        game.endTurn();
        CHECK(_p1.trade({{"brick", 1}, {"lumber", 1}}, {{"wheat", 1}, {"wool", 1}}, _p3) == false);
    }
    SUBCASE("trying to buy a development card out of turn") {
        game.endTurn();
        CHECK_THROWS(_p3.buyDevelopmentCard("knight", game));
    }
    SUBCASE("trying to roll the dice out of turn") {
        game.endTurn();
        CHECK_THROWS(_p3.rollDice(6));
    }
}