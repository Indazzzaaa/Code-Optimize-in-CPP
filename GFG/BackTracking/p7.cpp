// Unique Subsets

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareVectors(const std::vector<int> &a, const std::vector<int> &b)
{
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] == b[j])
        {
            i++;
            j++;
            continue;
        }
        if (b[j] > a[i])
            return true;
        else
            return false;
    }

    return a.size() < b.size();
}

void solveRec(vector<vector<int>> &result, vector<int> &currSubset, vector<int> arr, int &n, int i)
{

    if (i == n)
    {
        result.push_back(vector<int>(currSubset.begin(), currSubset.end()));
        // cout << "Now size is : " << result.size() << endl;
        return;
    }

    currSubset.push_back(arr[i]);
    solveRec(result, currSubset, arr, n, i + 1);
    currSubset.pop_back();
    while (i + 1 < n && arr[i] == arr[i + 1])
    {
        i++;
    }
    solveRec(result, currSubset, arr, n, i + 1);
}

vector<vector<int>> AllSubsets(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());
    vector<int> currSubset;
    vector<vector<int>> result;
    solveRec(result, currSubset, arr, n, 0);
    sort(result.begin(), result.end(), compareVectors);
    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 1, 3, 2};
    vector<vector<int>> results = AllSubsets(arr, arr.size());
    for (vector<int> result : results)
    {
        for (auto i : result)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << "Size of result is : " << results.size() << endl;
    cout << "Program Execution Completed!" << endl;

    return 0;
}
