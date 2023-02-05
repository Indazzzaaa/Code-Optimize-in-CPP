#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int> &a, int k)
{
    unordered_map<int, int> u;

    int n = a.size();
    int i;

    for (i = 0; i < n; i++)
    {
        u[a[i]]++;
    }

    vector<pair<int, int>> v(u.begin(), u.end());

    sort(v.begin(), v.end(), [](pair<int, int> x, pair<int, int> y)
         {
        if (x.second == y.second)
            return x.first < y.first;
        else
            return x.second > y.second; });

    vector<int> r;
    for (i = 0; i < k; i++)
    {
        r.push_back(v[i].first);
    }

    return r;
}

int main()
{
    cout << "\n\nWelcome to Studytonight :-)\n\n\n";
    cout << " =====  Program to find the top k most frequent elements in a vector, in CPP  ===== \n\n\n";

    // initializing vector with the following elements
    vector<int> v = {1, 2, 3, 1, 2, 1};

    vector<int> f;

    int k = 2; // to find the 2 most frequent numbers

    int n = v.size();

    cout << "The elements of the given vector is : ";

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << "  ";
    }

    f = topKFrequent(v, k);

    n = f.size();

    cout << "\n\n The top " << k << " most frequent numbers are: ";

    for (int i = 0; i < n; i++)
    {
        cout << f[i] << "    ";
    }

    cout << "\n\n\n";

    return 0;
}