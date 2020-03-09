#ifndef FOURIER_H
#define FOURIER_H

#include <vector>

enum class Error {
    NONE,
    NO_VALUES,
    INVALID_DATASET
};

struct InputData {
    std::vector<std::pair<double, double>> data;
    Error error{Error::NONE};

    operator bool() const { return error == Error::NONE; } 
    std::vector<std::pair<double, double>> & operator()() { return data; }
};

struct FourierCoefficients {
    struct FourierCoefficient {
        int order{0};
        double a{0};
        double b{0};
    };

    std::vector<FourierCoefficient> coefficients;
    Error error{Error::NONE};
    

    operator bool() const { return error == Error::NONE; }
    std::vector<FourierCoefficient> & operator()() { return coefficients; }
};

#endif