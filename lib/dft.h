#ifndef DFT_H
#define DFT_H

#include "helper.h"
#include "fourier.h"

namespace DFT
{
    FourierCoefficients Solve(const FourierHelper::Data& data)
    {
        return {};
    }
};

TEST_SUITE("Fourier test suite") {
    TEST_CASE ("DFT test") {
        FourierHelper::Data data = FourierHelper::ParseDataFile("testData.txt");
        REQUIRE(data);

        FourierHelper::Data expectedResults = FourierHelper::ParseDataFile("testResults.txt");
        REQUIRE(expectedResults);

        FourierCoefficients coefficients = DFT::Solve(data);

        CHECK(FourierHelper::Equal(expectedResults, coefficients));
    }
}

#endif