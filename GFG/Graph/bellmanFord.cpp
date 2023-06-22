#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
//! we took long as the parameter so that we can accumulate INT_MAX + weight(u,v) for int it will overflow
struct triplet
{
    int src, des, weight;
};

void bellmanFord(vector<triplet> &edges, int vertexCount)
{
    vector<long> distance(vertexCount, INT_MAX);
    // reset the distance of the source
    distance[0] = 0;
    // now go for the relax all edges v-1 times
    for (int cout = 1; cout < vertexCount; cout++)
    {
        for (triplet tri : edges)
        {
            if (distance[tri.des] > distance[tri.src] + tri.weight)
            {
                distance[tri.des] = distance[tri.src] + tri.weight;
            }
        }
    }

    // print the all distances
    for (int i = 0; i < vertexCount; i++)
    {
        cout << i << " at distance :  " << distance[i] << endl;
    }

    // now checking for -ve edge cycle
    for (int count = 1; count < vertexCount; count++)
    {
        for (triplet tri : edges)
        {
            if (distance[tri.des] > distance[tri.src] + tri.weight)
            {
                cout << "Your graph have -ve edge cycle  " << endl;

                return;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // vector<triplet> edges = {{0, 1, 1}, {0, 2, 4}, {1, 2, -3}, {1, 3, 2}, {2, 3, 3}};
    // bellmanFord(edges, 4);
    vector<triplet> edges = {{0, 1, -8}, {1, 2, 3}, {2, 0, 1}};
    bellmanFord(edges, 3);

    return 0;
}
