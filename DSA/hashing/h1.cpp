#include <iostream>
#include <stdlib.h>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void hash_setOperation()
{
    unordered_set<int> set = {1, 2, 3, 4, 5};
    set.insert(10);
    set.insert({20, 30});
    set.erase(20);

    // value iteration
    for (int x : set)
        cout << x << " ";
    cout << endl;

    set.insert(30);
    cout << set.count(30) << endl;
    //  pointer interation
    for (auto it = set.begin(); it != set.end(); it++)
        cout << *it << " ";
    cout << endl;
}
void hash_mapOperation()
{

    unordered_map<string, int> map = {{"a", 1}, {"b", 2}};
    map["c"] = 3;
    //! map["d"]; very dangerous line if the element does not exist it put 0 in there

    //! cout << map["d"] << endl;

    map.insert({"f", 10});
    //  erase function will return 0 if that does not exist if yes then 1
    cout << map.erase("dd") << endl;
    cout << map.erase("a") << endl;

    // testing for found
    cout << "Testing for found " << map.count("a") << endl;
    cout << "Testing for found " << map.count("b") << endl;

    cout << "size of map " << map.size() << endl;
    map.clear();
    cout << "size of map " << map.size() << endl;
    cout << "Testing for empty " << map.empty() << endl;
    // traversing on the element
    for (pair<string, int> x : map)
        cout << x.first << "  " << x.second << endl;

    cout << "Using iterator for traversing ------" << endl;
    for (auto it = map.begin(); it != map.end(); it++)
        cout << it->first << " " << it->second << endl;
}

int main(int argc, char const *argv[])
{
    system("cls");

    // hash_setOperation();
    hash_mapOperation();
    cin.get();
    return 0;
}
