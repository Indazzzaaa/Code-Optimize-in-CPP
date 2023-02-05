// experiment with matrix
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
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

int main(int argc, char const *argv[])
{
    system("cls");
    vector<vector<int>> matrix;
    for (int i = 0; i < 3; i++)
    {
        vector<int> v;
        for (int j = 0; j < 3; j++)
        {
            v.push_back(i);
        }
        matrix.push_back(v);
    }

    printVectorMatrix(matrix);
    cout << endl;
    cin.get();

    return 0;
}
