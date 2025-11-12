#include "../include/matrix.hpp"

using namespace matrix;
//1
TEST(MatrixDeterminantTest, ZeroMatrix1x1) 
{
    Matrix<double> m(1, 1, 0.0);
    EXPECT_DOUBLE_EQ(m.determinant(), 0.0);
}
//2
TEST(MatrixDeterminantTest, IdentityMatrix1x1) 
{
    Matrix<double> m(1, 1, 1.0);
    EXPECT_DOUBLE_EQ(m.determinant(), 1.0);
}

//3
TEST(MatrixDeterminantTest, Simple2x2) 
{
    Matrix<double> m(2, 2);
    m.at(0, 0) = 1; m.at(0, 1) = 2;
    m.at(1, 0) = 3; m.at(1, 1) = 4;
    EXPECT_DOUBLE_EQ(m.determinant(), -2.0);
}

//4
TEST(MatrixDeterminantTest, IdentityMatrix2x2) 
{
    Matrix<double> m(2, 2);
    m.at(0, 0) = 1; m.at(0, 1) = 0;
    m.at(1, 0) = 0; m.at(1, 1) = 1;
    EXPECT_DOUBLE_EQ(m.determinant(), 1.0);
}

//5
TEST(MatrixDeterminantTest, ZeroDeterminant2x2) 
{
    Matrix<double> m(2, 2);
    m.at(0, 0) = 1; m.at(0, 1) = 2;
    m.at(1, 0) = 2; m.at(1, 1) = 4;
    EXPECT_DOUBLE_EQ(m.determinant(), 0.0);
}

//6
TEST(MatrixDeterminantTest, Simple3x3) 
{
    Matrix<double> m(3, 3);
    m.at(0, 0) = 1; m.at(0, 1) = 2; m.at(0, 2) = 3;
    m.at(1, 0) = 4; m.at(1, 1) = 5; m.at(1, 2) = 6;
    m.at(2, 0) = 7; m.at(2, 1) = 8; m.at(2, 2) = 10;
    EXPECT_DOUBLE_EQ(m.determinant(), -3.0);
}

//7
TEST(MatrixDeterminantTest, IdentityMatrix3x3) 
{
    Matrix<double> m(3, 3);
    m.at(0, 0) = 1; m.at(0, 1) = 0; m.at(0, 2) = 0;
    m.at(1, 0) = 0; m.at(1, 1) = 1; m.at(1, 2) = 0;
    m.at(2, 0) = 0; m.at(2, 1) = 0; m.at(2, 2) = 1;
    EXPECT_DOUBLE_EQ(m.determinant(), 1.0);
}

//8
TEST(MatrixDeterminantTest, ZeroDeterminant3x3) 
{
    Matrix<double> m(3, 3);
    m.at(0, 0) = 1; m.at(0, 1) = 2; m.at(0, 2) = 3;
    m.at(1, 0) = 4; m.at(1, 1) = 5; m.at(1, 2) = 6;
    m.at(2, 0) = 7; m.at(2, 1) = 8; m.at(2, 2) = 9;
    EXPECT_DOUBLE_EQ(m.determinant(), 0.0);
}

//9
TEST(MatrixDeterminantTest, UpperTriangular3x3) 
{
    Matrix<double> m(3, 3);
    m.at(0, 0) = 2; m.at(0, 1) = 3; m.at(0, 2) = 1;
    m.at(1, 0) = 0; m.at(1, 1) = 4; m.at(1, 2) = 5;
    m.at(2, 0) = 0; m.at(2, 1) = 0; m.at(2, 2) = 6;
    EXPECT_DOUBLE_EQ(m.determinant(), 48.0);
}

//10
TEST(MatrixDeterminantTest, LowerTriangular3x3) 
{
    Matrix<double> m(3, 3);
    m.at(0, 0) = 2; m.at(0, 1) = 0; m.at(0, 2) = 0;
    m.at(1, 0) = 3; m.at(1, 1) = 4; m.at(1, 2) = 0;
    m.at(2, 0) = 1; m.at(2, 1) = 5; m.at(2, 2) = 6;
    EXPECT_DOUBLE_EQ(m.determinant(), 48.0);
}

