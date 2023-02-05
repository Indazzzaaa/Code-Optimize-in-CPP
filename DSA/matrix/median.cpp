#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

void findMedian(vector<vector<int>> &matrix)
{
    int min_val = INT_MAX, max_val = INT_MIN;
    int rowCount = matrix.size();
    int colCount = matrix[0].size();
    // extracting out the min and max value because our value will lie in between them
    for (int i = 0; i < rowCount; i++)
    {
        min_val = min(min_val, matrix[i][0]);
        max_val = max(max_val, matrix[i][colCount - 1]);
    }
    int midElementPos = (rowCount * colCount + 1) / 2;
    while (max_val > min_val)
    {
        int mid = (min_val + max_val) / 2;
        // now iterate over the row and found the position on mid element in that row
        int pos = 0;
        for (int i = 0; i < rowCount; i++)
        {
            // this will give us position of upper bound
            pos += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if (pos < midElementPos)
        {
            min_val = mid + 1;
        }
        else
        {
            max_val = mid;
        }
    }

    cout << "Middle element is : " << min_val << endl;
}

int main()
{
    vector<vector<int>> matrix = {{5, 10, 20, 30, 40}, {1, 2, 3, 4, 6}, {15, 15, 18, 19, 19}};
    findMedian(matrix);
    cin.get();
}