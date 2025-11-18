#ifndef MATRIX_H__
#define MATRIX_H__
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <span>
#include <type_traits>
#include <gtest/gtest.h>

namespace matrix
{
    template <typename type>
    class Matrix
    {
        
    private:
        size_t rows, cols;
        type** data;

        void allocateMemory() 
        {
            static_assert(std::is_default_constructible<type>::value, 
                          "Matrix type must be default-constructible");
            data = new type*[rows];
            for (size_t i = 0; i < rows; ++i) 
            {
                data[i] = new type[cols]{};
            }
        }

        void clearMemory() 
        {
            if (data != nullptr) 
            {
                for (size_t i = 0; i < rows; ++i) 
                {
                    delete[] data[i];
                }
                delete[] data;
                data = nullptr;
            }
        }

        // swap
        void swap(Matrix& other) noexcept
        {
            using std::swap;
            swap(rows, other.rows);
            swap(cols, other.cols);
            swap(data, other.data);
        }

    public:
        // default constructor
        Matrix(): rows(0), cols(0), data(nullptr) {}

        // constructor without flat_array
        Matrix(size_t rows, size_t cols): rows(rows), cols(cols), data(nullptr) 
        {
            if (rows > 0 && cols > 0) 
            {
                allocateMemory();
            }
        }
        
        // constructor with flat_array
        Matrix(size_t rows, size_t cols, std::span<const type> flat_array): rows(rows), cols(cols), data(nullptr) 
        {
            if (rows > 0 && cols > 0) 
            {
                
                size_t required_elements = rows * cols;
                if (flat_array.size() != required_elements) 
                {
                    throw std::invalid_argument("Flat array wrong size");
                }
                
                allocateMemory();
                
                for (size_t i = 0; i < rows; ++i) 
                {
                    for (size_t j = 0; j < cols; ++j) 
                    {
                        data[i][j] = flat_array[i * cols + j];
                    }
                }
            }
        }

        // constructor with std::initializer_list
        Matrix(std::initializer_list<std::initializer_list<type>> init_list) : 
            rows(init_list.size()), cols(0), data(nullptr) 
        {
            if (rows == 0) 
            {
                return; 
            }

            auto first_row = init_list.begin();
            cols = first_row->size();
            
            for (const auto& row : init_list) 
            {
                if (row.size() != cols) 
                {
                    throw std::invalid_argument("All rows must have the same number of columns");
                }
            }

            allocateMemory();
            
            size_t i = 0;
            for (const auto& row_list : init_list) 
            {
                size_t j = 0;
                for (const auto& element : row_list) 
                {
                    data[i][j] = element;
                    ++j;
                }
                ++i;
            }
        }


        // constructor with iterator
        template <typename InputIt>
        Matrix(size_t rows, size_t cols, InputIt first, InputIt last): rows(rows), cols(cols), data(nullptr)
        {
            size_t total_elements = std::distance(first, last);
            if (rows * cols != total_elements)
            {
                throw std::invalid_argument("Flat array wrong size");
            }
            allocateMemory();
            auto it = first;
            for (size_t i = 0; i < rows; ++i) 
            {
                for (size_t j = 0; j < cols; ++j) 
                {
                    if (it != last) 
                    {
                        data[i][j] = *it++;
                    }
                }
            }
        }

        // same-value constructor
        Matrix(size_t rows, size_t cols, const type& value): rows(rows), cols(cols), data(nullptr) 
        {
            if (rows > 0 && cols > 0) 
            {
                allocateMemory();
                for (size_t i = 0; i < rows; ++i) 
                {
                    for (size_t j = 0; j < cols; ++j) 
                    {
                        data[i][j] = value;
                    }
                }
            }
        }

        // copy constructor
        Matrix(const Matrix& other) : rows(0), cols(0), data(nullptr) 
        {
            if (other.data != nullptr) 
            {
                type** new_data = nullptr;
                try 
                {
                    new_data = new type*[other.rows];
                    for (size_t i = 0; i < other.rows; ++i) 
                    {
                        new_data[i] = new type[other.cols];
                    }
                    
                    for (size_t i = 0; i < other.rows; ++i) 
                    {
                        for (size_t j = 0; j < other.cols; ++j) 
                        {
                            new_data[i][j] = other.data[i][j];
                        }
                    }
                    
                    rows = other.rows;
                    cols = other.cols;
                    data = new_data;
                } 
                catch (...) 
                {
                    if (new_data != nullptr) 
                    {
                        for (size_t i = 0; i < other.rows; ++i) 
                        {
                            delete[] new_data[i];
                        }
                        delete[] new_data;
                    }
                    throw; 
                }
            }
        }

        // copy assignment
        Matrix& operator=(Matrix other) 
        {
            swap(other);
            return *this;
        }    

        // move constructor
        Matrix(Matrix&& other) noexcept : Matrix() 
        {
            swap(other);
        }   

        // move assignment
        Matrix& operator=(Matrix&& other) noexcept 
        {
            if (this != &other) 
            {
                swap(other);
            }
            return *this;
        }

        // destructor
        ~Matrix() 
        {
            clearMemory();
        }

        // Methods for accessing elements and dimensions
        type& at(size_t row, size_t col) 
        {
            if (row >= rows || col >= cols) 
            {
                throw std::out_of_range("Matrix indices out of range");
            }
            return data[row][col];
        }

        const type& at(size_t row, size_t col) const 
        {
            if (row >= rows || col >= cols) 
            {
                throw std::out_of_range("Matrix indices out of range");
            }
            return data[row][col];
        }

        size_t getRows() const { return rows; }
        size_t getCols() const { return cols; }

        // Method to print matrix 
        void print() const 
        {
            for (size_t i = 0; i < rows; ++i) 
            {
                for (size_t j = 0; j < cols; ++j) 
                {
                    std::cout << data[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }

        // Method to calculate determinant
        type determinant() const 
        {
            if (rows != cols || rows == 0) 
            {
                throw std::invalid_argument("Matrix must be square for determinant calculation");
            }
            
            Matrix<type> temp(*this);
            type det = 1;
            const type epsilon = static_cast<type>(1e-10); 

            for (size_t i = 0; i < rows; ++i) 
            {
                size_t pivot = i;
                for (size_t j = i + 1; j < rows; ++j) 
                {
                    if (std::abs(temp.data[j][i]) > std::abs(temp.data[pivot][i])) 
                    {
                        pivot = j;
                    }
                }

                if (std::abs(temp.data[pivot][i]) < epsilon) 
                {
                    return static_cast<type>(0);
                }

                if (pivot != i) 
                {
                    std::swap(temp.data[i], temp.data[pivot]);
                    det = -det; 
                }

                det *= temp.data[i][i];

                for (size_t j = i + 1; j < rows; ++j) 
                {
                    type factor = temp.data[j][i] / temp.data[i][i];
                    for (size_t k = i + 1; k < cols; ++k) 
                    {
                        temp.data[j][k] -= factor * temp.data[i][k];
                    }
                }
            }

            return det;
        }

        // Public swap method for external use
        friend void swap(Matrix& first, Matrix& second) noexcept
        {
            first.swap(second);
        }
    };
}

#endif