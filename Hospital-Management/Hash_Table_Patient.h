#ifndef HASH_TABLE_PATIENT_H
#define HASH_TABLE_PATIENT_H
#include "Hash_Node_Patient.h"
#include <cstring>
using namespace std;

class hashTablePatient
{
public:
    int tableSize;
    int currentSize;
    hashNodePatient **buckets;

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
        hashNodePatient **oldBuckets = buckets;
        buckets = new hashNodePatient *[tableSize];
        for(int i=0; i<tableSize; i++)
        {
            buckets[i]=NULL;
        }

        for(int i=0; i<oldTableSize; i++)
        {
            hashNodePatient *temp = oldBuckets[i];
            while(temp)
            {
                insert(temp->name, temp->phone, temp->id, temp->room_No, temp->age, temp->disease);
                temp = temp->next;
            }
            delete oldBuckets[i];
        }
        delete [] oldBuckets;
    }

    hashTablePatient()
    {
        currentSize = 0;
        tableSize = 7;
        buckets = new hashNodePatient *[tableSize];
        for(int i=0; i<tableSize; i++)
        {
            buckets[i] = NULL;
        }
    }

    void insert(char *key, char *p, char *i, int r, int a, char *d)
    {
        int z = hashFunction(key);

        hashNodePatient *node = new hashNodePatient(key, p, i, r, a, d);
        node->next = buckets[z];
        buckets[z] = node;
        currentSize++;

        float loadFactor = (float)currentSize/tableSize;
        if(loadFactor > 0.7)
        {
            reHash();
        }
    }

    hashNodePatient *find(char *key)
    {
        int i = hashFunction(key);

        hashNodePatient *temp = buckets[i];

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

        hashNodePatient *temp = buckets[i];

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
                    hashNodePatient *target = temp;
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

    void printNames()
    {
        int k=1;
        for(int i=0; i<tableSize; i++)
        {
            hashNodePatient *temp = buckets[i];
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
        hashNodePatient *temp = find(key);
        if(temp!=NULL)
        {
            cout << "Name            :   " << temp->name << endl;
            cout << "Phone           :   " << temp->phone << endl;
            cout << "ID              :   " << temp->id << endl;
            cout << "Room_No         :   " << temp->room_No << endl;
            cout << "Age             :   " << temp->age << endl;
            cout << "Disease         :   " << temp->disease << endl;
        }
        else
        {
            cout << "Person Not Found" << endl;
        }
        return;
    }

    ~hashTablePatient()
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
#endif // HASH_TABLE_PATIENT_H
