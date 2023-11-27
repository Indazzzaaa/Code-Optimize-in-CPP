// combination sum

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result;

bool isSafe(int sum, int number)
{
    return (sum - number) >= 0;
}

void sumRec(vector<int> &a, int sum, vector<int> &resultArr)
{

    if (sum == 0)
    {
        result.push_back(resultArr);
        return;
    }

    for (int i = 0; i < a.size(); i++)
    {

        if (isSafe(sum, a[i]))
        {
            resultArr.push_back(a[i]);
            sumRec(a, sum - a[i], resultArr);
            resultArr.pop_back();
        }
        else
        {
            return;
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    vector<int> resultArr;
    // Remove duplicates while preserving the sorted order
    auto last = std::unique(A.begin(), A.end());

    // Erase the duplicate elements
    A.erase(last, A.end());

    sumRec(A, B, resultArr);
    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {1, 1, 2, 2};
    auto last = std::unique(A.begin(), A.end());
    A.erase(last, A.end());
    for (auto i : A)
    {
        cout << i << endl;
    }

    return 0;
}
