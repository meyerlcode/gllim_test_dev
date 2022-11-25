#include "./computeDeterminant.hpp"
#include "math.h"


double Helpers::computeDetermiant(const arma::mat& matrix){
    if (matrix.n_rows <=3){
        return det(matrix);
    }else{
        if (chol(R,matrix)){
            return 2*sum(log(R.diag()));
        }else{
            return det(matrix);
        }
    }
}