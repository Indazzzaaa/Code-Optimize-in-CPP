#include <iostream>
using namespace std;

// ! union by rank , but it's to implement them together union by rank and path compression
// so only having path compression and simple union will  give us constant amortized time complexity
// so use either union by rank and simple find function to get O(logn)
//  or go with path compression and we'll end up O(1) time complexity.
class DisjointSet_Optimized
{

    int *parent;
    int *rank;
    int size;

public:
    DisjointSet_Optimized(int arrSize)
    {

        size = arrSize;
        parent = new int[size];
        rank = new int[size];

        for (int i = 0; i < size; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    ~DisjointSet_Optimized()
    {
        delete[] parent;
        delete[] rank;
        cout << "container and rank space deallocated. " << endl;
    }

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
        // if both have same parent then , they are part of same subset
        if (x_rep == y_rep)
            return;

        if (rank[x_rep] > rank[y_rep])
        {
            parent[y_rep] = x_rep;
        }
        else if (rank[y_rep] > rank(x_rep))
        {
            parent[x_rep] = y_rep;
        }
        else
        {
            // case when both have the same rank , then we can pick anyone I went with x_rep and increasing it's ranko      7
            parent[x_rep] = y_rep;
            rank[x_rep]++;
        }
    }
};