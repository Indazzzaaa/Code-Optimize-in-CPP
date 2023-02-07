#include <iostream>
#include <stdlib.h>
using namespace std;

struct singlyLL
{

    singlyLL *next;
    int data;
    singlyLL(int data)
    {
        this->next = NULL;
        this->data = data;
    };

    singlyLL *insertBegin(singlyLL *&head, int data)
    {
        singlyLL *temp = new singlyLL(data);
        temp->next = head;
        return temp;
    }
    singlyLL *insertEnd(singlyLL *&head, int data)
    {
        singlyLL *temp = new singlyLL(data);
        if (head == NULL)
            return temp;
        singlyLL *curr = head;
        while (curr->next != NULL)
            curr = curr->next;

        curr->next = temp;
        return head;
    }
    singlyLL *deleteFirst(singlyLL *head)
    {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
        {
            delete head;
            return NULL;
        }

        singlyLL *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    singlyLL *deleteLast(singlyLL *head)
    {
        if (head == NULL)
            return NULL;
        singlyLL *curr = head;
        while (curr->next != NULL && curr->next->next != NULL)
            curr = curr->next;

        delete curr->next;
        curr->next = NULL;
        return head;
    }

    singlyLL *insertAtPos(singlyLL *head, int data, int pos)
    {

        singlyLL *temp = new singlyLL(data);
        if (pos == 1)
        {
            temp->next = head;
            return temp;
        }

        singlyLL *curr = head;
        // ! just for the case position does not exist
        singlyLL *followPtr = NULL;
        for (int i = 1; i < pos - 1 && curr != NULL; i++)
        {
            followPtr = curr;
            curr = curr->next;
        }

        if (curr != NULL)
        {
            temp->next = curr->next;
            curr->next = temp;
        }
        else
        {
            followPtr->next = temp;
        }

        return head;
    }

    bool search(singlyLL *head, int key)
    {

        if (head == NULL)
        {
            return false;
        }

        singlyLL *curr = head;
        while (curr != NULL)
        {
            if (curr->data == key)
                return true;
            curr = curr->next;
        }

        return false;
    }

    // * Prints the LL in required way
    static void print(singlyLL *head)
    {
        if (head == NULL)
        {
            cout << "Our List is Empty  " << endl;
            return;
        }
        while (head != NULL)
        {
            cout << "[ " << head->data << " ]";
            cout << "---->";
            head = head->next;
        }
        cout << "NULL" << endl;
    }

    singlyLL *reverse(singlyLL *&head)
    {
        if (head == NULL)
            cout << "Nothing to reverse LL is Empty! " << endl;
        singlyLL *prev = NULL;
        singlyLL *curr = head;
        while (curr != NULL)
        {
            singlyLL *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // if even nodes then it will return node n/2th
    singlyLL *middleNode(singlyLL *&head)
    {
        if (head == NULL)
            return NULL;

        singlyLL *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    singlyLL *findNthFromEnd(singlyLL *&head, int n)
    {
        if (head == NULL)
            return NULL;
        singlyLL *backPtr = head, *frwdPtr = head;
        for (int i = 0; i < n && frwdPtr != NULL; i++)
        {
            frwdPtr = frwdPtr->next;
        }

        if (frwdPtr != NULL)
        {
            while (frwdPtr != NULL)
            {
                backPtr = backPtr->next;
                frwdPtr = frwdPtr->next;
            }
        }

        return backPtr;
    }

    singlyLL *reverseInGroups(singlyLL *head, int k)
    {

        bool isFirstPass = true;
        singlyLL *curr = head, *prevPtr = NULL;
        while (curr != NULL)
        {
            singlyLL *prev = NULL;
            singlyLL *currStart = curr;
            for (int i = 0; i < k && curr != NULL; i++)
            {
                singlyLL *next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            if (isFirstPass)
            {

                head = prev;
                isFirstPass = false;
            }
            else
            {
                prevPtr->next = prev;
            }
            prevPtr = currStart;
        }

        return head;
    }
    // !I have designed this algorithm assuming that loop does exist
    static void detectLoop(singlyLL *head)
    {
        if (head == NULL)
            cout << "No loop exist" << endl;

        singlyLL *slow = head, *fast = head;
        do
        {
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        slow = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        cout << "Loop found at node : " << slow->next->data << endl;

        // couting the nodes in loop
        slow = slow->next;
        fast = slow;
        int count = 0;
        do
        {
            fast = fast->next;
            count++;
        } while (fast != slow);

        cout << "Number of nodes inside the loop are : " << count << endl;
    }

    static void interSectionPoint(singlyLL *head1, singlyLL *head2)
    {
        if (head1 == NULL || head2 == NULL)
            cout << "No intersection point lies " << endl;

        // counting length of head1 and head2 nodes
        int h1count = 0, h2count = 0;
        singlyLL *curr1 = head1, *curr2 = head2;
        while (curr1 != NULL)
        {
            h1count++;
            curr1 = curr1->next;
        }
        while (curr2 != NULL)
        {
            h2count++;
            curr2 = curr2->next;
        }

        cout << "Node count in LL1,LL2 is : ( " << h1count << ", " << h2count << ") " << endl;
        // we are using head1 for longer list and head2 for smaller
        if (h1count < h2count)
        {
            swap(head1, head2);
            swap(h1count, h2count);
        }

        // increamenting the LL of head1 by h1count-h2Count
        for (int i = 0; i < h1count - h2count; i++)
        {
            head1 = head1->next;
        }

        while (head1 != head2)
        {
            head1 = head1->next;
            head2 = head2->next;
        }

        cout << "Intersection found at : " << head1->data << endl;
    }

    static singlyLL *sort(singlyLL *head)
    {
        // !checking the partition level
        // static int partition = 0;
        // partition++;
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // finding the mid of the link
        singlyLL *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // we are breaking link after slow and creating the two links
        auto temp = slow->next;
        slow->next = NULL;
        slow = temp;
        /* cout << "Partition : " << partition << endl;
        print(head);
        print(slow); */
        singlyLL *head1 = sort(head);
        singlyLL *head2 = sort(slow);
        return mergeLL(head1, head2);
    }

    static singlyLL *mergeLL(singlyLL *head1, singlyLL *head2)
    {
        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;

        singlyLL *resultHead = NULL, *resultEnd = NULL;
        while (head1 != NULL && head2 != NULL)
        {
            singlyLL *temp = NULL;
            if (head1->data > head2->data)
            {
                temp = head2;
                head2 = head2->next;
            }
            else
            {

                temp = head1;
                head1 = head1->next;
            }

            temp->next = NULL;
            if (resultHead == NULL)
            {
                resultHead = temp;
                resultEnd = temp;
            }
            else
            {
                resultEnd->next = temp;
                resultEnd = resultEnd->next;
            }
        }

        if (head1 == NULL)
        {
            resultEnd->next = head2;
        }
        else
        {
            resultEnd->next = head1;
        }

        return resultHead;
    }
};