//11
TEST(MatrixDeterminantTest, DiagonalMatrix3x3) 
{
    Matrix<double> m(3, 3);
    m.at(0, 0) = 2; m.at(0, 1) = 0; m.at(0, 2) = 0;
    m.at(1, 0) = 0; m.at(1, 1) = 3; m.at(1, 2) = 0;
    m.at(2, 0) = 0; m.at(2, 1) = 0; m.at(2, 2) = 4;
    EXPECT_DOUBLE_EQ(m.determinant(), 24.0);
}

//12
TEST(MatrixDeterminantTest, Simple4x4) 
{
    Matrix<double> m(4, 4);
    m.at(0, 0) = 1; m.at(0, 1) = 0; m.at(0, 2) = 2; m.at(0, 3) = -1;
    m.at(1, 0) = 3; m.at(1, 1) = 0; m.at(1, 2) = 0; m.at(1, 3) = 5;
    m.at(2, 0) = 2; m.at(2, 1) = 1; m.at(2, 2) = 4; m.at(2, 3) = -3;
    m.at(3, 0) = 1; m.at(3, 1) = 0; m.at(3, 2) = 5; m.at(3, 3) = 0;
    EXPECT_DOUBLE_EQ(m.determinant(), 30.0);
}

//13
TEST(MatrixDeterminantTest, IdentityMatrix4x4) 
{
    Matrix<double> m(4, 4);
    m.at(0, 0) = 1; m.at(0, 1) = 0; m.at(0, 2) = 0; m.at(0, 3) = 0;
    m.at(1, 0) = 0; m.at(1, 1) = 1; m.at(1, 2) = 0; m.at(1, 3) = 0;
    m.at(2, 0) = 0; m.at(2, 1) = 0; m.at(2, 2) = 1; m.at(2, 3) = 0;
    m.at(3, 0) = 0; m.at(3, 1) = 0; m.at(3, 2) = 0; m.at(3, 3) = 1;
    EXPECT_DOUBLE_EQ(m.determinant(), 1.0);
}

//14
TEST(MatrixDeterminantTest, ZeroDeterminant4x4) 
{
    Matrix<double> m(4, 4);
    m.at(0, 0) = 1; m.at(0, 1) = 2; m.at(0, 2) = 3; m.at(0, 3) = 4;
    m.at(1, 0) = 2; m.at(1, 1) = 4; m.at(1, 2) = 6; m.at(1, 3) = 8;
    m.at(2, 0) = 3; m.at(2, 1) = 6; m.at(2, 2) = 9; m.at(2, 3) = 12;
    m.at(3, 0) = 4; m.at(3, 1) = 8; m.at(3, 2) = 12; m.at(3, 3) = 16;
    EXPECT_DOUBLE_EQ(m.determinant(), 0.0);
}

//15
TEST(MatrixDeterminantTest, UpperTriangular4x4) 
{
    Matrix<double> m(4, 4);
    m.at(0, 0) = 2; m.at(0, 1) = 1; m.at(0, 2) = 3; m.at(0, 3) = 4;
    m.at(1, 0) = 0; m.at(1, 1) = 3; m.at(1, 2) = 2; m.at(1, 3) = 1;
    m.at(2, 0) = 0; m.at(2, 1) = 0; m.at(2, 2) = 4; m.at(2, 3) = 5;
    m.at(3, 0) = 0; m.at(3, 1) = 0; m.at(3, 2) = 0; m.at(3, 3) = 6;
    EXPECT_DOUBLE_EQ(m.determinant(), 144.0);
}

//16
TEST(MatrixDeterminantTest, LowerTriangular4x4) 
{
    Matrix<double> m(4, 4);
    m.at(0, 0) = 2; m.at(0, 1) = 0; m.at(0, 2) = 0; m.at(0, 3) = 0;
    m.at(1, 0) = 1; m.at(1, 1) = 3; m.at(1, 2) = 0; m.at(1, 3) = 0;
    m.at(2, 0) = 4; m.at(2, 1) = 2; m.at(2, 2) = 4; m.at(2, 3) = 0;
    m.at(3, 0) = 3; m.at(3, 1) = 1; m.at(3, 2) = 5; m.at(3, 3) = 6;
    EXPECT_DOUBLE_EQ(m.determinant(), 144.0);
}

