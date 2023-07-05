#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSwaps(vector<int> &nums)
{
    vector<pair<int, int>> valIndexPair;
    for (int i = 0; i < nums.size(); i++)
    {
        valIndexPair.push_back({nums[i], i});
    }
    sort(valIndexPair.begin(), valIndexPair.end());

    int count = 0; // this will count the number of swaps
    for (int i = 0; i < valIndexPair.size(); i++)
    {
        if (i != valIndexPair[i].second)
        {
            count++;
            swap(valIndexPair[i], valIndexPair[valIndexPair[i].second]);
            i--; // after swap again recheck at current index
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    vector<int> test1 = {2,
                         8,
                         5,
                         4};

    vector<int> test2 = {10,
                         19,
                         6,
                         3,
                         5};

    vector<int> test3 = {13, 1, 5, 3, 6, 11, 10};

    cout
        << "Test1 : " << minSwaps(test1) << endl;
    cout << "Test2: " << minSwaps(test2) << endl;
    cout << "Test3: " << minSwaps(test3) << endl;

    return 0;
}
