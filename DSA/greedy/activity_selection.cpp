#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

bool custom_comp(pair<int, int> &p1, pair<int, int> &p2)
{
    return p2.second > p1.second;
}

void activities_test()
{

    pair<int, int> activities[] = {{1, 3}, {2, 4}, {3, 8}, {10, 11}};
    int size = sizeof(activities) / sizeof(pair<int, int>);
    sort(activities, activities + size, custom_comp);
    cout << "Sorted pair printing : " << endl;
    for_each(activities, activities + size, [](auto element)
             { cout << "( " << element.first << "," << element.second << " )"
                    << " "; });
    cout << endl;

    pair<int, int> &lastSelected = activities[0];
    cout << "Address Test :  ";
    cout << &lastSelected << "  " << &activities[0] << endl;
    int count = 1;
    for (int i = 1; i < size; i++)
    {
        if (activities[i].first >= lastSelected.second)
        {
            count++;
            lastSelected = activities[i];
        }
    }

    cout << "Activities that can be completed in given time is : " << count << endl;
}

int main(int argc, char const *argv[])
{
    system("cls");
    cout << "[Process Started]\n\n";
    activities_test();

    cout << "\n\n[Process Ended]" << endl;

    return 0;
}
