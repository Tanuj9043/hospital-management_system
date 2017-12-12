#ifndef QUEUE_H
#define QUEUE_H
#include "Queue_Node.h"
using namespace std;

class Queue
{
public:
    queueNode *front;
    queueNode *rear;

    Queue()
    {
        front = NULL;
    }

    void push(linkedListNode *node)
    {
        if(front==NULL)
        {
            front = rear = new queueNode(node);
        }
        else
        {
            queueNode *temp = new queueNode(node);
            rear->next = temp;
            rear = temp;
        }
    }

    void pop()
    {
        if(front==NULL)
        {
            return;
        }
        else if(front==rear && front!=NULL)
        {
            delete front;
            delete rear;
            front = rear = NULL;
        }
        else
        {
            queueNode *temp = front;
            front = front->next;
            temp->next = NULL;
            delete temp;
        }
    }

    queueNode *left()
    {
        if(front!=NULL) return front;
    }

    bool empty()
    {
        return front==NULL ? true : false;
    }

    ~Queue()
    {
        if(front!=NULL)
        {
            delete front;
            front = NULL;
        }
        delete rear;
    }
};
#endif // QUEUE_H
