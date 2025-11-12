#include "../include/matrix.hpp"


int main() {
    int n;
    std::cin >> n;
    
    // Create matrix with given size
    matrix::Matrix<double> mat(n, n);
    
    // Read matrix elements
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> mat.at(i, j);
        }
    }
    
    // Calculate and output determinant

    double det = mat.determinant();
    std::cout << det << std::endl;
    
    return 0;
}