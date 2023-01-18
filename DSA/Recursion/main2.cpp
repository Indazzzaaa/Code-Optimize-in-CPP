#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string> // this is needed , otherwise cout won't print it.
using namespace std;
#define print(x) cout << endl
#define printX(x) cout << x

void setMethodSubsetGenerate(string s);
void recMethodSubsetGenerate(string &s, string res, int i);
int subSetSum(int arr[], int sum, int n);
void printPermutation(string s, int i);

int main(int argc, char const *argv[])
{
    system("cls");

    // setMethodSubsetGenerate("abcd");
    string s = "abc";
    printPermutation(s, 0);

    return 0;
}

void printPermutation(string s, int i)
{

    if (i == s.length())
    {
        cout << s << endl;

        return;
    }

    for (int j = i; j < s.length(); j++)
    {
        swap(s[j], s[i]);
        printPermutation(s, i + 1);
        swap(s[j], s[i]);
    }
}

int subSetSum(int arr[], int sum, int n)
{
    if (n == 0)
        return sum == 0 ? 1 : 0;

    // optimization
    if (sum < 0)
        return 0;

    return subSetSum(arr, sum, n - 1) +
           subSetSum(arr, sum - arr[n - 1], n - 1);
}

void recMethodSubsetGenerate(string &s, string res, int i)
{

    if (i == s.length())
    {
        cout << res << endl;
        return;
    }

    recMethodSubsetGenerate(s, res, i + 1);
    recMethodSubsetGenerate(s, res + s[i], i + 1);
}

void setMethodSubsetGenerate(string s)
{
    int n = pow(2, s.length());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            if (i & (1 << j))
                printX(s[j]);
        }
        print();
    }
}
