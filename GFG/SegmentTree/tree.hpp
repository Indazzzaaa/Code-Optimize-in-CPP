#include <iostream>
#include <vector>
using namespace std;

class SegmentTree
{

    vector<int> container;
    pair<int *, int> baseRef;
    int constructTree(int start, int end, int current)
    {
        if (start == end)
        {
            container[current] = baseRef.first[start];
            return container[current];
        }

        int mid = (start + end) / 2;
        container[current] = constructTree(start, mid, 2 * current + 1) + constructTree(mid + 1, end, 2 * current + 2);
        return container[current];
    }

    int rangeQuerryHelper(int qs, int qe, int start, int end, int current)
    {
        // cout << "Helper Ran " << endl;
        // if completely outside of the range
        if (start > qe || end < qs)
            return 0;
        // if current node is completely inside the asked querry range
        if (qs <= start && end <= qe)
            return container[current];

        int mid = (start + end) / 2;

        return rangeQuerryHelper(qs, qe, start, mid, 2 * current + 1) + rangeQuerryHelper(qs, qe, mid + 1, end, 2 * current + 2);
    }

    void updateQuerryHelper(int start, int end, int current, int &indexToUpdate, int &diff)
    {
        // if given index is completely outside of range
        if (indexToUpdate > end || indexToUpdate < start)
            return;

        container[current] = container[current] + diff;
        // * there must me two range node atleast before going for further think why?
        if (end > start)
        {

            int mid = (start + end) / 2;
            updateQuerryHelper(start, mid, 2 * current + 1, indexToUpdate, diff);
            updateQuerryHelper(mid + 1, end, 2 * current + 2, indexToUpdate, diff);
        }
    }

public:
    SegmentTree(int *arr, int size)
    {
        container.resize(4 * size, -1);
        baseRef.first = arr;
        baseRef.second = size;
        constructTree(0, size - 1, 0);
    }

    int rangeQuerry(int qStart, int qEnd)
    {
        return rangeQuerryHelper(qStart, qEnd, 0, baseRef.second - 1, 0);
    }

    // we will never touch the actual array only the segement tree array will be updated
    void updateQuerry(int index, int value)
    {
        int diff = value - baseRef.first[index];
        updateQuerryHelper(0, baseRef.second - 1, 0, index, diff);
    }

    void logTree()
    {
        for (int i = 0; i < container.size(); i++)
        {
            cout << container[i] << endl;
        }
    }
};
