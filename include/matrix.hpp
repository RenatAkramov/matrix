#ifndef MATRIX_H__
#define MATRIX_H__
#include <iostream>
#include <stdexcept>
#include <cmath>
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
        Matrix(size_t rows, size_t cols, const type* flat_array): rows(rows), cols(cols), data(nullptr) 
        {
            if (rows > 0 && cols > 0) 
            {
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
        Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(nullptr) 
        {
            if (other.data != nullptr) 
            {
                allocateMemory();
                for (size_t i = 0; i < rows; ++i) 
                {
                    for (size_t j = 0; j < cols; ++j) 
                    {
                        data[i][j] = other.data[i][j];
                    }
                }
            }
        }

        // copy assignment
        Matrix& operator=(const Matrix& other) 
        {
            if (this != &other) 
            {
                clearMemory();
                rows = other.rows;
                cols = other.cols;
                if (other.data != nullptr) 
                {
                    allocateMemory();
                    for (size_t i = 0; i < rows; ++i) 
                    {
                        for (size_t j = 0; j < cols; ++j) 
                        {
                            data[i][j] = other.data[i][j];
                        }
                    }
                }
            }
            return *this;
        }    

        // move constructor
        Matrix(Matrix&& other) noexcept: rows(other.rows), cols(other.cols), data(other.data) 
        {
            other.rows = 0;
            other.cols = 0;
            other.data = nullptr;
        }    

        // move assignment
        Matrix& operator=(Matrix&& other) noexcept 
        {
            if (this != &other) 
            {
                clearMemory();
                rows = other.rows;
                cols = other.cols;
                data = other.data;
                other.rows = 0;
                other.cols = 0;
                other.data = nullptr;               
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
    };
}

#endif