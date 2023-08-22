#include "dj_set.hpp"

int main(int argc, char const *argv[])
{
    int size = 6;
    DisjoinSet djSet = DisjoinSet(size);
    djSet.union_do(0, 1);
    djSet.union_do(2, 3);
    djSet.union_do(4, 5);

    djSet.logContainer();
    cout << endl
         << endl;

    djSet.union_do(0, 2);
    djSet.logContainer();
    cout << endl
         << endl;
    djSet.union_do(3, 5);
    djSet.logContainer();

    return 0;
}
