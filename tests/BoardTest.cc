//
// Created by Ryan Gurnick on 2019-05-09.
//
#include <gtest/gtest.h>
#include "../heads/Board.h"

TEST(BoardH, testPattern) {
    Board b;
    ASSERT_EQ(b.printBoard(), "0123456789\n\n0101010101\t0\n1010101010\t1\n0101010101\t2\n1010101010\t3\n0101010101\t4\n1010101010\t5\n0101010101\t6\n1010101010\t7\n0101010101\t8\n1010101010\t9\n");
}

TEST(BoardH, testTiles){
    Board b;
    ASSERT_EQ(b.printTiles(), "Tile[0-1-0](sX: 1 sY: 0 cX: 1 cY: 0 valid: 1 king: 0 player: 0)\nTile[0-3-0](sX: 3 sY: 0 cX: 3 cY: 0 valid: 1 king: 0 player: 0)\nTile[0-5-0](sX: 5 sY: 0 cX: 5 cY: 0 valid: 1 king: 0 player: 0)\nTile[0-7-0](sX: 7 sY: 0 cX: 7 cY: 0 valid: 1 king: 0 player: 0)\nTile[0-9-0](sX: 9 sY: 0 cX: 9 cY: 0 valid: 1 king: 0 player: 0)\nTile[0-0-1](sX: 0 sY: 1 cX: 0 cY: 1 valid: 1 king: 0 player: 0)\nTile[0-2-1](sX: 2 sY: 1 cX: 2 cY: 1 valid: 1 king: 0 player: 0)\nTile[0-4-1](sX: 4 sY: 1 cX: 4 cY: 1 valid: 1 king: 0 player: 0)\nTile[0-6-1](sX: 6 sY: 1 cX: 6 cY: 1 valid: 1 king: 0 player: 0)\nTile[0-8-1](sX: 8 sY: 1 cX: 8 cY: 1 valid: 1 king: 0 player: 0)\nTile[0-1-2](sX: 1 sY: 2 cX: 1 cY: 2 valid: 1 king: 0 player: 0)\nTile[0-3-2](sX: 3 sY: 2 cX: 3 cY: 2 valid: 1 king: 0 player: 0)\nTile[0-5-2](sX: 5 sY: 2 cX: 5 cY: 2 valid: 1 king: 0 player: 0)\nTile[0-7-2](sX: 7 sY: 2 cX: 7 cY: 2 valid: 1 king: 0 player: 0)\nTile[0-9-2](sX: 9 sY: 2 cX: 9 cY: 2 valid: 1 king: 0 player: 0)\nTile[0-0-3](sX: 0 sY: 3 cX: 0 cY: 3 valid: 1 king: 0 player: 0)\nTile[0-2-3](sX: 2 sY: 3 cX: 2 cY: 3 valid: 1 king: 0 player: 0)\nTile[0-4-3](sX: 4 sY: 3 cX: 4 cY: 3 valid: 1 king: 0 player: 0)\nTile[0-6-3](sX: 6 sY: 3 cX: 6 cY: 3 valid: 1 king: 0 player: 0)\nTile[0-8-3](sX: 8 sY: 3 cX: 8 cY: 3 valid: 1 king: 0 player: 0)\nTile[1-1-6](sX: 1 sY: 6 cX: 1 cY: 6 valid: 1 king: 0 player: 1)\nTile[1-3-6](sX: 3 sY: 6 cX: 3 cY: 6 valid: 1 king: 0 player: 1)\nTile[1-5-6](sX: 5 sY: 6 cX: 5 cY: 6 valid: 1 king: 0 player: 1)\nTile[1-7-6](sX: 7 sY: 6 cX: 7 cY: 6 valid: 1 king: 0 player: 1)\nTile[1-9-6](sX: 9 sY: 6 cX: 9 cY: 6 valid: 1 king: 0 player: 1)\nTile[1-0-7](sX: 0 sY: 7 cX: 0 cY: 7 valid: 1 king: 0 player: 1)\nTile[1-2-7](sX: 2 sY: 7 cX: 2 cY: 7 valid: 1 king: 0 player: 1)\nTile[1-4-7](sX: 4 sY: 7 cX: 4 cY: 7 valid: 1 king: 0 player: 1)\nTile[1-6-7](sX: 6 sY: 7 cX: 6 cY: 7 valid: 1 king: 0 player: 1)\nTile[1-8-7](sX: 8 sY: 7 cX: 8 cY: 7 valid: 1 king: 0 player: 1)\nTile[1-1-8](sX: 1 sY: 8 cX: 1 cY: 8 valid: 1 king: 0 player: 1)\nTile[1-3-8](sX: 3 sY: 8 cX: 3 cY: 8 valid: 1 king: 0 player: 1)\nTile[1-5-8](sX: 5 sY: 8 cX: 5 cY: 8 valid: 1 king: 0 player: 1)\nTile[1-7-8](sX: 7 sY: 8 cX: 7 cY: 8 valid: 1 king: 0 player: 1)\nTile[1-9-8](sX: 9 sY: 8 cX: 9 cY: 8 valid: 1 king: 0 player: 1)\nTile[1-0-9](sX: 0 sY: 9 cX: 0 cY: 9 valid: 1 king: 0 player: 1)\nTile[1-2-9](sX: 2 sY: 9 cX: 2 cY: 9 valid: 1 king: 0 player: 1)\nTile[1-4-9](sX: 4 sY: 9 cX: 4 cY: 9 valid: 1 king: 0 player: 1)\nTile[1-6-9](sX: 6 sY: 9 cX: 6 cY: 9 valid: 1 king: 0 player: 1)\nTile[1-8-9](sX: 8 sY: 9 cX: 8 cY: 9 valid: 1 king: 0 player: 1)\n");
}

