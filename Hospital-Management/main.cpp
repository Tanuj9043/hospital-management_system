#include <iostream>
#include "Hash_Table_Staff.h"
#include "Hash_Table_Patient.h"
#include "Graph.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int d,m,y;
char hname[1000];

void display()
{
    printf("\n%45s\n%80d/%d/%d\n\n\n",hname,d,m,y);
    return;
}

void printMap(Graph &map)
{
    display();
    if(map.empty())
    {
        cout << "Map not made!!";
        return;
    }
    cout << "           Map\n\n";
    map.printAdjList();
    return;
}

void printCities(char s[][1000], int z)
{
    if(z!=1) display();
    if(s[0][0]=='\0')
    {
        cout << "Map not made!!";
        return;
    }
    cout << "           Cities On Map\n\n";
    for(int i=0; s[i][0]!='\0'; i++)
    {
        cout << i+1 << ". " << s[i] << endl;
    }
    return;
}

void makeMap(Graph &map, char s[][1000])
{
    display();
    cout << "           Map Maker\n\n";
    cout << "Enter Number of roads : ";
    int v;
    cin >> v;
    map.insertVertices(v);

    cout << "\nEnter no. of cities : ";
    int a;
    cin >> a;
    cout << "\nEnter cities name     : ";
    int i;
    for(i=0; i<a; i++) cin >> s[i];
    s[i][0]='\0';
    cout << endl;
    for(int i=0; i<a; i++)
    {
        cout << i+1 << ". " << s[i] << endl;
    }
    cout << endl;
    int x,y;
    for(int i=0; i<v; i++)
    {
        cout << "Enter edges : ";
        cin >> x >> y;
        map.add_Edge(x-1, s[x-1], y-1, s[y-1]);
    }
    return;
}

void shortestPath(Graph &map, char s[][1000])
{
    display();
    if(map.empty())
    {
        cout << "Map not made!!";
        return;
    }
    cout << "           Find Route\n\n";
    int a, b;
    printCities(s,1);
    cout << endl;
    map.printAdjList();
    cout << endl;
    cout << "Enter source and destination : ";
    cin >> a >> b;
    cout << endl;
    map.BFS(a-1,b-1);
    cout << endl;
    return;
}

void insertStaff(hashTableStaff &staff)
{
    display();
    cout << "           Insert Staff's Info\n\n";
    char name[1000];
    char phone[1000];
    char id[1000];
    int desig;
    int age;
    cout << "1. Doctor\n2. Nurse\n3. Guard\n4. Receptionist\n5. Janitor\n\n";
    cout << "Name            :   ";
    cin >> name;
    cout << "Phone           :   ";
    cin >> phone;
    cout << "ID              :   ";
    cin >> id;
    cout << "Designation     :   ";
    cin >> desig;
    cout << "Age             :   ";
    cin >> age;
    staff.insert(name, phone, id, desig, age);
    return;
}

void insertPatient(hashTablePatient &patient)
{
    display();
    cout << "           Insert Patient's Info\n\n";
    char name[1000];
    char phone[1000];
    char id[1000];
    int room_No;
    int age;
    char disease[1000];

    cout << "Name            :   ";
    cin >> name;
    cout << "Phone           :   ";
    cin >> phone;
    cout << "ID              :   ";
    cin >> id;
    cout << "Room No         :   ";
    cin >> room_No;
    cout << "Age             :   ";
    cin >> age;
    cout << "Disease         :   ";
    cin >> disease;
    patient.insert(name, phone, id, room_No, age, disease);
    return;
}

void findStaff(hashTableStaff &staff)
{
    display();
    cout << "           Find Staff\n\n";
    staff.printNames();
    char a[1000];
    cout << "\nWhich staff member's details you want? : ";
    cin >> a;
    cout << endl;
    staff.printDetails(a);
}

void findPatient(hashTablePatient &patient)
{
    display();
    cout << "           Find Patient\n\n";
    patient.printNames();
    char a[1000];
    cout << "\nWhich patient's details you want? : ";
    cin >> a;
    cout << endl;
    patient.printDetails(a);
}

void removeStaff(hashTableStaff &staff)
{
    display();
    cout << "           Remove Staff Member\n";
    staff.printNames();
    cout << "\nWhich staff member you want to remove? : ";
    char str[1000];
    cin >> str;
    staff.remove(str);
}

void removePatient(hashTablePatient &patient)
{
    display();
    cout << "           Remove Patient\n";
    patient.printNames();
    cout << "\nWhich patient member you want to remove? : ";
    char str[1000];
    cin >> str;
    patient.remove(str);
}

int main()
{
    cout << "Enter date          : ";
    cin >> ::d;
    cout << "Enter month         : ";
    cin >> ::m;
    cout << "Enter year          : ";
    cin >> ::y;
    cout << "Enter hospital name : ";
    cin.get();
    cin.getline(hname,1000);
    system("cls");

    hashTableStaff staff;
    hashTablePatient patient;
    Graph map;
    char s[1000][1000];
    s[0][0]='\0';

    int choice;
    while(1)
    {
        display();
        cout << "1.  Make MAP\n";
        cout << "2.  Display Cities\n";
        cout << "3.  Show MAP\n";
        cout << "4.  Find route\n";
        cout << "5.  Insert staff member\n";
        cout << "6.  Insert patient\n";
        cout << "7.  Find staff member\n";
        cout << "8.  Find patient\n";
        cout << "9.  Remove staff\n";
        cout << "10. Remove patient\n";
        cout << "11. Exit\n\n";
        cout << "Enter choice : ";
        cin >> choice;

        system("cls");
        switch (choice)
        {
            case 1: makeMap(map, s);
            break;
            case 2: printCities(s,0);
            break;
            case 3: printMap(map);
            break;
            case 4: shortestPath(map, s);
            break;
            case 5: insertStaff(staff);
            break;
            case 6: insertPatient(patient);
            break;
            case 7: findStaff(staff);
            break;
            case 8: findPatient(patient);
            break;
            case 9: removeStaff(staff);
            break;
            case 10: removePatient(patient);
            break;
            case 11: system("cls");
                     cout << "\n\n\n                        THANK YOU\n\n\n";
                     return 0;
            break;
            default : cout << "Wrong Input\n";
                      system("cls");
                      continue;
        }
        cout << endl << endl;
        cout << "Press enter to continue";
        cin.get();
        cin.get();
        system("cls");
    }
    return 0;
}
