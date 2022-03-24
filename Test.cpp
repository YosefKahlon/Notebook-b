/**
 *
 *
 * AUTHORS: <Yosef Or Kahlon>
 *
 * Date: 2022 - 3
 */

#include "doctest.h"
#include "Notebook.hpp"
#include "sources/Direction.hpp"

using namespace ariel;

#include <string>
#include <algorithm>

using namespace std;


TEST_CASE ("1") {

    Notebook test;

            SUBCASE("-------------write------------") {
        //negative page
        CHECK_THROWS(test.write(-1, 1, 3, Direction::Horizontal, "d"));
        CHECK_THROWS(test.write(-1, 1, 3, Direction::Vertical, "d"));


        //negative row
        CHECK_THROWS(test.write(1, -1, 3, Direction::Horizontal, "d"));
        CHECK_THROWS(test.write(1, -1, 3, Direction::Vertical, "d"));


        //negative col
        CHECK_THROWS(test.write(1, 1, -3, Direction::Horizontal, "d"));
        CHECK_THROWS(test.write(1, 1, -3, Direction::Vertical, "d"));
    }

            SUBCASE("-------------read------------") {
        //negative page
        CHECK_THROWS(test.read(-1, 1, 3, Direction::Horizontal, 1));
        CHECK_THROWS(test.read(-1, 1, 3, Direction::Vertical, 1));


        //negative row
        CHECK_THROWS(test.read(1, -1, 3, Direction::Horizontal, 1));
        CHECK_THROWS(test.read(1, -1, 3, Direction::Vertical, 1));


        //negative col
        CHECK_THROWS(test.read(1, 1, -3, Direction::Horizontal, 1));
        CHECK_THROWS(test.read(1, 1, -3, Direction::Vertical, 1));


        //negative length to read
        CHECK_THROWS(test.read(1, 1, 3, Direction::Vertical, -1));
    }


            SUBCASE("-------------erase------------") {
        //negative page
        CHECK_THROWS(test.erase(-1, 1, 3, Direction::Horizontal, 1));
        CHECK_THROWS(test.erase(-1, 1, 3, Direction::Vertical, 1));

        //negative row
        CHECK_THROWS(test.erase(1, -1, 3, Direction::Horizontal, 1));
        CHECK_THROWS(test.erase(1, -1, 3, Direction::Vertical, 1));


        //negative col
        CHECK_THROWS(test.erase(1, 1, -3, Direction::Horizontal, 1));
        CHECK_THROWS(test.read(1, 1, -3, Direction::Vertical, 1));

        //negative length to read
        CHECK_THROWS(test.erase(1, 1, 3, Direction::Vertical, -2));
        CHECK_THROWS(test.erase(1, 1, 3, Direction::Horizontal, -6));
    }

}

TEST_CASE ("2") {
    Notebook test;
    CHECK_THROWS(test.read(1, 1, 3, Direction::Vertical, 102));
    CHECK_THROWS(test.read(1, 1, 3, Direction::Horizontal, 102));
    CHECK_THROWS(test.erase(1, 1, 3, Direction::Horizontal, 102));


    CHECK_THROWS(test.write(1, 1, 102, Direction::Horizontal, "sss"));
    CHECK_THROWS(test.write(1, 1, 102, Direction::Vertical, "sss"));

    CHECK_THROWS(test.read(1, 1, 102, Direction::Vertical, 1));
    CHECK_THROWS(test.read(1, 1, 102, Direction::Horizontal, 1));

    CHECK_THROWS(test.erase(1, 1, 102, Direction::Horizontal, 2));
    CHECK_THROWS(test.erase(1, 1, 102, Direction::Horizontal, 2));

}

TEST_CASE ("3") {

    Notebook test;

    test.write(10, 10, 10, Direction::Vertical, "TEST");
            CHECK(test.read(10, 10, 10, Direction::Vertical, 4) == "TEST");
            CHECK(test.read(10, 10, 11, Direction::Vertical, 4) == "EST_");
            CHECK(test.read(10, 10, 11, Direction::Vertical, 3) == "_ES");

    test.erase(10, 10, 10, Direction::Vertical, 3);
            CHECK(test.read(10, 10, 10, Direction::Vertical, 4) == "~~~T");

    test.write(50, 50, 50, Direction::Vertical, "TEST");
            CHECK(test.read(50, 50, 50, Direction::Horizontal, 4) == "T___");

    test.write(60, 60, 60, Direction::Horizontal, "TEST");
            CHECK(test.read(60, 60, 60, Direction::Vertical, 4) == "T___");

    test.write(70, 60, 60, Direction::Horizontal, "TEST TEST");
            CHECK(test.read(70, 60, 60, Direction::Vertical, 8) == "TEST_TES");

    test.erase(70, 60, 64, Direction::Vertical, 1);
            CHECK(test.read(70, 60, 64, Direction::Vertical, 8) == "TEST~TEST");
    test.erase(70, 60, 60, Direction::Vertical, 1);
    test.erase(70, 60, 68, Direction::Vertical, 1);
            CHECK(test.read(70, 60, 64, Direction::Vertical, 8) == "~EST~TES~");
}

TEST_CASE ("4") {
    Notebook test;

    SUBCASE("can't write here ") {
        test.write(11, 11, 11, Direction::Vertical, "TEST");
        CHECK_THROWS(test.write(11, 11, 12, Direction::Vertical, "TEST"));
        CHECK_THROWS(test.write(11, 11, 12, Direction::Horizontal, "TEST"));
    }

}




