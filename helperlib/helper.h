#ifndef HELPER_H
#define HELPER_H

#include <string>

namespace Fourier {
    struct InputData;
    struct Coefficients;
};

namespace FourierHelper 
{
    /**
     * @brief Transforms input data of the form x;y into Fourier:InputData datastruct
     * 
     * The input data contains x;y (cartesian coordinates) data points seperated by a linebreak
     * 
     * @param inputData
     * @return Fourier::InputData
     */
    Fourier::InputData ParseInputDataFile(const std::string& inputData);

    /**
     * @brief Transforms coefficients of the form i;x;y into Fourier:Coefficients datastruct
     * 
     * The input data contains i:x;y data points seperated by a linebreak
     * i = datapoint
     * x = order
     * y = amplitude
     * 
     * @param coefficients
     * @return Fourier::Coefficients
     */
    Fourier::Coefficients ParseOutputDataFile(const std::string& coefficients);
};

#endif