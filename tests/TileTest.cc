//
// Created by Ryan Gurnick on 2019-05-13.
//
#include <gtest/gtest.h>
#include "../heads/Tile.h"

TEST(TileH, testPrint){
    Tile t0(0,0,0);
    ASSERT_EQ(t0.printTile(), "Tile[0-0-0](sX: 0 sY: 0 cX: 0 cY: 0 valid: 1 king: 0 player: 0)");
    Tile t1(1,1,0);
    ASSERT_EQ(t1.printTile(), "Tile[0-1-1](sX: 1 sY: 1 cX: 1 cY: 1 valid: 1 king: 0 player: 0)");
}

TEST(TileH, testConstructor){
    Tile t0(0,0,0);
    ASSERT_EQ(t0.name, "0-0-0");
    ASSERT_EQ(t0.x, 0);
    ASSERT_EQ(t0.y, 0);
    ASSERT_EQ(t0.player, 0);


    Tile t1(0,0,1);
    ASSERT_EQ(t1.name, "1-0-0");
    ASSERT_EQ(t1.x, 0);
    ASSERT_EQ(t1.y, 0);
    ASSERT_EQ(t1.player, 1);

    Tile t2(2,2,1);
    ASSERT_EQ(t2.name, "1-2-2");
    ASSERT_EQ(t2.x, 2);
    ASSERT_EQ(t2.y, 2);
    ASSERT_EQ(t2.player, 1);

}

TEST(TileH, testUpdateName){
    Tile t0(0,0,0);
    ASSERT_EQ(t0.moveTile(1,1), false);
}

TEST(TileH, testMove){

}