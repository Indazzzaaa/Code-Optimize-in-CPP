#include "tree.hpp"

int main(int argc, char const *argv[])
{
    int arr[] = {10, 20, 30, 40, 50, 60};
    int size = sizeof(arr) / sizeof(arr[0]);

    auto tree = SegmentTree(arr, size);
    // tree.logTree();
    cout << "Sum  is : " << tree.rangeQuerry(0, 1) << endl;
    tree.updateQuerry(1, 25);
    cout << "Sum  is : " << tree.rangeQuerry(0, 1) << endl;
    cout << "Program Finished" << endl;
    return 0;
}
