#ifndef COMPUTE_DETERMINANT_H
#define COMPUTE_DETERMINANT_H
#include <armadillo>

extern "C" // This code will be read as C type. This is mandatory for ctypes to work
{
// class Helpers
// {
//     public:
//     // double computeDeterminant(const arma::mat& matrix);
//     double computeDeterminant(const double& matrix);
// };

// // Full version without pointer without class
// double computeDeterminant(const arma::mat& matrix);


// // fake function without class without pointers
// double computeDeterminant(const double matrix);

// // Det function without armadillo without class without pointers
// double computeDeterminant(const double matrix[3][3]);

// recursive determinant
double computeDeterminant(double matrix[10][10], int n);

}
#endif