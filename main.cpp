#include "../include/matrix.hpp"

int main() 
{
    int n;
    std::cin >> n;
    if (!std::cin || n < 0) 
    {
        std::cerr << "Error: Invalid matrix size. Expected non-negative integer." << std::endl;
        return 1;
    }
    
    matrix::Matrix<double> mat(n, n);
        for (size_t i = 0; i < n; ++i) 
    {
        for (size_t j = 0; j < n; ++j) 
        {
            std::cin >> mat.at(i, j);
            if (!std::cin) 
            {
                std::cerr << "Error: Invalid input for matrix element at position (" 
                          << i << ", " << j << "). Expected a number." << std::endl;
                return 1;
            }
        }
    }
    
    if (!std::cin) 
    {
        std::cerr << "Error: Failed to read matrix elements." << std::endl;
        return 1;
    }

    try 
    {
        double det = mat.determinant();
        std::cout << det << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cerr << "Error calculating determinant: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}