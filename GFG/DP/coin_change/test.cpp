#include "cc.hpp"

void test1()
{
    vector<int> arr = {1, 2, 3};
    int sum = 4;
    cout << "[Test-1] Result is : " << CoinChange::solveRec(arr, sum, arr.size()) << endl;
    cout << "[Test-1_DP] Result is : " << CoinChange::dpSolve(arr, sum) << endl;
}

void test2()
{
    vector<int> arr = {2, 5, 3, 6};
    int sum = 10;
    cout << "[Test-2] Result is : " << CoinChange::solveRec(arr, sum, arr.size()) << endl;
    cout << "[Test-2_DP] Result is : " << CoinChange::dpSolve(arr, sum) << endl;
}

int main(int argc, char const *argv[])
{
    test1();
    test2();

    cout << "Execution Completed !!" << endl;

    return 0;
}
