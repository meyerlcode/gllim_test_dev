#include "./computeDeterminant.hpp"
#include <armadillo>
#include<math.h>       // used for pow() function. pow() function is used to calculate some power of a number

extern "C" // This code will be read as C type. This is mandatory for ctypes to work
{
// Helpers::Helpers() {}

// // Full version
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

// // Full version without pointer without class
// double computeDeterminant(const arma::mat& matrix){
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

// fake function with Helpers class
// double Helpers::computeDeterminant(const double& matrix){
//     return matrix*2;
// }

// // fake function without class without pointers
// double computeDeterminant(const double matrix){
//     printf("matrix = %.1f\n",matrix);
//     return matrix*2;
// }

// // Det function without armadillo without class without pointers
// double computeDeterminant(const double matrix[3][3]){
//     printf("matrix =\n%.1f %.1f %.1f\n%.1f %.1f %.1f\n%.1f %.1f %.1f\n",
//         matrix[0][0], matrix[0][1], matrix[0][2], matrix[1][0], matrix[1][1], matrix[1][2], matrix[2][0], matrix[2][1], matrix[2][2]);
//     return matrix[0][0]*matrix[1][1]*matrix[2][2];
// }


// recursive determinant
double computeDeterminant(double matrix[10][10], int n){
    double det = 0;
    double submatrix[10][10];
    if (n == 2)
    return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    else {
        for (int x = 0; x < n; x++) {
         int subi = 0;
         for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
               if (j == x)
               continue;
               submatrix[subi][subj] = matrix[i][j];
               subj++;
            }
            subi++;
         }
         det = det + (pow(-1, x) * matrix[0][x] * computeDeterminant( submatrix, n - 1 ));
      }
   }
   return det;
}



}