#include <iostream>
#include "singly.cpp"
using namespace std;

void testLoopDetection()
{
    singlyLL *head = NULL, *end = NULL;
    for (int i = 0; i < 10; i++)
    {
        head = head->insertEnd(head, i);
    }
    singlyLL::print(head);
    end = head->findNthFromEnd(head, 1);
    end->next = head->next->next->next; // !loop on node with value =3
    singlyLL::detectLoop(head);
}

void testLLIntersection()
{

    singlyLL *h1 = NULL, *h2 = NULL, *temp = NULL;
    for (int i = 3; i < 6; i++)
    {
        h1 = h1->insertEnd(h1, (i - 3) * 10);
        h2 = h2->insertEnd(h2, (i - 4) * 100);
        temp = temp->insertEnd(temp, i);
    }
    (h1->findNthFromEnd(h1, 1))->next = temp;
    (h2->findNthFromEnd(h2, 1))->next = temp;

    singlyLL::print(temp);
    singlyLL::print(h1);
    singlyLL::print(h2);
    singlyLL::interSectionPoint(h1, h2);
}

void testMergeLL()
{
    singlyLL *h1 = NULL, *temp = NULL;
    for (int i = 3; i < 6; i++)
    {
        h1 = h1->insertEnd(h1, (i - 3) * 10);
        temp = temp->insertEnd(temp, i);
    }

    singlyLL::print(temp);
    singlyLL::print(h1);
    singlyLL::print(singlyLL::mergeLL(h1, temp));
}

void testSorting()
{
    singlyLL *head = NULL;
    for (int i = 0; i < 1000; i++)
    {
        int num = rand() % 100;
        head = head->insertEnd(head, num);
    }
    cout << "Before Sorting : " << endl;
    singlyLL::print(head);
    head = singlyLL::sort(head);
    cout << "After sorting : " << endl;
    singlyLL::print(head);
}

int main(int argc, char const *argv[])
{
    system("cls");
    // testLoopDetection();
    // testLLIntersection();
    // testMergeLL();
    testSorting();
    cin.get();
    return 0;
}
