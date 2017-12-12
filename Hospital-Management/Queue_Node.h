#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H
#include "Linked_List_Node.h"
using namespace std;

class queueNode
{
public:
    linkedListNode *add;
    queueNode *next;

    queueNode(linkedListNode *head)
    {
        add = head;
        next = NULL;
    }

    ~queueNode()
    {
        if(next!=NULL)
        {
            delete next;
            next = NULL;
        }
    }
};
#endif // QUEUE_NODE_H
