#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "Enter the size of array : ";
    int n;
    cin >> n;
    int arr[n];
    cout << "\n Size of array is : " << sizeof(arr) / sizeof(int) << endl;

    return 0;
}
