#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool customSortFunction(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return b.first < a.first;

    else
        return b.second < a.second;
}

string mostFrequentWord(string arr[], int n)
{
    // pair first value will be it's first encounter index in array and second will be the freq
    unordered_map<string, pair<int, int>> umap;
    for (int i = 0; i < n; i++)
    {
        if (umap.find(arr[i]) == umap.end())
        {
            umap.insert({arr[i], {i, 1}});
        }
        else
        {
            umap[arr[i]].second = umap[arr[i]].second + 1;
        }
    }

    vector<pair<int, int>> result;
    for (auto it = umap.begin(); it != umap.end(); it++)
    {
        result.push_back(it->second);
    }

    sort(result.begin(), result.end(), customSortFunction);

        return arr[result[0].first];
}

int main(int argc, char const *argv[])
{
    string arr[] = {"geeks",
                    "for",
                    "geeks"};
    int size = sizeof(arr) / sizeof(arr[0]);
    mostFrequentWord(arr, size);
    return 0;
}
