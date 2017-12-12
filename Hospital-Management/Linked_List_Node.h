#ifndef LINKED_LIST_NODE_H
#define LINKED_LIST_NODE_H
using namespace std;

class linkedListNode
{
public:
    char *place;
    int index;
    linkedListNode* next;

    linkedListNode(char *p, int i)
    {
        place = new char[strlen(p)+1];
        strcpy(place,p);
        index = i;
        next=NULL;
    }

    ~linkedListNode()
    {
        if(next!=NULL)
        {
            delete next;
            next = NULL;
        }
        delete [] place;
    }
};
#endif // LINKED_LIST_H
