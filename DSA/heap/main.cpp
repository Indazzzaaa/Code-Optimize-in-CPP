#include <iostream>
#include <stdlib.h>
#include <queue>
#include "heap.cpp"
using namespace std;


int main(int argc, char const *argv[])
{
    system("cls");
    cout << "[Process started ] \n\n\n";

    // creating_heap_with_random_array_test();
    // my_comp obj;
    // cout << "Test custom comparator function: " << obj(10, 20) << endl;
    cout
        << "\n\n\n[Process Ended ] " << endl;
    cin.get();

    return 0;
}
struct my_comp
{

    int operator()(const int &a, const int &b) const
    {
        return b > a ? b : a;
    }
};