//17
TEST(MatrixDeterminantTest, DiagonalMatrix4x4) 
{
    Matrix<double> m(4, 4);
    m.at(0, 0) = 2; m.at(0, 1) = 0; m.at(0, 2) = 0; m.at(0, 3) = 0;
    m.at(1, 0) = 0; m.at(1, 1) = 3; m.at(1, 2) = 0; m.at(1, 3) = 0;
    m.at(2, 0) = 0; m.at(2, 1) = 0; m.at(2, 2) = 4; m.at(2, 3) = 0;
    m.at(3, 0) = 0; m.at(3, 1) = 0; m.at(3, 2) = 0; m.at(3, 3) = 5;
    EXPECT_DOUBLE_EQ(m.determinant(), 120.0);
}

//18
TEST(MatrixDeterminantTest, RowSwap4x4) 
{
    Matrix<double> m(4, 4);
    m.at(0, 0) = 0; m.at(0, 1) = 1; m.at(0, 2) = 0; m.at(0, 3) = 0;
    m.at(1, 0) = 1; m.at(1, 1) = 0; m.at(1, 2) = 0; m.at(1, 3) = 0;
    m.at(2, 0) = 0; m.at(2, 1) = 0; m.at(2, 2) = 1; m.at(2, 3) = 0;
    m.at(3, 0) = 0; m.at(3, 1) = 0; m.at(3, 2) = 0; m.at(3, 3) = 1;
    EXPECT_DOUBLE_EQ(m.determinant(), -1.0);
}

//19
TEST(MatrixDeterminantTest, MultipleRowSwaps4x4) 
{
    Matrix<double> m(4, 4);
    m.at(0, 0) = 0; m.at(0, 1) = 0; m.at(0, 2) = 0; m.at(0, 3) = 1;
    m.at(1, 0) = 0; m.at(1, 1) = 0; m.at(1, 2) = 1; m.at(1, 3) = 0;
    m.at(2, 0) = 0; m.at(2, 1) = 1; m.at(2, 2) = 0; m.at(2, 3) = 0;
    m.at(3, 0) = 1; m.at(3, 1) = 0; m.at(3, 2) = 0; m.at(3, 3) = 0;
    EXPECT_DOUBLE_EQ(m.determinant(), 1.0);
}

//20
TEST(MatrixDeterminantTest, LargeValues5x5) 
{
    Matrix<double> m(5, 5);
    m.at(0, 0) = 10; m.at(0, 1) = 2; m.at(0, 2) = 3; m.at(0, 3) = 4; m.at(0, 4) = 5;
    m.at(1, 0) = 6; m.at(1, 1) = 20; m.at(1, 2) = 8; m.at(1, 3) = 9; m.at(1, 4) = 10;
    m.at(2, 0) = 11; m.at(2, 1) = 12; m.at(2, 2) = 30; m.at(2, 3) = 14; m.at(2, 4) = 15;
    m.at(3, 0) = 16; m.at(3, 1) = 17; m.at(3, 2) = 18; m.at(3, 3) = 40; m.at(3, 4) = 20;
    m.at(4, 0) = 21; m.at(4, 1) = 22; m.at(4, 2) = 23; m.at(4, 3) = 24; m.at(4, 4) = 50;
    EXPECT_NEAR(m.determinant(), 3390600.0, 1e-6);
}

//21
TEST(MatrixDeterminantTest, SmallValues3x3) 
{
    Matrix<double> m(3, 3);
    m.at(0, 0) = 0.1; m.at(0, 1) = 0.2; m.at(0, 2) = 0.3;
    m.at(1, 0) = 0.4; m.at(1, 1) = 0.5; m.at(1, 2) = 0.6;
    m.at(2, 0) = 0.7; m.at(2, 1) = 0.8; m.at(2, 2) = 0.9;
    EXPECT_NEAR(m.determinant(), 0.0, 1e-10);
}

//22
TEST(MatrixDeterminantTest, NegativeValues3x3) 
{
    Matrix<double> m(3, 3);
    m.at(0, 0) = -1; m.at(0, 1) = -2; m.at(0, 2) = -3;
    m.at(1, 0) = -4; m.at(1, 1) = -5; m.at(1, 2) = -6;
    m.at(2, 0) = -7; m.at(2, 1) = -8; m.at(2, 2) = -9;
    EXPECT_DOUBLE_EQ(m.determinant(), 0.0);
}

