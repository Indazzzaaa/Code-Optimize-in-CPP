#include <iostream>
#include <vector>
using namespace std;

#define MATRIX vector<vector<int>>

void printMat(MATRIX &output)
{

    int rowCount = output.size();
    int colCount = output[0].size();
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixMultipication(MATRIX mat1, MATRIX mat2)
{
    int rowsCount = mat1.size();
    int colCount = mat2[0].size();
    // ! this is the main thing to remember
    MATRIX output(rowsCount, vector<int>(colCount));
    for (int i = 0; i < rowsCount; i++)
    {

        for (int j = 0; j < colCount; j++)
        {
            int sum = 0;
            for (int t = 0; t < colCount; t++)
            {
                sum += mat1[i][t] * mat2[t][j];
            }
            output[i][j] = sum;
        }
    }
    printMat(output);
}

int main()
{

    MATRIX m1 = {{1, 2}, {3, 4}, {5, 6}};
    MATRIX m2 = {{10, 20}, {30, 40}};

    matrixMultipication(m1, m2);
    cout << "DONE THE EXECUTION" << endl;
    return 0;
}
