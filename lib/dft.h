#ifndef FOURIER_H
#define FOURIER_H

#include "helper.h"
#include "fourier.h"

TEST_SUITE("Fourier test suite") {
    TEST_CASE ("DFT test") {
        TestDataHelper::Data data = TestDataHelper::ParseDataFile("testData.txt");
        REQUIRE(data);

        CHECK(false);
    }
}

#endif