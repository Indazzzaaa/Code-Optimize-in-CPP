#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;

void findMedian(int arr1[], int arr2[], int n1, int n2)
{

    // we have assumed size of arr1 <=size of arr2
    int begin = 0, end = n1;
    while (end >= begin)
    {
        int i1 = (begin + end) / 2;
        int i2 = (n1 + n2 + 1) / 2 - i1;

        int min1 = (i1 == n1 ? INT_MAX : arr1[i1]);
        int max1 = (i1 == 0 ? INT_MIN : arr1[i1 - 1]);

        int min2 = (i2 == n2 ? INT_MAX : arr2[i2]);
        int max2 = (i2 == 0 ? INT_MIN : arr2[i2 - 1]);

        if (max1 <= min2 && min1 >= max2)
        {
            if ((n2 + n1) % 2 == 0) // make sure use modulo otherwise never give ans(because of float)
            {
                int ans = (max(max1, max2) + min(min1, min2)) / 2;
                cout << "Answer is  : " << ans << endl;
            }
            else
            {
                int ans = max(max1, max2);
                cout << "i1 and i2 are : " << i1 << "," << i2 << endl;
                cout << "Answer is : " << ans << endl;
            }
        }

        if (max1 > min2)
        {
            end = i1 - 1;
        }
        else
        {
            begin = i1 + 1;
        }
    }
}

void findRepeatingElement(int arr[], int n)
{

    // with 1 it's works fine , but 0 and  1 at same index must be take care of
    int slow = arr[0] + 1, fast = arr[0] + 1;
    do
    {
        slow = arr[slow] + 1;
        fast = arr[arr[fast] + 1];
    } while (slow != fast);

    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow] + 1;
        fast = arr[fast] + 1;
    }

    cout << "Element that found is : " << slow - 1 << endl;
}

bool isFeasible(int arr[], int n, int k, int sum)
{
    int res = 1;
    int tempSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (tempSum + arr[i] > sum)
        {
            res++;
            tempSum = arr[i];
        }
        else
        {
            tempSum += arr[i];
        }
    }

    return (res <= k);
}

int allocatesMinPages(int arr[], int n, int k)
{
    int max = arr[0], sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        max = std::max(max, arr[i]);
        sum += arr[i];
    }
    int start = max, end = sum;
    int res = 0;
    while (start <= end)
    {
        cout << "Start and end are : " << start << "," << end << endl;
        int mid = (start + end) / 2;
        if (isFeasible(arr, n, k, mid))
        {
            res = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    system("cls");
    /*     int arr1[] = {10, 20, 30, 40, 50};
        int arr2[] = {5, 15, 25, 35, 45};
        findMedian(arr1, arr2, 5, 5); */

    int arr1[] = {10, 20, 30, 40, 50, 60, 70};
    cout << "Pages allocated are : " << allocatesMinPages(arr1, 7, 3) << endl;

    cin.get();
    return 0;
}
