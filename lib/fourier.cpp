#include "fourier.h"

bool Fourier::Equal(const Fourier::Coefficients& expected, const Fourier::Coefficients& results)
{
    if(!expected || !results) return false;
    if(expected().size() != results().size()) return false;

    bool equal = false;

    return equal;
}