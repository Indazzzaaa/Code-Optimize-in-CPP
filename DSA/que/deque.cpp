#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>
using namespace std;

class Dqueue
{
    int *container;
    int capacity;
    int size;
    int front;

public:
    Dqueue(int cap)
    {
        capacity = cap;
        container = new int[capacity];
        for_each(container, container + capacity, [](int &element)
                 { element = -1; });
        size = 0;
        front = 0;
    }

    void push_back(int data)
    {
        if (isFull())
        {
            cout << "Your array is full : " << endl;
            return;
        }
        int rear = (getRear() + 1) % capacity;
        container[rear] = data;
        size++;
    }

    int pop_back()
    {
        if (isEmpty())
        {
            cout << "Your queue is empty : " << endl;
            return INT_MIN;
        }

        int dataToReturn = container[getRear()];
        size--;
        return dataToReturn;
    }

    int pop_front()
    {
        if (isEmpty())
        {
            cout << "Your queue is empty : " << endl;
            return INT_MIN;
        }
        int dataToReturn = container[front];
        front = (front + 1) % capacity;
        return dataToReturn;
    }

    void pushFront(int data)
    {
        if (isFull())
        {
            cout << "Your array is full : " << endl;
            return;
        }
        front = (front - 1 + capacity) % capacity;
        container[front] = data;
        size++;
    }

    int getFront()
    {
        return container[front];
    }

    int getBack()
    {
        return container[getRear()];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    int getRear()
    {
        return (front + size - 1) % capacity;
    }

    void printContainer()
    {
        for_each(container, container + capacity, [](int element)
                 { cout << element << " " << endl; });
    }

    void operator delete(void *ptr)
    {
        cout << "Custom delete operator called." << std::endl;
        delete[] static_cast<char *>(ptr);
    }
};

int main(int argc, char const *argv[])
{
    system("cls");
    Dqueue dq(10);
    dq.push_back(10);
    dq.push_back(20);
    dq.pushFront(100);
    dq.pushFront(200);
    cout << dq.getBack() << "  " << dq.getFront() << endl;
    dq.printContainer();
    return 0;
}
