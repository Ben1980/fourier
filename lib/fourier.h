#ifndef FOURIER_H
#define FOURIER_H

#include <vector>

namespace Fourier {
    enum class Error {
        NONE,
        NO_VALUES,
        INVALID_DATASET
    };

    struct InputData {
        std::vector<std::pair<double, double>> data;
        Error error{Error::NONE};

        operator bool() const { 
            return !data.empty() && error == Error::NONE; 
        } 
        std::vector<std::pair<double, double>> & operator()() { return data; }
        const std::vector<std::pair<double, double>> & operator()() const { return data; }
    };

    struct Coefficients {
        struct Coefficient {
            int order{0};
            double a{0};
            double b{0};
        };

        std::vector<Coefficient> coefficients;
        Error error{Error::NONE};
        
        operator bool() const { 
            return !coefficients.empty() && error == Error::NONE;
        }
        std::vector<Coefficient> & operator()() { return coefficients; }
        const std::vector<Coefficient> & operator()() const { return coefficients; }
    };

    bool Equal(const Coefficients& expected, const Coefficients& result);
    bool Equal(double a, double b, double maximumDelta = 1e-15);
};

#endif