TEST(BoardH, testCombined){
    Board b;
    ASSERT_EQ(b.printCombinedBoard(), "0 1 2 3 4 5 6 7 8 9 \n\n0 * 0 * 0 * 0 * 0 *   0\n* 0 * 0 * 0 * 0 * 0   1\n0 * 0 * 0 * 0 * 0 *   2\n* 0 * 0 * 0 * 0 * 0   3\n0 1 0 1 0 1 0 1 0 1   4\n1 0 1 0 1 0 1 0 1 0   5\n0 - 0 - 0 - 0 - 0 -   6\n- 0 - 0 - 0 - 0 - 0   7\n0 - 0 - 0 - 0 - 0 -   8\n- 0 - 0 - 0 - 0 - 0   9\n");
}

TEST(BoardH, testMove){
    Board b;
    b.selectTile("0-2-3");
    b.moveSelectedTile(1,1);
    ASSERT_EQ(b.printCombinedBoard(), "0 1 2 3 4 5 6 7 8 9 \n\n0 * 0 * 0 * 0 * 0 *   0\n* 0 * 0 * 0 * 0 * 0   1\n0 * 0 * 0 * 0 * 0 *   2\n* 0 1 0 * 0 * 0 * 0   3\n0 1 0 * 0 1 0 1 0 1   4\n1 0 1 0 1 0 1 0 1 0   5\n0 - 0 - 0 - 0 - 0 -   6\n- 0 - 0 - 0 - 0 - 0   7\n0 - 0 - 0 - 0 - 0 -   8\n- 0 - 0 - 0 - 0 - 0   9\n");
    b.selectTile("0-3-4");
    b.moveSelectedTile(-1,1);
    ASSERT_EQ(b.printCombinedBoard(), "0 1 2 3 4 5 6 7 8 9 \n\n0 * 0 * 0 * 0 * 0 *   0\n* 0 * 0 * 0 * 0 * 0   1\n0 * 0 * 0 * 0 * 0 *   2\n* 0 1 0 * 0 * 0 * 0   3\n0 1 0 1 0 1 0 1 0 1   4\n1 0 * 0 1 0 1 0 1 0   5\n0 - 0 - 0 - 0 - 0 -   6\n- 0 - 0 - 0 - 0 - 0   7\n0 - 0 - 0 - 0 - 0 -   8\n- 0 - 0 - 0 - 0 - 0   9\n");
}