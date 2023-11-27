#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class LIS
{
public:
    // n^2
    static int lisNormal(vector<int> arr)
    {
        const int size = arr.size();
        if (size == 0 || size == 1)
            return size;
        int lisArr[size];
        lisArr[0] = 1;
        int maxLength = 1;
        for (int i = 1; i < size; i++)
        {
            lisArr[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] > arr[j])
                {
                    lisArr[i] = max(lisArr[j] + 1, lisArr[i]);
                    maxLength = max(maxLength, lisArr[i]);
                }
            }
        }

        return maxLength;
    }

    // nlog(n)
    static int lisBinarySearch(vector<int> arr)
    {
        const int size = arr.size();
        if (size == 0 || size == 1)
            return size;
        int lisArr[size];
        int lisIndex = 0;
        lisArr[lisIndex] = arr[0];
        for (int i = 1; i < size; i++)
        {
            if (arr[i] > lisArr[lisIndex])
            {
                lisArr[++lisIndex] = arr[i];
            }
            else
            {
                int temp = arr[i];
                auto ref = upper_bound(&lisArr[0], &lisArr[lisIndex], temp);

                int index = (ref - &lisArr[0]);

                // important for dealing with test-case3
                if (lisIndex > 0 && lisArr[index - 1] != arr[i])
                    *ref = arr[i];
                // cout << "Index is : " << (ref - &lisArr[0]) << endl;
            }
        }

        return lisIndex + 1;
    }
};

class Problems
{
public:
    // minimum deletion require to make array sorted
    static int minDelToSort(vector<int> arr)
    {
        return arr.size() - LIS::lisBinarySearch(arr);
    }
};