//23
TEST(MatrixDeterminantTest, MixedSigns3x3) 
{
    Matrix<double> m(3, 3);
    m.at(0, 0) = 1; m.at(0, 1) = -2; m.at(0, 2) = 3;
    m.at(1, 0) = -4; m.at(1, 1) = 5; m.at(1, 2) = -6;
    m.at(2, 0) = 7; m.at(2, 1) = -8; m.at(2, 2) = 9;
    EXPECT_DOUBLE_EQ(m.determinant(), 0.0);
}

//24
TEST(MatrixDeterminantTest, FractionalValues2x2) 
{
    Matrix<double> m(2, 2);
    m.at(0, 0) = 1.5; m.at(0, 1) = 2.5;
    m.at(1, 0) = 3.5; m.at(1, 1) = 4.5;
    EXPECT_DOUBLE_EQ(m.determinant(), 1.5 * 4.5 - 2.5 * 3.5);
}

//25
TEST(MatrixDeterminantTest, IntegerOverflowProtection) 
{
    long double det = 1000000.0 * 4000000.0 - 2000000.0 * 3000000.0;
    Matrix<long double> m(2, 2);
    m.at(0, 0) = 1000000LL; m.at(0, 1) = 2000000LL;
    m.at(1, 0) = 3000000LL; m.at(1, 1) = 4000000LL;
    EXPECT_NEAR(m.determinant(), det, 1e-6);
}

//26
TEST(MatrixDeterminantTest, ZeroPivotHandling) 
{
    Matrix<double> m(3, 3);
    m.at(0, 0) = 0; m.at(0, 1) = 1; m.at(0, 2) = 2;
    m.at(1, 0) = 3; m.at(1, 1) = 4; m.at(1, 2) = 5;
    m.at(2, 0) = 6; m.at(2, 1) = 7; m.at(2, 2) = 8;
    EXPECT_NEAR(m.determinant(), 0.0, 1e-10);
}

//27
TEST(MatrixDeterminantTest, NearZeroPivot) 
{
    Matrix<double> m(3, 3);
    m.at(0, 0) = 1e-15; m.at(0, 1) = 2; m.at(0, 2) = 3;
    m.at(1, 0) = 4; m.at(1, 1) = 5; m.at(1, 2) = 6;
    m.at(2, 0) = 7; m.at(2, 1) = 8; m.at(2, 2) = 9;
    EXPECT_NEAR(m.determinant(), 3.0, 1e-12);
}

//28
TEST(MatrixDeterminantTest, RandomMatrix4x4) 
{
    Matrix<double> m(4, 4);
    m.at(0, 0) = 2; m.at(0, 1) = 1; m.at(0, 2) = 3; m.at(0, 3) = 4;
    m.at(1, 0) = 1; m.at(1, 1) = 3; m.at(1, 2) = 2; m.at(1, 3) = 1;
    m.at(2, 0) = 4; m.at(2, 1) = 2; m.at(2, 2) = 1; m.at(2, 3) = 3;
    m.at(3, 0) = 3; m.at(3, 1) = 4; m.at(3, 2) = 2; m.at(3, 3) = 1;
    EXPECT_EQ(m.determinant(), 25);
}

//29
TEST(MatrixDeterminantTest, SymmetricMatrix3x3) 
{
    Matrix<double> m(3, 3);
    m.at(0, 0) = 2; m.at(0, 1) = 1; m.at(0, 2) = 1;
    m.at(1, 0) = 1; m.at(1, 1) = 2; m.at(1, 2) = 1;
    m.at(2, 0) = 1; m.at(2, 1) = 1; m.at(2, 2) = 2;
    EXPECT_DOUBLE_EQ(m.determinant(), 4.0);
}

//30
TEST(MatrixDeterminantTest, AntiSymmetricMatrix3x3) 
{
    Matrix<double> m(3, 3);
    m.at(0, 0) = 0; m.at(0, 1) = 1; m.at(0, 2) = 2;
    m.at(1, 0) = -1; m.at(1, 1) = 0; m.at(1, 2) = 3;
    m.at(2, 0) = -2; m.at(2, 1) = -3; m.at(2, 2) = 0;
    EXPECT_DOUBLE_EQ(m.determinant(), 0.0);
}

