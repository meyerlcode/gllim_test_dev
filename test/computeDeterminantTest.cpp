#include "../source/computeDeterminant.hpp"
#include "../source/computeDeterminant.cpp"
#include <armadillo>
#include <iostream>

int main(int argc, const char **argv) {

    // // armadillo library
    // arma::mat A(3, 3);
    // A.ones(3,3);
    // std::cout << "A:\n" << A << "\n" << std::endl;
    // double detA;
    // detA = computeDeterminant(A);

    // Helpers H; // create helpers class
    // double A2(3.5);
    // detA = H.computeDeterminant(A2);

    // det function without armadillo without class without pointers
    double A[10][10] = { {1,1,1},
                        {1,2,3},
                        {0,1,0}};
    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 10; j++) {
    //         A[i][j] = 2;
    //     }
    // }
    double detA;
    detA = computeDeterminant(A, 3);

    std::cout << "det(A) = " << detA << "\n" << std::endl;




    // Initialize the random generator
    // arma::arma_rng::set_seed_random();

    // Create a 4x4 random matrix and print it on the screen
    // arma::Mat<double> A = arma::randu(4,4);
    // std::cout << "A:\n" << A << "\n" << std::endl;

    // // Multiply A with his transpose:
    // std::cout << "A * A.t() =\n";
    // std::cout << A * A.t() << "\n";

    // // Access/Modify rows and columns from the array:
    // A.row(0) = A.row(1) + A.row(3);
    // A.col(3).zeros();
    // std::cout << "add rows 1 and 3, store result in row 0, also fill 4th column with zeros:\n";
    // std::cout << "A:\n" << A << "\n";

    // // Create a new diagonal matrix using the main diagonal of A:
    // arma::Mat<double>B = arma::diagmat(A);
    // std::cout << "B:\n" << B << "\n";

    // // Save matrices A and B:
    // // A.save("A_mat.txt", arma::arma_ascii);
    // // B.save("B_mat.txt", arma::arma_ascii);

    return 0;
}