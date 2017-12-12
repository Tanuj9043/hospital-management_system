#ifndef HASH_TABLE_STAFF_H
#define HASH_TABLE_STAFF_H
#include "Hash_Node_Staff.h"
#include <cstring>
using namespace std;

class hashTableStaff
{
public:
    int tableSize;
    int currentSize;
    hashNodeStaff **buckets;

    int hashFunction(char *key)
    {
        int ans = 0;
        int currentPower = 1;
        int len = strlen(key);

        for(int i=0; i<len; i++)
        {
            ans += currentPower*key[len-i-1];
            currentPower *= 37;
            currentPower %= tableSize;
            ans %= tableSize;
        }
        return ans;
    }

    void reHash()
    {
        int oldTableSize = tableSize;
        tableSize *= 2;
        currentSize = 0;
        hashNodeStaff **oldBuckets = buckets;
        buckets = new hashNodeStaff *[tableSize];
        for(int i=0; i<tableSize; i++)
        {
            buckets[i]=NULL;
        }

        for(int i=0; i<oldTableSize; i++)
        {
            hashNodeStaff *temp = oldBuckets[i];
            while(temp)
            {
                int d = findDesigNumber(temp);
                insert(temp->name, temp->phone, temp->id, d, temp->age);
                temp = temp->next;
            }
            delete oldBuckets[i];
        }
        delete [] oldBuckets;
    }

    hashTableStaff()
    {
        currentSize = 0;
        tableSize = 7;
        buckets = new hashNodeStaff *[tableSize];
        for(int i=0; i<tableSize; i++)
        {
            buckets[i] = NULL;
        }
    }

    void insert(char *key, char *p, char *i, int d, int a)
    {
        int z = hashFunction(key);

        hashNodeStaff *node = new hashNodeStaff(key, p, i, d, a);
        node->next = buckets[z];
        buckets[z] = node;
        currentSize++;

        float loadFactor = (float)currentSize/tableSize;
        if(loadFactor > 0.7)
        {
            reHash();
        }
    }

    hashNodeStaff *find(char *key)
    {
        int i = hashFunction(key);

        hashNodeStaff *temp = buckets[i];

        while(temp)
        {
            if(strcmp(key, temp->name)==0)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void remove(char *key)
    {
        int i = hashFunction(key);

        hashNodeStaff *temp = buckets[i];

        if(strcmp(key,buckets[i]->name)==0)
        {
            buckets[i] = buckets[i]->next;
            temp->next=NULL;
            delete temp;
        }
        else
        {
            while(temp)
            {
                if(strcmp(key, buckets[i]->name)==0)
                {
                    hashNodeStaff *target = temp;
                    target = target->next;
                    temp->next = target->next;
                    delete target;
                    target = NULL;
                    return;
                }
                temp = temp->next;
            }
        }
    }

    int findDesigNumber(hashNodeStaff *node)
    {
        int ans=-1;
        if(strcmp(node->desig,"Doctor")==0) ans=1;
        else if(strcmp(node->desig,"Nurse")==0) ans=2;
        else if(strcmp(node->desig,"Guard")==0) ans=3;
        else if(strcmp(node->desig,"Receptionist")==0) ans=4;
        else if(strcmp(node->desig,"Janitor")==0) ans=5;
        return ans;
    }

    void printNames()
    {
        int k=1;
        for(int i=0; i<tableSize; i++)
        {
            hashNodeStaff *temp = buckets[i];
            while(temp)
            {
                cout << k << ". " << temp->name << endl;
                temp = temp->next;
                k++;
            }
        }
    }

    void printDetails(char *key)
    {
        hashNodeStaff *temp = find(key);
        if(temp!=NULL)
        {
            cout << "Name            :   " << temp->name << endl;
            cout << "Phone           :   " << temp->phone << endl;
            cout << "ID              :   " << temp->id << endl;
            cout << "Designation     :   " << temp->desig << endl;
            cout << "Age             :   " << temp->age << endl;
        }
        else
        {
            cout << "Person Not Found" << endl;
        }
        return;
    }

    ~hashTableStaff()
    {
        for(int i=0; i<tableSize; i++)
        {
            if(buckets[i]!=NULL)
            {
                delete buckets[i];
            }
        }
        delete [] buckets;
    }
};
#endif // HASH_TABLE_STAFF_H
