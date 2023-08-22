#include <iostream>
using namespace std;

#define repr(x, y) "{" << x << "," << y << "}"

class DisjoinSet
{
    int *parent;
    int size;

public:
    DisjoinSet(int sizeOfArray)
    {
        size = sizeOfArray;
        parent = new int[size];
        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
        }
    }

    // purpose is to find the representative of the  subset x belong to
    // path compression
    int find(int node)
    {

        if (parent[node] == node)
            return node;

        parent[node] = find(parent[node]);
        return parent[node];
    }

    void union_do(int x, int y)
    {
        int x_rep = find(x);
        int y_rep = find(y);
        if (x_rep == y_rep)
            return;
        parent[y_rep] = x_rep;
    }

    void logContainer()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " ";
        }
        cout << endl;
        for (int i = 0; i < size; i++)
        {
            cout << parent[i] << " ";
        }
        cout << endl;
    }

    ~DisjoinSet()
    {
        delete[] parent;
        cout << "parent Memory De-allocated" << endl;
    }
};