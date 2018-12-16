/* Реализуйте функцию swap_min, которая принимает на вход двумерный массив целых
 * чисел, ищет в этом массиве строку, содержащую наименьшее среди всех элементов
 * массива значение, и меняет эту строку местами с первой строкой массива.
 * 
 * Подумайте, как обменять строки массива, не обменивая элементы строк
 * по-отдельности.
 * 
 * Требования к реализации: при выполнении этого задания вы можете определять 
 * любые вспомогательные функции. Вводить или выводить что-либо не нужно. 
 * Реализовывать функцию main не нужно.
 */
#include <iostream>
using namespace std;
#include <cstdlib>
#include <time.h>

void fill_array_rand(int *m[], unsigned rows, unsigned cols)
{
    srand(time(NULL));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j) m[i][j] = rand() % 100 + 1;
    }
}

void print_array(int *m[], unsigned rows, unsigned cols)
{
    cout << '\n';
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j) cout << m[i][j] << ' ';
        cout << '\n';
    }
}

void swap_min(int *m[], unsigned rows, unsigned cols)
{
    int lowestRow = 0;
    int lowestVal = m[0][0];
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (m[i][j] < lowestVal)
            {
                lowestVal = m[i][j];
                if (lowestRow != i) lowestRow = i;
            }
        }
    }
    if (lowestRow)
    {
        int * tmpRow = m[lowestRow];
        m[lowestRow] = m[0];
        m[0] = tmpRow;
    }
}

int main(int argc, char const *argv[])
{
    int rows = 4;
    int cols = 4;
    int ** array = new int * [rows];
    array[0] = new int [rows * cols];
    for (int i = 1; i != rows; ++i)
    {
        array[i] = array[i - 1] + cols;
    }
    fill_array_rand(array, rows, cols);
    print_array(array, rows, cols);
    swap_min(array, rows, cols);
    print_array(array, rows, cols);
    return 0;
}