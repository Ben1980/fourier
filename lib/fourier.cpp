#include "fourier.h"
#include <algorithm>
#include <cmath>

bool Fourier::Equal(const Coefficients& expected, const Coefficients& result)
{
    if(!expected || !result) return false;
    if(expected().size() != result().size()) return false;

    const bool equal = std::equal(expected().begin(), expected().end(), result().begin(), 
    [](const Coefficients::Coefficient& expected, const Coefficients::Coefficient& result) {
        const bool equalOrder = (expected.order - result.order) == 0;
        const bool equalA = Equal(expected.a, result.a);
        const bool equalB = Equal(expected.b, result.b);

        return equalOrder && equalA && equalB;
    });

    return equal;
}

bool Fourier::Equal(double expected, double result, double maximumDelta)
{
    if(expected > std::numeric_limits<double>::min()) { // Test case for values unequal to 0
        return std::fabs(result/expected - 1) <= maximumDelta;
    }

    // Test case for values equal to 0
    return std::fabs(result) <= std::numeric_limits<double>::min();
}