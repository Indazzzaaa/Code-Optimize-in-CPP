#include "LIS.hpp"

void test_min_del_to_sort_array()
{
    vector<int> arr = {5, 10, 3, 6, 7, 8};
    cout << "Min element to delete  is : " << Problems::minDelToSort(arr) << endl;
}

int main(int argc, char const *argv[])
{
    test_min_del_to_sort_array();
    cout << "Execution completed!!" << endl;

    return 0;
}
