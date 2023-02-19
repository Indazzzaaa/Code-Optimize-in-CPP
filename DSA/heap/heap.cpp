#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

// ! this is min heap we have designed
struct heap
{
    int *container;
    int size;
    int capacity;
    heap(const int &tempCapacity)
    {
        this->capacity = tempCapacity;
        container = new int[capacity];
        size = 0;
    }

    heap(int *startPtr, int *endPtr)
    {
        cout << "Capacity is  : " << endPtr - startPtr << endl;
        this->capacity = endPtr - startPtr;
        container = new int[this->capacity];
        for (int i = 0; i < capacity; i++, startPtr++)
        {
            container[i] = *startPtr;
        }
        size = capacity;

        createHeap();
    }

    void createHeap()
    {

        // now start creating the heap from the bottom most right most parent
        for (int i = (size - 2) / 2; i > -1; i--)
        {
            minHipify(i);
        }
    }

    ~heap()
    {
        cout << "Destructor is called  " << endl;
        delete[] container;
    }

    //  ! just for testing minhipify and all
    void randomInsert(int index, int key)
    {
        container[index] = key;
    }

    int getLeftChild(int index)
    {
        int left = (2 * index + 1);
        return left > (size - 1) ? index : left;
    }

    int getRightChild(int index)
    {
        int right = (2 * index + 2);
        return right > (size - 1) ? index : right;
    }

    int getParent(int index)
    {
        return (index - 1) / 2;
    }

    void print()
    {
        for_each(container, container + size, [](int element)
                 { cout << element << " "; });
        cout << endl;
    }

    void insert(int key)
    {
        if (size == capacity)
        {
            cout << "your container if full " << endl;
            return;
        }

        int currPos = size;
        container[currPos] = key;
        size++;
        while (currPos > 0 && container[getParent(currPos)] > container[currPos])
        {
            int parent = getParent(currPos);
            swap(container[parent], container[currPos]);
            currPos = parent;
        }
    }

    //  !mosty this does from index 0 , but used as subroutine in case of random array
    void minHipify(int index)
    {
        int smallest = index;
        if (container[getRightChild(index)] < container[smallest])
        {
            smallest = getRightChild(index);
        }

        if (container[getLeftChild(index)] < container[smallest])
        {
            smallest = getLeftChild(index);
        }

        if (smallest != index)
        {
            swap(container[smallest], container[index]);
            minHipify(smallest);
        }
    }

    int getMin()
    {
        if (size == 0)
        {
            cout << "You don't have any element in it. " << endl;
            return INT_MAX;
        }

        return container[0];
    }

    int extractMin()
    {
        if (size == 0)
        {
            cout << "Your container is empty : " << endl;
            return INT_MAX;
        }
        int dataToReturn = container[0];
        swap(container[0], container[size - 1]);
        size--;
        minHipify(0);

        return dataToReturn;
    }

    void decreaseKey(int i, int key)
    {
        int parent = getParent(i);
        container[i] = key;
        while (i > -1 && container[parent] > key)
        {
            swap(container[i], container[parent]);
            i = parent;
        }
    }

    void deleteKey(int index)
    {
        if (size == 0)
        {
            cout << "Your container is empty " << endl;
            return;
        }

        decreaseKey(index, INT_MIN);
        extractMin();
    }

    void heapSort()
    {
        int tempSize = size;
        for (int i = 0; i < tempSize; i++)
        {
            swap(container[0], container[size - 1]);
            size--;
            minHipify(0);
        }
        size = tempSize;

        this->print();
    }
};
