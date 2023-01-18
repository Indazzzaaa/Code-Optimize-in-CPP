#include <iostream>
#include <math.h>
using namespace std;

void minGroupFlip(string arr)
{

    int n = arr.length();
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] != arr[i])
        {
            if (arr[i] != arr[0])
            {
                cout << "Flip starts from : " << i;
            }
            else
            {
                cout << "\tEnds on : " << i - 1 << endl;
            }
        }
    }

    // this is the edge case , because in this last transition would not caught , think why
    if (arr[n - 1] != arr[0])
    {
        cout << "\t Ends on : " << n - 1;
    }
}

int kandane(int *arr, int n)
{
    int res = arr[0];
    int currMax = arr[0];
    for (int i = 1; i < n; i++)
    {
        currMax = max(arr[i], currMax + arr[i]);
        res = max(res, currMax);
    }
    return res;
}

int circularSubarraySum(int arr[], int n)
{
    int normalSum = kandane(arr, n);
    if (normalSum < 0)
        return normalSum;
    int arraySum = 0;
    for (int i = 0; i < n; i++)
    {
        arraySum += arr[i];
        arr[i] = -arr[i];
    }

    int nowSUm = kandane(arr, n);
    int circularSum = arraySum + nowSUm;

    return max(circularSum, normalSum);
}

int maxIndexDiff(int arr[], int n)
{
    int maxIndex;
    int maxIndexStore[N];
    maxIndexStore[n - 1] = n - 1;
    maxIndex = n - 1;
    for (int i = n - 2; i > -1;i++){
        if(arr[i] <=arr[maxIndex]){
            maxIndexStore[i] = maxIndex;
        }else{
            // no max index present
            maxIndexStore[i] = -1;
            maxIndex = i;
        }
    }
    int res = 0;
    for (int i = 0; i < n;i++){
        if(maxIndexStore[i]!=-1){
            res = max(res, maxIndexStore[i] - i);
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{

    int arr[] = {8, -8, 9, -9, 10, -11, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << circularSubarraySum(arr, n);

    return 0;
}
