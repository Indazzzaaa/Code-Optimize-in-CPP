#include "LIS.hpp"
#include <algorithm>

void test1()
{
    vector<int> arr = {1, 8, 2, 6, 3};
    cout << "[Test_1] Result is : " << LIS::lisNormal(arr) << endl;
    cout << "[Test_1_Binary] Result is : " << LIS::lisBinarySearch(arr) << endl;
}

void test2()
{
    vector<int> arr = {1, 1, 1, 1};
    cout << "[Test_2] Result is : " << LIS::lisNormal(arr) << endl;
    cout << "[Test_2_Binary] Result is : " << LIS::lisBinarySearch(arr) << endl;
}

void test3()
{
    vector<int> arr = {1, 2, 1, 2, 1, 2, 1, 2, 2};
    cout << "[Test_3] Result is : " << LIS::lisNormal(arr) << endl;
    cout << "[Test_3_Binary] Result is : " << LIS::lisBinarySearch(arr) << endl;
}
int main(int argc, char const *argv[])
{
    test1();
    test2();
    test3();

    cout << "Execution Completed !!" << endl;
    return 0;
}
