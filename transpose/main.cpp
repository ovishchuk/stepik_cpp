#include <iostream>

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** transM = new int * [cols];
    transM[0] = new int [cols * rows];
    for (size_t indexi = 1; indexi != cols; ++indexi)
    {
        transM[indexi] = transM[indexi - 1] + rows;
    }
    for (size_t indexrow = 0; indexrow < cols; ++indexrow)
    {
        for (size_t indexcol = 0; indexcol < rows; ++indexcol)
        {
            transM[indexrow][indexcol] = m[indexcol][indexrow];
        }
    }
    return transM;
}

int main(void)
{
    int rows = 4;
    int cols = 5;
    int ** baseArray = new int * [rows];
    int ** workArray = 0;
    baseArray[0] = new int [rows * cols];
    for (size_t index = 1; index != rows; ++index)
    {
        baseArray[index] = baseArray[index - 1] + cols;
    }
    baseArray[0][0] = 7;
    baseArray[0][1] = 2;
    baseArray[0][2] = 8;
    baseArray[1][0] = 3;
    baseArray[1][1] = 0;
    baseArray[1][2] = 4;
    baseArray[1][3] = 9;
    baseArray[1][4] = 5;
    baseArray[2][0] = 1;
    baseArray[2][1] = 7;
    baseArray[2][2] = 2;
    baseArray[2][3] = 6;
    baseArray[3][0] = 4;
    workArray = transpose(baseArray, rows, cols);
    delete [] baseArray[0];
    delete [] baseArray;
    std::cout << '\n';
    for (size_t i = 0; i < cols; ++i)
    {
        for (size_t j = 0; j < rows; ++j)
        {
            std::cout << workArray[i][j] << " ";
        }
        std::cout << '\n';
    }
    return 0;
}
