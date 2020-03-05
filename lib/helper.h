#ifndef HELPER_H
#define HELPER_H

#include <vector>
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>

namespace TestDataHelper 
{
    struct Data {
        std::vector<std::pair<double, double>> data;
        enum class Error {
            NONE,
            NO_VALUES,
            INVALID_DATASET
        } error{Error::NONE};

        Data() = default;
        Data(const std::vector<std::pair<double, double>>& input, Error e) : data(input), error(e) {}
        operator bool() const { return error == Error::NONE; } 
        std::vector<std::pair<double, double>> & operator()() { return data; }
    };

    Data ParseDataFile(const std::string &inputData)
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

                const double x = atof(values.front().c_str());
                const double y = atof(values.back().c_str());
                data().push_back({x, y});
            }
        }

        return data;
    }
};

#endif