#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>

struct InputData;
struct FourierCoefficients;

namespace FourierHelper 
{
    InputData ParseInputDataFile(const std::string& inputData);
    FourierCoefficients ParseOutputDataFile(const std::string& coefficients);

    bool Equal(const FourierCoefficients& expected, const FourierCoefficients& results);
};

#endif