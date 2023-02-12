#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

//! making push costly
class stack
{

public:
    queue<int> q1, q2;
    stack()
    {
        cout << "Stack constructor is called" << endl;
        ;
    }
    void push(int key)
    {
        // first put all of q1 in q2 , then put new element in q1 and put back q2 element in q1;

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(key);
        // copy back
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int popCostly()
    {
        // push in q2 until q1 size ==1 and now pop and then put the q2 all back to q1
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int itemReturn = q1.front();
        q1.pop();
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return itemReturn;
    }

    void rpopCostly()
    {
        // first print last item;
        recPop();
        // reverse the que;
        reverseQue();
    }

    void reverseQue()
    {
        if (q1.empty())
            return;
        int data = q1.front();
        q1.pop();
        reverseQue();
        q1.push(data);
    }

    void recPop()
    {
        if (q1.empty())
            return;
        if (q1.size() == 1)
        {
            cout << "Popped : " << q1.front() << endl;
            q1.pop();
            return;
        }

        int data = q1.front();
        q1.pop();
        recPop();
        q1.push(data);
    }

    void print()
    {
        cout << "Printing the content of q1 " << endl;
        while (!q1.empty())
        {
            cout << q1.front() << endl;
            q1.pop();
        }
    }
};

void pushCostlyTest()
{
    stack s;
    for (int i = 0; i < 10; i++)
    {
        s.push(i);
    }

    s.print();
}

void popCostlyTest()
{
    stack s;
    for (int i = 0; i < 10; i++)
    {
        s.q1.push(i);
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "Popped : " << s.popCostly() << endl;
    }
}

void recPopCostlyTest()
{
    stack s;
    for (int i = 0; i < 10; i++)
    {
        s.q1.push(i);
    }

    for (int i = 0; i < 10; i++)
    {
        s.rpopCostly();
    }
}

int main(int argc, char const *argv[])
{
    recPopCostlyTest();
    return 0;
}
