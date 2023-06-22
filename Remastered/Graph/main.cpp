#include <iostream>
// #include "graphList.cpp"
#include "adjacentMatrix.cpp"
#include <stdlib.h>
using namespace std;

int main(int argc, char const *argv[])
{
    system("cls");
    Graph *g = new AdjacentMatrix(5);
    g->insertEdge(0, 1, 10);
    g->insertEdge(1, 2, 15);
    g->insertEdge(2, 3, 20);
    g->insertVertex();
    // cout << *g << endl;
    g->traverseGraph();
    delete g;

    return 0;
}
