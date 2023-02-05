#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

void printVectorMatrix(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
// for tranpose matrix must be squre matrix
void transpose(vector<vector<int>> &matrix)
{

    for (int i = 0; i < matrix.size(); i++)
    {
        int col = matrix[i].size();
        for (int j = i + 1; j < col; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

void rotateAnticlock(vector<vector<int>> &matrix)
{

    // take mirror image about bottom
    transpose(matrix);
    printVectorMatrix(matrix);
    cout << endl;
    int i = 0, j = matrix.size() - 1;
    while (j > i)
    {
        for (int col = 0; col < matrix.size(); col++)
        {
            swap(matrix[i][col], matrix[j][col]);
        }

        i++;
        j--;
    }
    printVectorMatrix(matrix);
    cout << endl;
}

void spiralPrint(vector<vector<int>> &matrix)
{
    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;
    while (bottom >= top && right >= left)
    {
        // print left to right : top++
        for (int i = left; i <= right; i++)
        {
            cout << matrix[top][i] << " ";
        }
        top++;

        // print top to bottom :right --
        for (int i = top; i <= bottom; i++)
        {
            cout << matrix[i][right] << " ";
        }
        right--;

        // edge cases of single row
        if (top <= bottom)
        {
            // print right to left : bottom--
            for (int i = right; i >= left; i--)
            {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        // edge case when single colm
        if (left <= right)
        {
            // print bottom to top : left++
            for (int i = bottom; i >= top; i--)
            {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }

    cout << endl
         << "Spiral Print completed : " << endl;
}

bool searchInRowColmMatrix(vector<vector<int>> &matrix, int &x)
{

    int row = 0, col = matrix[0].size() - 1;
    int rowCount = matrix.size();
    int colCount = matrix[0].size();

    while (row < rowCount && col < colCount)
    {
        if (matrix[row][col] == x)
            return true;
        else if (matrix[row][col] > x)
        {
            col--;
        }
        else
        {
            row++;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    system("cls");
    vector<vector<int>> matrix = {{10, 20, 30, 40},
                                  {15, 25, 35, 45},
                                  {27, 29, 37, 48},
                                  {32, 33, 39, 50}};

    int key = 31;

    cout << "Is value present " << searchInRowColmMatrix(matrix, key);

    cin.get();
    return 0;
}
