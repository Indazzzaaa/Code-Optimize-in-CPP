#include <iostream>
#include <vector>
#include <stdlib.h>
#include <limits.h>
#include <algorithm>

using namespace std;
#define show(msg, x, y) cout << msg << "( " << x << "," << y << ")" << endl

// ! currently we are not checking for overflow or under flow condition
class stack
{
    vector<int> v;
    int min;

public:
    stack(int capacity)
    {
        v.reserve(capacity);
        min = INT_MAX;
    }

    void push(int key)
    {
        if (v.empty())
        {
            min = key;
            v.push_back(key);
            return;
        }
        if (key > min)
        {
            v.push_back(key);

            return;
        }
        int elementToInsert = 2 * key - min;
        min = key;
        v.push_back(elementToInsert);
    }

    int pop()
    {

        if (v.back() > min)
        {
            int temp = v.back();
            v.pop_back();
            return temp;
        }

        int tempRetun = min;
        min = 2 * min - v.back();
        v.pop_back();
        return tempRetun;
    }

    int getMin()
    {
        return min;
    }

    void printStack()
    {
        for_each(v.begin(), v.end(), [](int element)
                 { cout << element << "  "; });
        cout << endl;
    }
};

int main(int argc, char const *argv[])
{

    stack s(10);
    for (int i = 0; i < 5; i++)
    {
        int temp = rand() % 10;
        s.push(temp);
        show("(pushed,now_min) : ", temp, s.getMin());
    }

    cout << "Min now is : " << s.getMin() << endl;
    s.printStack();

    for (int i = 0; i < 5; i++)
    {
        int temp = s.pop();
        show("(popped,now_min) : ", temp, s.getMin());
    }

    return 0;
}
