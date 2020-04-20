#ifndef DFT_H
#define DFT_H

#include "../helperlib/helper.h"
#include "../helperlib/fourier.h"

namespace DFT
{
    Fourier::Coefficients Solve(const Fourier::InputData& data)
    {
        return {};
    }
};

TEST_SUITE("Fourier test suite") {
    TEST_CASE ("DFT test") {
        Fourier::InputData data = FourierHelper::ParseInputDataFile("testData.txt");
        REQUIRE(data);

        Fourier::Coefficients expectedResults = FourierHelper::ParseOutputDataFile("testResults.txt");
        REQUIRE(expectedResults);

        Fourier::Coefficients coefficients = DFT::Solve(data);

        CHECK(Fourier::Equal(expectedResults, coefficients));
    }
}

#endif