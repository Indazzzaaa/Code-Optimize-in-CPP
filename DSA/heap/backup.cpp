#include <iostream>
#include <stdlib.h>
#include "heap.cpp"
using namespace std;

//  ! place here
void creating_heap_with_random_array_test()
{
    int arr[] = {170, 60, 50, 40, 30, 20, 10};
    int size = sizeof(arr) / sizeof(int);
    heap hp(arr, arr + size);
    cout << "after min heapify : ";
    hp.print();

    cout << "Heap sort result : " << endl;
    hp.heapSort();
}

void delete_key_test()
{
    heap hp(5);
    hp.insert(10);
    hp.insert(5);
    hp.insert(12);
    hp.deleteKey(2);

    hp.print();
}

void extract_min_test()
{
    heap hp(5);
    hp.insert(10);
    hp.insert(5);
    hp.insert(12);
    cout << "Printing the min : " << hp.getMin() << endl;
    cout << "Extract min : " << hp.extractMin() << endl;
    hp.print();
}

void insertTest()
{
    heap obj(10);
    obj.insert(10);
    obj.insert(2);
    obj.insert(5);
    obj.insert(3);
    obj.randomInsert(0, 200);
    cout << "Before min hipify : ";
    obj.print();
    cout << "After min hipify : ";
    obj.minHipify(0);
    obj.print();
}
