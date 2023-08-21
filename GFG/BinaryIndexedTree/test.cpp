#include "BIT.hpp"

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    BIT bit_tree = BIT(arr, size);
    bit_tree.logBST();
    cout << "SUm is " << bit_tree.getSum(2) << endl;
    bit_tree.Update(1, 20);
    cout << "SUm is " << bit_tree.getSum(2) << endl;

    cout << "Program Finished!" << endl;
    return 0;
}
