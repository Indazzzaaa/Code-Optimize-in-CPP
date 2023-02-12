#include <iostream>
#include <stdlib.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

#define show(msg, x, y) cout << msg << "( " << x << "," << y << ")" << endl

void prevGreaterElement()
{
    vector<int> v = {8, 4, 12, 3, 14, 10, 12, 121, 14, 16, 18, 19, 22, 32, 1};
    stack<int> s;

    for (auto i : v)
    {

        while (s.size() > 0)
        {
            if (s.top() > i)
            {
                show("(element,greater)", i, s.top());
                s.push(i);
                break;
            }
            s.pop();
        }
        if (s.empty())
        {
            s.push(i);
            show("(element,greater)", i, -1);
            continue;
        }
    }
}

void nextGreaterElement()
{
    vector<int> v = {8, 4, 12, 3, 14, 10, 12, 121, 14, 16, 18, 19, 22, 32, 1};
    stack<int> s;

    for (auto element = v.rbegin(); element != v.rend(); element++)
    {
        int i = *element;
        while (s.size() > 0)
        {
            if (s.top() > i)
            {
                show("(element,greater)", i, s.top());
                s.push(i);
                break;
            }
            s.pop();
        }
        if (s.empty())
        {
            s.push(i);
            show("(element,greater)", i, -1);
            continue;
        }
    }

    /*  for (auto i : v.cr)
     {


     } */
}

void prevSmallerElement()
{
    vector<int> v = {8, 4, 12, 3, 14, 10, 12, 121, 14, 16, 18, 19, 22, 32, 0, 1};
    stack<int> s;
    for (auto element : v)
    {
        while (s.size() > 0)
        {
            if (s.top() < element)
            {
                show(" (element,smaller) ", element, s.top());
                s.push(element);
                break;
            }
            s.pop();
        }
        if (s.empty())
        {
            show(" (element, smaller ) ", element, -1);
            s.push(element);
        }
    }
}

void nextSmallerElement()
{
    vector<int> v = {8, 4, 12, 3, 14, 10, 12, 121, 14, 16, 18, 19, 22, 32, 0, 1};
    stack<int> s;
    for (auto i = v.rbegin(); i != v.rend(); i++)
    {
        int element = *i;
        while (s.size() > 0)
        {
            if (s.top() < element)
            {
                show(" (element,smaller) ", element, s.top());
                s.push(element);
                break;
            }
            s.pop();
        }
        if (s.empty())
        {
            show(" (element, smaller ) ", element, -1);
            s.push(element);
        }
    }
}

void stockSpanProblem()
{
    vector<int> v = {13, 15, 12, 14, 16, 8, 6, 4, 10, 30};
    stack<int> s;
    for (int i = 0; i < v.size(); i++)
    {

        while (s.size() > 0)
        {
            int topIndex = s.top();
            if (v[topIndex] < v[i])
            {
                s.pop();
            }
            else
            {
                show("(Element,span) ", v[i], i - topIndex);
                s.push(i);
                break;
            }
        }
        if (s.empty())
        {
            show("(Element,span) ", v[i], i + 1);
            s.push(i);
        }
    }
}

void printVector(vector<int> &v, string msg)
{

    cout << msg << endl;
    for_each(v.begin(), v.end(), [](int element)
             { cout << element << " "; });
    cout << endl;
}

//  ! trick is to find the area by assuming i to be the smallest
void largestHistogramArea1()
{

    vector<int> v = {2, 5, 1};
    // we are keeping track of index
    // !this is not the right way to do that,first constrain the size then assign it value
    vector<int> left_nextSmaller(v.size(), 0);
    left_nextSmaller.reserve(v.size());
    vector<int> right_nextSmaller(v.size(), 0);
    right_nextSmaller.reserve(v.size());

    show("(left_capacity,right_capacity)", left_nextSmaller.capacity(), right_nextSmaller.capacity());
    stack<int> s;

    // finding the count of smaller element left of ith
    for (int i = 0; i < v.size(); i++)
    {

        while (!s.empty() && v[i] <= v[s.top()])
        {
            s.pop();
        }

        int prevSmallerCount = s.empty() ? (i + 1) : (i - s.top());
        s.push(i);

        left_nextSmaller[i] = prevSmallerCount;
    }

    // clear the stack for reuse
    while (!s.empty())
        s.pop();
    // finding the count of smaller element right of ith
    for (int i = v.size() - 1; i > -1; i--)
    {
        while (!s.empty() && v[i] <= v[s.top()])
        {
            s.pop();
        }

        int nextSmallerCount = s.empty() ? (v.size() - i) : (s.top() - i);
        s.push(i);
        right_nextSmaller[i] = nextSmallerCount;
    }

    // let's print the both the arrays we are getting
    printVector(v, "Original array");
    printVector(left_nextSmaller, "Left next smaller array");
    printVector(right_nextSmaller, "right next smaller array");

    int res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        res = max(res, v[i] * (left_nextSmaller[i] + right_nextSmaller[i] - 1));
    }
    cout << "Result is : " << res;
}

int largestHistogramAreaOptimized(vector<int> &v)
{
    stack<int> s;
    int res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        while (!s.empty() && v[s.top()] >= v[i])
        {

            int top = s.top();
            s.pop();
            int tempRes = v[top] * (s.empty() ? i : (i - s.top() - 1));
            res = max(res, tempRes);
        }
        s.push(i);
    }

    while (!s.empty())
    {
        int tp = s.top();
        s.pop();
        int tempRes = v[tp] * (s.empty() ? v.size() : (v.size() - s.top() - 1));
        res = max(res, tempRes);
    }
    return res;
}

void testOptimizedHistogramArea()
{
    vector<int> v = {6, 2, 5, 4, 1, 5, 6};
    cout << "Largest histogram area is : " << largestHistogramAreaOptimized(v);
}

int main(int argc, char const *argv[])
{
    system("cls");
    // prevGreaterElement();
    // nextGreaterElement();
    // prevSmallerElement();
    // nextSmallerElement();
    // stockSpanProblem();
    // largestHistogramArea1();
    testOptimizedHistogramArea();

    cin.get();

    return 0;
}
