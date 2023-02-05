#include <iostream>
#include <stdlib.h>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

void countDistinctElement()
{
    unordered_set<int> set;
    int arr[] = {1, 1, 2, 3, 4, 5, 5};
    for (auto element : arr)
        set.insert(element);

    cout << "Distinct Element in array is : " << set.size() << endl;
}

void countFreq()
{
    vector<int> v = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, -1, -1, -20, -20, -4, -4};
    unordered_map<int, int> map;
    for (auto element : v)
        map[element]++;
    cout << "Printing the frequency of elment : " << endl;
    for (pair<int, int> entry : map)
        cout << "Data : " << entry.first << "\tFreq : " << entry.second << endl;
}

void longestSubArrayWithSum()
{
    vector<int> v = {3, 1, 0, 1, 8, 2, 3, 6};
    int sum = 5;
    unordered_map<int, int> map;
    int res = 0;
    int pre_sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        pre_sum += v[i];
        if (pre_sum == sum)
            res = i + 1;
        if (map.find(pre_sum) == map.end())
            map[pre_sum] = i;
        if (map.find(pre_sum - sum) != map.end())
        {
            res = max(res, i - map[pre_sum - sum]);
        }
    }

    cout << "Longest sub array is  : " << res << endl;
}

void longestWithEqual_zeros_ones()
{
    vector<int> v = {1, 0, 1, 1, 1, 0, 0};
    unordered_map<int, int> map;
    int res = 0;
    int pre_sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        pre_sum += (v[i] == 0 ? -1 : v[i]);
        if (pre_sum == 0)
            res = i + 1;
        if (map.find(pre_sum) == map.end())
            map[pre_sum] = i;
        else
        {
            res = max(res, i - map[pre_sum]);
        }
    }

    cout << "Longest subarray with equal 0 and 1 is : " << res << endl;
}

int main(int argc, char const *argv[])
{
    // countDistinctElement();
    // countFreq();
    // longestSubArrayWithSum();
    longestWithEqual_zeros_ones();
    return 0;
}
