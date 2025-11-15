#include "../include/matrix.hpp"


int main() 
{
    int n;
    std::cin >> n;
    
    matrix::Matrix<double> mat(n, n);
    
    for (size_t i = 0; i < n; ++i) 
    {
        for (size_t j = 0; j < n; ++j) 
        {
            std::cin >> mat.at(i, j);
        }
    }
    

    double det = mat.determinant();
    std::cout << det << std::endl;
    
    return 0;
}