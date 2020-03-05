#ifndef FOURIER_H
#define FOURIER_H

#include <vector>

struct FourierCoefficients {
    struct FourierCoefficient {
        int order{0};
        double a{0};
        double b{0};
    };

    std::vector<FourierCoefficient> coefficients;
};

#endif