#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
void printArr(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "  ";
        }
        cout << endl;
    }
}
bool is_safe(int **arr, int n, int row, int col, int val)
{
    //  check int current row
    for (int i = 0; i < col; i++)
    {
        if (arr[row][i] == val)
            return false;
    }
    // check in current colm
    for (int i = 0; i < row; i++)
    {
        if (arr[i][col] == val)
            return false;
    }

    //  check for the small grid;
    int sq = sqrt(n);
    int row_start = row - row % sq;
    int col_start = col - col % sq;
    for (int i = 0; i < sq; i++)
    {
        for (int j = 0; j < sq; j++)
        {
            if (arr[i + row_start][j + col_start] == val)
                return false;
        }
    }

    return true;
}
// ! two step process
//  * 1 find the empty space
//  * 2 try to fill the sapce with all possible values

bool sudoku(int **arr, int n)
{

    //  find the empty space in the grid
    int i, j;
    bool isEmpty = false;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
            {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty)
        {
            break;
        }
    }

    if (i == n && j == n)
    {
        cout << "Printing the board" << endl;
        printArr(arr, n);
        return true;
    }

    for (int t = 1; t < 10; t++)
    {

        if (is_safe(arr, n, i, j, t))
        {
            arr[i][j] = t;
            if (sudoku(arr, n))
                return true;

            // reset to zero for next values
            arr[i][j] = 0;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    system("cls");
    int *arr[9];
    for (int i = 0; i < 9; i++)
    {
        arr[i] = new int[9]{0};
    }
    cout << "size of array " << sizeof(arr) << endl;
    // to make our sudo ku go for all possible combinations
    for (int i = 1; i < 10; i++)
    {
        //  initialize the all array element to 0 fastest way
        for_each(arr, arr + 9, [](auto element)
                 { memset(element, 0, 9 * sizeof(element)); });
        arr[0][0] = i;
        cout << " Initial board " << endl;
        printArr(arr, 9);
        sudoku(arr, 9);
    }

    return 0;
}
