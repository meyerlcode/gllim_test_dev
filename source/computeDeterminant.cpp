#include "./computeDeterminant.hpp"
#include <armadillo>

// Helpers::Helpers() {}

// double Helpers::computeDeterminant(const arma::mat& matrix){
//     if (matrix.n_rows <=3){
//         return det(matrix);
//     }else{
//         arma::mat R;
//         if (chol(R,matrix)){
//             return 2*arma::sum(log(R.diag())); // return log det ?
//         }else{
//             return det(matrix);
//         }
//     }
// }

double Helpers::computeDeterminant(const double& matrix){
    return matrix*2;
}