#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>

struct FourierCoefficients;

namespace FourierHelper 
{
    struct Data {
        std::vector<std::pair<double, double>> data;
        enum class Error {
            NONE,
            NO_VALUES,
            INVALID_DATASET
        } error{Error::NONE};

        operator bool() const { return error == Error::NONE; } 
        std::vector<std::pair<double, double>> & operator()() { return data; }
    };

    Data ParseDataFile(const std::string& inputData);

    bool Equal(const Data& expected, const FourierCoefficients& results);
};

#endif