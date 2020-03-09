#include "helper.h"
#include "fourier.h"

InputData FourierHelper::ParseInputDataFile(const std::string& inputData)
{
    std::fstream input(inputData, std::ifstream::in);

    InputData data;
    if(input.is_open() && input.good()) {
        std::string line;
        while(std::getline(input, line)) {
            std::vector<std::string> values;
            boost::split(values, line, [](char c) { return c == ';'; });

            if(values.empty()) {
                return {{}, Error::NO_VALUES};
            }
            if(values.size() < 2 || values.size() > 2) {
                return {{}, Error::INVALID_DATASET};
            }

            const double x = std::stod(values.front());
            const double y = std::stod(values.back());
            data().push_back({x, y});
        }
    }

    return data;
}

FourierCoefficients FourierHelper::ParseOutputDataFile(const std::string& coefficients)
{
    std::fstream input(coefficients, std::ifstream::in);

    FourierCoefficients data;
    if(input.is_open() && input.good()) {
        std::string line;
        while(std::getline(input, line)) {
            std::vector<std::string> values;
            boost::split(values, line, [](char c) { return c == ';'; });

            if(values.empty()) {
                return {{}, Error::NO_VALUES};
            }
            if(values.size() < 3 || values.size() > 3) {
                return {{}, Error::INVALID_DATASET};
            }

            const int x = std::stoi(values.front());
            const double y = std::stod(values[1]);
            const double z = std::stod(values.back());
            data().push_back({x, y, z});
        }
    }

    return data;
}

bool FourierHelper::Equal(const FourierCoefficients& expected, const FourierCoefficients& results)
{
    

    bool equal = false;

    return equal;
}