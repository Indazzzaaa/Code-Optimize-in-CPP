#include <iostream>
using namespace std;

class Fibo
{
    long long *dp;
    long long size;

public:
    Fibo(long long n)
    {
        size = n + 1;
        dp = new long long[size];
        for (long long i = 0; i < size; i++)
        {
            dp[i] = -1;
        }

        dp[0] = 0;
        dp[1] = 1;
    }

    static int fibRec(long long n)
    {
        if (n == 0 || n == 1)
            return n;

        return fibRec(n - 1) + fibRec(n - 2);
    }

    long long fibTopDown(long long n)
    {
        if (dp[n] != -1)
            return dp[n];

        dp[n] = fibTopDown(n - 1) + fibTopDown(n - 2);
        return dp[n];
    }

    long long fibTabulation(long long n)
    {
        for (long long i = 2; i < size; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};