//31
TEST(MatrixDeterminantTest, HilbertMatrix3x3) 
{
    Matrix<double> m(3, 3);
    m.at(0, 0) = 1.0/1; m.at(0, 1) = 1.0/2; m.at(0, 2) = 1.0/3;
    m.at(1, 0) = 1.0/2; m.at(1, 1) = 1.0/3; m.at(1, 2) = 1.0/4;
    m.at(2, 0) = 1.0/3; m.at(2, 1) = 1.0/4; m.at(2, 2) = 1.0/5;
    EXPECT_NEAR(m.determinant(), 1.0/2160, 1e-10);
}

//32
TEST(MatrixDeterminantTest, AllOnesMatrix3x3) 
{
    Matrix<double> m(3, 3, 1.0);
    EXPECT_DOUBLE_EQ(m.determinant(), 0.0);
}

//33
TEST(MatrixDeterminantTest, ScalarMultiplicationProperty) 
{
    Matrix<double> m(3, 3);
    m.at(0, 0) = 1; m.at(0, 1) = 2; m.at(0, 2) = 3;
    m.at(1, 0) = 4; m.at(1, 1) = 5; m.at(1, 2) = 6;
    m.at(2, 0) = 7; m.at(2, 1) = 8; m.at(2, 2) = 10;
    
    Matrix<double> m2 = m;
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            m2.at(i, j) = 2 * m.at(i, j);
        }
    }
    
    EXPECT_NEAR(m2.determinant(), 8 * m.determinant(), 1e-10);
}

//34
TEST(MatrixDeterminantTest, NonSquareMatrixThrows) 
{
    Matrix<double> m(2, 3);
    EXPECT_THROW(m.determinant(), std::invalid_argument);
}

//35
TEST(MatrixDeterminantTest, EmptyMatrixThrows) 
{
    Matrix<double> m(0, 0);
    EXPECT_THROW(m.determinant(), std::invalid_argument);
}

//36
TEST(MatrixDeterminantTest, SingleElementLargeValue) 
{
    Matrix<double> m(1, 1);
    m.at(0, 0) = 1e308;
    EXPECT_DOUBLE_EQ(m.determinant(), 1e308);
}

//37
TEST(MatrixDeterminantTest, PrecisionTest6x6) 
{
    Matrix<double> m(6, 6);
    for (size_t i = 0; i < 6; ++i) 
    {
        for (size_t j = 0; j < 6; ++j) 
        {
            m.at(i, j) = 1.0 / (i + j + 1.0);
        }
    }
    EXPECT_NEAR(m.determinant(), 5.3673e-18, 1e-22);
}

//38
TEST(MatrixDeterminantTest, IntegerMatrix5x5) 
{
    Matrix<int> m(5, 5);
    m.at(0, 0) = 1; m.at(0, 1) = 0; m.at(0, 2) = 0; m.at(0, 3) = 0; m.at(0, 4) = 0;
    m.at(1, 0) = 0; m.at(1, 1) = 2; m.at(1, 2) = 0; m.at(1, 3) = 0; m.at(1, 4) = 0;
    m.at(2, 0) = 0; m.at(2, 1) = 0; m.at(2, 2) = 3; m.at(2, 3) = 0; m.at(2, 4) = 0;
    m.at(3, 0) = 0; m.at(3, 1) = 0; m.at(3, 2) = 0; m.at(3, 3) = 4; m.at(3, 4) = 0;
    m.at(4, 0) = 0; m.at(4, 1) = 0; m.at(4, 2) = 0; m.at(4, 3) = 0; m.at(4, 4) = 5;
    EXPECT_EQ(m.determinant(), 120);
}

//39
TEST(MatrixDeterminantTest, FloatType) 
{
    Matrix<float> m(2, 2);
    m.at(0, 0) = 1.5f; m.at(0, 1) = 2.5f;
    m.at(1, 0) = 3.5f; m.at(1, 1) = 4.5f;
    EXPECT_FLOAT_EQ(m.determinant(), 1.5f * 4.5f - 2.5f * 3.5f);
}

int main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}