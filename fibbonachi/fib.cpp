// f0 =0, f1=1,f2=1 , f3=2 ......
#include <iostream>
using namespace std;
long long fibRec(long long);
long long fib_Optimized(long long n);
int main(int argc, char const *argv[])
{
    int n = 100;
    // takes logn of time.
    cout << "Result is : " << fib_Optimized(n) << endl;
    cout << "Result is : " << fibRec(n) << endl;

    return 0;
}

long long fibRec(long long n)
{

    if (n == 0 || n == 1)
        return n;

    return fibRec(n - 2) + fibRec(n - 1);
}

void dot(long long mat[2][2], long long mat2[2][2])
{

    long long n00, n01, n10, n11;
    n00 = mat[0][0] * mat2[0][0] + mat[0][1] * mat2[1][0];
    n01 = mat[0][0] * mat2[0][1] + mat[0][1] * mat2[1][1];
    n10 = mat[1][0] * mat2[0][0] + mat[1][1] * mat2[1][0];
    n11 = mat[1][0] * mat2[0][1] + mat[1][1] * mat2[1][1];
    mat[0][0] = n00;
    mat[0][1] = n01;
    mat[1][0] = n10;
    mat[1][1] = n11;
}

void power(long long matrix[2][2], int n)
{

    // identity matrix
    long long result[2][2] = {
        {1, 0},
        {0, 1}};

    while (n > 0)
    {
        if (n % 2 == 1)
        {
            dot(result, matrix);
        }
        dot(matrix, matrix);
        n = n / 2;
    }

    matrix[0][0] = result[0][0];
    matrix[0][1] = result[0][1];
    matrix[1][0] = result[1][0];
    matrix[1][1] = result[1][1];
}

long long fib_Optimized(long long n)
{

    // fib(n) == [[1 1] , [1,0]] ^n-1
    if (n == 0)
        return n;
    long long result[2][2] = {
        {1, 1},
        {1, 0}};
    power(result, n - 1);
    return result[0][0];
}
