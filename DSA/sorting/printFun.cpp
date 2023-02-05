void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void printVector(vector<int> &v)
{
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}