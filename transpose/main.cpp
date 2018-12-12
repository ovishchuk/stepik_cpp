#include <iostream>

int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int ** transM = new int * [rows];
    transM[0] = new int [rows * cols];
    for (int index = 1; index != rows; ++index)
    {
        transM[index] = transM[index - 1] + cols;
    }
    return transM;
}

int main(void)
{
    return 0;
}
