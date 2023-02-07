#include <iostream>
#include <time.h>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
using namespace std;

#define long long long

// this is simple recusive  version

void timeSandBox(long (*func)(long), int n)
{

    clock_t start, end;

    start = clock();
    cout << n << " th fiboncci number is :  " << func(n) << endl;
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken to execute this program is  : " << time_taken << setprecision(7) << "sec" << endl;
}

long fibRec(long n)
{
    if (n == 0 || n == 1)
        return n;

    return fibRec(n - 1) + fibRec(n - 2);
}

long fibRecMemoization(int n, vector<long> &m)
{
    if (n == 0 || n == 1)
    {
        m[n] = n;
    }

    if (m[n] != -1)
        return m[n];
    m[n] = fibRecMemoization(n - 1, m) + fibRecMemoization(n - 2, m);
    return m[n];
}
long fibTabulation(long n)
{
    vector<int> m(n + 1, -1);
    m[0] = 0;
    m[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        m[i] = m[i - 1] + m[i - 2];
    }
    return m[n];
}
void memoizationTest(int n)
{

    vector<long> m(n + 1, -1);
    // for_each(m.begin(), m.end(), [](int element)
    //          { cout << element << " "; });
    cout << n << "th  fibonnaci number is  : " << fibRecMemoization(n, m) << endl;
}

int main(int argc, char const *argv[])
{
    system("cls");
    cout << "Program started .." << endl;
    // timeSandBox(fibRec, 40); not working above 40
    // timeSandBox(fibTabulation, 50);
    memoizationTest(10);
    cin.get();

    return 0;
}
