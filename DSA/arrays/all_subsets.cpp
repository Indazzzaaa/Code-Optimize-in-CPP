#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
    system("cls");
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int t = i; t <= j; t++)
            {
                cout << arr[t] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
