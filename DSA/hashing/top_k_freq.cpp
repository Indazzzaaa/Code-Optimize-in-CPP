#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
//  ! this solution is nlogn , but with heap can be created in nlogk
void printMap(unordered_map<int, int> &map)
{
    for (auto entry : map)
        cout << entry.first << "\t" << entry.second << endl;
}

void printVector(vector<pair<int, int>> &v)
{
    cout << "Printing vector of size  : " << v.size() << endl;
    for (auto i : v)
        cout << i.first << "\t" << i.second << endl;
}

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second == p2.second)
    {

        // if both freq same then we want smallest to be first
        return p1.first < p2.first;
    }
    else
    {
        return p1.second > p2.second;
    }
}

void topK()
{
    vector<int> v = {1, 2, 4, 1, 2, 1, 3};
    unordered_map<int, int> map;
    for (int element : v)
        map[element]++;
    vector<pair<int, int>> result(map.begin(), map.end());
    // printMap(map);
    cout << "Printing vector before sort : " << endl;
    printVector(result);
    // sort(result.begin(), result.end(), compare);
    sort(result.begin(), result.end(), [](pair<int, int> p1, pair<int, int> p2)
         {
             if (p1.second == p2.second)
                 return p1.first < p2.first;

             return p1.second > p2.second; });
    cout
        << "Printing vector after sort : " << endl;
    printVector(result);
}

int main(int argc, char const *argv[])
{
    system("cls");
    topK();
    cin.get();
    return 0;
}
