#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

void printVector()
{

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    // !const ref make sure that we don't modify the variable
    for_each(v.begin(), v.end(), [](int const &i) -> void
             { cout << i << endl; });
}

void testEnclosingScope()
{

    auto sq = [&](int a)
    {
        a *= a;
        return a;
    };
    int b = 10;
    int res = sq(b);
    cout
        << res << "\t" << b;
}

int main(int argc, char const *argv[])
{
    // printVector();
    testEnclosingScope();
    return 0;
}

/*
https://www.geeksforgeeks.org/lambda-expression-in-c/

[ capture clause ] (parameters) -> return-type
{
   definition of method
}

Generally, the return-type in lambda expressions is evaluated by the compiler itself and we don’t need to specify it explicitly. Also the -> return-type part can be ignored

e.g. conditional statements, the compiler can’t determine the return type and explicit specification is required.


A lambda expression can have more power than an ordinary function by having access to variables from the enclosing scope. We can capture external variables from the enclosing scope in three ways :
      Capture by reference
      Capture by value
      Capture by both (mixed capture)
Syntax used for capturing variables :
      [&] : capture all external variables by reference
      [=] : capture all external variables by value
      [a, &b] : capture a by value and b by reference
A lambda with an empty capture clause [ ] can only access variables which are local to it.


 */