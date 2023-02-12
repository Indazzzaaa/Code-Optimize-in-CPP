#include <iostream>
#include <deque>
#include <algorithm>
#include <Vector>
#include <stdlib.h>
using namespace std;

void dqTravering()
{

    deque<int> dq;
    for (int i = 0; i < 5; i++)
    {
        dq.push_back(i);
    }
    for (int i = 5; i < 10; i++)
    {
        dq.push_front(i);
    }

    for_each(dq.begin(), dq.end(), [](int element)
             { cout << element << endl; });
}

void getMaxInKSizeWindow()
{
    vector<int> arr = {10, 8, 5, 12, 15, 7, 6};
    deque<int> dq;
    int k = 3;
    for (int i = 0; i < k; i++)
    {
        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    cout << "Greater element is : " << arr[dq.front()] << endl;

    for (int i = k; i < arr.size(); i++)
    {
        // take out element if eligible for
        if (dq.front() < (i - k))
        {
            dq.pop_front();
        }

        // put the new element at right place
        while (!dq.empty() && arr[dq.back()] < arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);

        cout << "Greater element is : " << arr[dq.front()] << endl;
    }
}

int main(int argc, char const *argv[])
{
    system("cls");
    // dqTravering();
    getMaxInKSizeWindow();

    return 0;
}
