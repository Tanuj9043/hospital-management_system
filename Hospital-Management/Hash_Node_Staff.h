#ifndef HASH_NODE_STAFF_H
#define HASH_NODE_STAFF_H
#include <cstring>
using namespace std;

class hashNodeStaff
{
public:
    char *name;
    char *phone;
    char *id;
    char *desig;
    int age;
    hashNodeStaff *next;

    hashNodeStaff(char *n, char *p, char *i, int d, int a)
    {
        name = new char[strlen(n)+1];
        strcpy(name, n);
        phone = new char[strlen(p)+1];
        strcpy(phone, p);
        id = new char[strlen(i)+1];
        strcpy(id, i);
        if(d==1) desig="Doctor";
        else if(d==2) desig="Nurse";
        else if(d==3) desig="Guard";
        else if(d==4) desig="Receptionist";
        else if(d==5) desig="Janitor";
        age=a;
        next=NULL;
    }

    ~hashNodeStaff()
    {
        if(next!=NULL)
        {
            delete next;
            next = NULL;
        }
        delete [] name;
        delete [] phone;
        delete [] id;
        delete desig;
    }
};
#endif // HASH_NODE_STAFF_H
