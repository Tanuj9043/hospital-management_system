#ifndef HASH_NODE_PATIENT_H
#define HASH_NODE_PATIENT_H
using namespace std;

class hashNodePatient
{
public:
    char *name;
    char *phone;
    char *id;
    int room_No;
    int age;
    char *disease;
    hashNodePatient *next;

    hashNodePatient(char *n, char *p, char *i, int r, int a, char *d)
    {
        name = new char[strlen(n)+1];
        strcpy(name, n);
        phone = new char[strlen(p)+1];
        strcpy(phone, p);
        id = new char[strlen(i)+1];
        strcpy(id, i);
        disease = new char[strlen(d)+1];
        strcpy(disease, d);
        room_No = r;
        age = a;
        next = NULL;
    }

    ~hashNodePatient()
    {
        if(next!=NULL)
        {
            delete next;
            next = NULL;
        }
        delete [] name;
        delete [] phone;
        delete [] id;
        delete [] disease;
    }
};
#endif // HASH_NODE_PATIENT_H
