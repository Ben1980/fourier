#ifndef DFT_H
#define DFT_H

#include "helper.h"
#include "fourier.h"

namespace DFT
{
    FourierCoefficients Solve(const InputData& data)
    {
        return {};
    }
};

TEST_SUITE("Fourier test suite") {
    TEST_CASE ("DFT test") {
        InputData data = FourierHelper::ParseInputDataFile("testData.txt");
        REQUIRE(data);

        FourierCoefficients expectedResults = FourierHelper::ParseOutputDataFile("testResults.txt");
        REQUIRE(expectedResults);

        FourierCoefficients coefficients = DFT::Solve(data);

        CHECK(FourierHelper::Equal(expectedResults, coefficients));
    }
}

#endif