#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

bool comparator(pair<int, int> &p1, pair<int, int> &p2)
{
    // return (p2.second / p2.first) > (p1.second / p1.first);
    // return p2.second * p1.first > p1.second * p2.first;
    return p2.second * p1.first < p2.first * p1.second;
}

void knapsackTest()
{
    pair<int, int> knapsack[] = {{50, 600}, {20, 500}, {30, 400}};
    int size = sizeof(knapsack) / sizeof(pair<int, int>);
    sort(knapsack, knapsack + size, comparator);
    cout << "Printing the sorted knapsacK : ";
    for_each(knapsack, knapsack + size, [](auto element)
             { cout << "( " << element.first << " , " << element.second << " ) "; });
    cout << endl;
    int capacity = 70;
    int total_value = 0;
    for_each(knapsack, knapsack + size, [&](pair<int, int> element)
             {
                 if (capacity == 0)
                     return;

                 if (capacity > element.first)
                 {
                     capacity -= element.first;
                     total_value += element.second;
                 }
                 else
                 {
                     total_value += (element.second / element.first) * capacity;
                     capacity = 0;
                 } });

    cout << "Total value gathered is  : " << total_value << endl;
}

int main(int argc, char const *argv[])
{
    knapsackTest();
    cout << "\n\n[Process Completed]" << endl;

    return 0;
}
