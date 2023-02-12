#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>
using namespace std;

#define show(msg, x, y) cout << msg << "( " << x << "," << y << ")" << endl

class que
{

    int *container;
    int capacity;
    int size;
    int front;

public:
    que(int capacity)
    {
        this->capacity = capacity;
        container = new int[capacity];
        size = 0;
        front = 0;
    }

    void enque(int key)
    {
        if (isFull())
        {
            cout << "Que is full " << endl;
            return;
        }

        int rear = (getRear() + 1) % capacity;
        container[rear] = key;
        size++;

        // cout << "Key : " << key << " Front : " << front << " Size : " << size << " Rear" << rear << endl;
    }

    int deque()
    {
        if (isEmpty())
        {
            cout << "Your que is empty that's why returned the min int  " << endl;
            return INT_MIN;
        }

        int tempRes = container[front];
        front = (front + 1) % capacity;
        size--;
        return tempRes;
    }

    bool isFull()
    {
        return size == capacity;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int getRear()
    {
        return (front + size - 1) % capacity;
    }

    void print()
    {
        if (isEmpty())
        {
            cout << "Our queue is Empty , There is nothing to print : " << endl;
            return;
        }

        show("(front,rear)", front, getRear());
        cout << "Size " << size << endl;

        for_each(container, container + capacity, [](int element)
                 { cout << element << " "; });

        cout << endl;
    }
};

int main(int argc, char const *argv[])
{
    system("cls");
    que q(5);
    for (int i = 0; i < 5; i++)
    {
        q.enque(i);
    }
    q.print();

    q.deque();
    q.deque();
    q.enque(10);
    q.print();

    return 0;
}
