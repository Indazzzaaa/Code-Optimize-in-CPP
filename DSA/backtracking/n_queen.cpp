#include <iostream>
#include <stdlib.h>
#include <algorithm>
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

bool is_safe(int **arr, int row, int col, int n)
{

    //  checking the the row
    for (int i = col + 1; i < n; i++)
    {
        if (arr[row][i] == 1)
            return false;
    }

    //     check upper right diagonal
    for (int i = row - 1, j = col + 1; i > -1 && j < n; i--, j++)
    {
        if (arr[i][j])
            return false;
    }

    for (int i(row + 1), j(col + 1); i < n && j < n; i++, j++)
    {
        if (arr[i][j])
            return false;
    }

    return true;
}

bool n_queen(int **arr, int n, int qCount, bool debug = false)
{

    if (qCount == 0)
    {
        cout << "Printing board " << endl;
        printArr(arr, n);
        return true;
    }
    if (debug)
    {

        cout << "Printing board for " << endl;
        printArr(arr, n);
    }

    for (int i = 0; i < n; i++)
    {
        if (is_safe(arr, i, qCount - 1, n))
        {
            arr[i][qCount - 1] = 1;
            if (n_queen(arr, n, qCount - 1))
                return true;
            else
            {
                //  reset the position if false returned
                arr[i][qCount - 1] = 0;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    system("cls");
    int n = 0;
    cout << "Enter the queen Count must be > 3 : ";
    cin >> n;
    int *arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n]{0};
    }
    cout << " Initial board " << endl;
    printArr(arr, n);
    cout << "Is board possible : " << n_queen(arr, n, n) << endl;
    cout << "\n\nProcess complted ";

    return 0;
}
