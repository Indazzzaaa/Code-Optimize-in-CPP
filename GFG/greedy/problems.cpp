#include <iostream>
#include <vector>

#include <algorithm>
using namespace std;
// custom sort function
bool myComp(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.second < p2.second;
}
int activitySelection(vector<int> start, vector<int> end, int n)
{
    // 1. create pair of start and end time
    // 2. Sort the pair in increasing order of there end time
    // 3. Now on sorted list do the greedy operation

    vector<pair<int, int>> list;
    for (int i = 0; i < n; i++)
    {
        list.push_back({start[i], end[i]});
    }

       sort(list.begin(), list.end(), myComp);

    //  we are always picking up the first activity
    pair<int, int> prev = list[0];
    int count = 1;

    // now do greedy selection of the activity
    for (int i = 1; i < list.size(); i++)
    {
        if (prev.second < list[i].first)
        {
            prev = list[i];
            count++;
        }
    }

    return count;
}

int main(int argc, char const *argv[])
{
    int a = 2, b = 3;
    double r1 = b / a;
    cout << r1 << endl;

    return 0;
}
