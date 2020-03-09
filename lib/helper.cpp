#include "helper.h"
#include "fourier.h"

FourierHelper::Data FourierHelper::ParseDataFile(const std::string& inputData)
{
    std::fstream input(inputData, std::ifstream::in);

    Data data;
    if(input.is_open() && input.good()) {
        std::string line;
        while(std::getline(input, line)) {
            std::vector<std::string> values;
            boost::split(values, line, [](char c) { return c == ';'; });

            if(values.empty()) {
                return {{}, Data::Error::NO_VALUES};
            }
            if(values.size() < 2 || values.size() > 2) {
                return {{}, Data::Error::INVALID_DATASET};
            }

            const double x = std::stod(values.front());
            const double y = std::stod(values.back());
            data().push_back({x, y});
        }
    }

    return data;
}

bool FourierHelper::Equal(const FourierHelper::Data& expected, const FourierCoefficients& results)
{
    return false;
}