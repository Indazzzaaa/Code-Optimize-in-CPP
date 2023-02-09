#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

#define show(msg, x) cout << msg << x << endl

struct kstack
{
    int *container;
    int *stackTops;
    // *next array used for storing the next element and getting next free space
    int *nextArray;
    int capacity;
    int numberOfStacks;
    int size;
    int freeTop;

    kstack(int requiredCapacity, int stacksWant)
    {
        this->capacity = requiredCapacity;
        this->numberOfStacks = stacksWant;
        freeTop = 0;
        size = 0;
        container = new int[capacity]{0};
        nextArray = new int[capacity];
        stackTops = new int[stacksWant];
        this->initializeValues();
    }
    void print(auto container, int conSize)
    {
        for_each(container, container + conSize, [](auto element)
                 { cout << element << " "; });
        cout << endl;
    }

    void printObj()
    {

        show("Capacity of stack : ", capacity);
        show("Number of stacks : ", numberOfStacks);
        show("Current number of elements in stack : ", size);
        cout << "Container data : " << endl;
        print(container, capacity);
        cout << "stack tops data : " << endl;
        print(stackTops, numberOfStacks);
        cout << "Next array data : " << endl;
        print(nextArray, capacity);
        cout << "Current Free Top pos : " << freeTop << endl;
    }

    void push(int stackNo, int data)
    {

        if (freeTop == -1)
        {
            cout << "Stack is full  " << endl;
            return;
        }
        container[freeTop] = data;
        int nextFreeSpace = nextArray[freeTop];
        nextArray[freeTop] = stackTops[stackNo - 1];
        stackTops[stackNo - 1] = freeTop;
        freeTop = nextFreeSpace;
        size++;
    }

    int pop(int stackNo)
    {
        if (stackTops[stackNo - 1] == -1)
        {
            cout << "your stack : " << stackNo << " Is empty : " << endl;
            return INT_MIN;
        }
        int pos = stackTops[stackNo - 1];
        int dataToReturn = container[pos];
        // now update the nextFreeTopArray and stacktops
        stackTops[stackNo - 1] = nextArray[pos]; // this will give us the last store element index
        nextArray[pos] = freeTop;
        freeTop = pos;
        size--;
        return dataToReturn;
    }

private:
    void
    initializeValues()
    {
        for (int i = 0; i < numberOfStacks; i++)
        {
            stackTops[i] = -1;
        }

        for (int i = capacity - 2; i > -1; i--)
        {
            nextArray[i] = i + 1;
        }
        nextArray[capacity - 1] = -1;
    }
};

int main(int argc, char const *argv[])
{
    kstack stack(10, 3);
    stack.printObj();
    cout << endl
         << endl;

    for (int i = 0; i < 12; i++)
    {
        stack.push(i % 3 + 1, i);
    }
    stack.printObj();
    cout << endl
         << endl;
    for (int i = 0; i < 12; i++)
    {
        int stackNo = i % 3 + 1;
        cout << "Stack No : " << stackNo << " Data : " << stack.pop(stackNo) << endl;
    }

    return 0;
}
