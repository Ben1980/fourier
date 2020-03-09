#ifndef HELPER_H
#define HELPER_H

#include <string>

namespace Fourier {
    struct InputData;
    struct Coefficients;
};

namespace FourierHelper 
{
    Fourier::InputData ParseInputDataFile(const std::string& inputData);
    Fourier::Coefficients ParseOutputDataFile(const std::string& coefficients);
};

#endif