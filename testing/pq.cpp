#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {10, 2, 13, 4, 8};
    priority_queue<int> pq(arr, arr + 5);
    cout << arr[0] << endl;

    return 0;
}
