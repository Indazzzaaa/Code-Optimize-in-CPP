#include <iostream>
using namespace std;

class BIT
{
    int *container;
    int size;
    int *baseRef;

public:
    BIT(int *arr, int arrSize)
    {

        size = arrSize + 1;
        container = new int[size];
        baseRef = arr;
        for (int i = 0; i < size; i++)
        {
            container[i] = 0;
        }
        constructBIT(arrSize);
    }

        void Update(int index, int value)
    {

        int diff = value - baseRef[index];
        baseRef[index] = value;
        index = index + 1; // because in the BIT array we have index starting from 1
        while (index <= size - 1)
        {
            container[index] += diff;
            index = index + index & (-index);
        }
    }

    int getSum(int index)
    {
        int result = 0;
        index = index + 1;
        while (index > 0)
        {
            result += container[index];
            // must use the parenthesis other wise precedence rule will apply and you won't get the result as expected
            index = index - (index & (-index));
        }
        return result;
    }

    void logBST()
    {
        cout << "Printing the BST" << endl;

        for (int i = 0; i < size; i++)
        {
            cout << container[i] << " " << endl;
        }
    }

    ~BIT()
    {
        delete[] container;
        cout << "BIT memory deallocated" << endl;
    }

private:
    void constructBIT(int arrSize)
    {
        for (int i = 0; i < arrSize; i++)
        {
            constructHelper(i, baseRef[i]);
        }
    }

    void constructHelper(int i, int x)
    {
        i = i + 1;
        while (i < size)
        {
            container[i] += x;
            i = i + (i & (-i));
        }
    }
};
