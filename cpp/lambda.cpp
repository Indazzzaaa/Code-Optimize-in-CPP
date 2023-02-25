#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
using namespace std;

void test2()
{
    vector<int> v = {2, 3, 1, 5, 6};
    auto comparator = [](int e1, int e2) -> bool
    {
        return e2 > e1;
    };
    sort(v.begin(), v.end(), comparator);
    for_each(v.begin(), v.end(), [](int element)
             { cout << element << "  "; });
}

void immediateInvokeLambda()
{
    int num1 = 1;
    int num2 = 2;

    // invoked as soon as it is defined
    auto sum = [](int a, int b)
    {
        return a + b;
    }(num1, num2);

    cout << "The sum of " << num1 << " and " << num2 << " is " << sum;
}

int main()
{
    // test2();
    vector<int> v = {2, 3, 1, 5, 6};
    cout << "Max is : " << *max_element(v.begin(), v.end()) << endl;
    cout << "min is : " << *min_element(v.begin(), v.end()) << endl;
    immediateInvokeLambda();
}

void test1()
{

    int a = 10;
    int b = 20;
    auto lambda = [a, &b](int element) -> int
    { 
        // a=11; won't allow it
        b = 21;
        return element + a + b; };
    cout << lambda(30) << endl;
    cout << "a,b :" << a << "," << b << endl;
}