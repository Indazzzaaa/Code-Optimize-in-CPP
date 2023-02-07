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
        for (int i = 1; i < pos - 1 && curr != NULL, i++)
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
}