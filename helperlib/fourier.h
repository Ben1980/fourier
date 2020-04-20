#ifndef FOURIER_H
#define FOURIER_H

#include <vector>

/**
 * @brief The Fourier namespace is providing data structures to handle input and resulting coefficients of a fourier transformation
 */
namespace Fourier {
    enum class Error {
        NONE,
        NO_VALUES,
        INVALID_DATASET
    };

    /**
     * @brief The input data to perform a fourier transformation
     */
    struct InputData {
        //!< The actual data as x/y dataset
        std::vector<std::pair<double, double>> data;

        //!< The posible error state of the dataset
        Error error{Error::NONE};

        /**
         * @brief Checks if a dataset is good
         * 
         * @return true In case the data is good
         * @return false In case the data is bad
         */
        operator bool() const { 
            return !data.empty() && error == Error::NONE; 
        } 

        std::vector<std::pair<double, double>> & operator()() { return data; }
        const std::vector<std::pair<double, double>> & operator()() const { return data; }
    };

    /**
     * @brief The resulting coefficients of a fourier transformation
     */
    struct Coefficients {
        /**
         * @brief The actual coefficient data point
         */
        struct Coefficient {
            //!< The order of the coefficient
            int order{0};
            //!< The a value of the coefficient
            double a{0};
            //!< The b value of the coefficient
            double b{0};
        };

        //!< The actual coefficients derived by a fourier transformation
        std::vector<Coefficient> coefficients;

        //!< The posible error state of the dataset
        Error error{Error::NONE};
        
        /**
         * @brief Checks if a dataset is good
         * 
         * @return true In case the data is good
         * @return false In case the data is bad
         */
        operator bool() const { 
            return !coefficients.empty() && error == Error::NONE;
        }

        std::vector<Coefficient> & operator()() { return coefficients; }
        const std::vector<Coefficient> & operator()() const { return coefficients; }
    };

    /**
     * @brief Compares two coefficient lists of the same size
     * 
     * @param expected 
     * @param result 
     * @return true In case of both coefficient lists are equal
     * @return false In case of both coefficient lists are unequal
     */
    bool Equal(const Coefficients& expected, const Coefficients& result);

    /**
     * @brief Compares two given values
     * 
     * @param expected 
     * @param result 
     * @param maximumDelta The maximum allowed difference between expected and result
     * @return true In case of both values are equal
     * @return false In case of both values are unequal
     */
    bool Equal(double expected, double result, double maximumDelta = 1e-15);
};

#endif