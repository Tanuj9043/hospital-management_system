#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "Linked_List_Node.h"
#include <cstring>
using namespace std;

class linkedList
{
public:
    linkedListNode *head;
    linkedListNode *tail;

    linkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(char *c, int i)
    {
        if(head==NULL)
        {
            head = tail = new linkedListNode(c, i);
        }
        else
        {
            linkedListNode *n = new linkedListNode(c, i);
            tail->next = n;
            tail = n;
        }
    }

    void print()
    {
        if(head==NULL) return;

        linkedListNode *temp = head;
        cout << temp->place << " --> ";
        temp = temp->next;
        while(temp)
        {
            cout << temp->place << " ";
            temp = temp->next;
            if(temp!=NULL) cout << ", ";
        }
        cout << endl;
    }

    ~linkedList()
    {
        if(head!=NULL)
        {
            delete head;
            head = NULL;
        }
    }
};
#endif // LINKED_LIST_H
