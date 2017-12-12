#ifndef GRAPH_H
#define GRAPH_H
#include "Linked_List.h"
#include "Queue.h"
#include <cstring>
using namespace std;

class Graph
{
public:
    int V;
    linkedList *adjList;

    Graph()
    {

    }

    Graph(int v)
    {
        V = v;
        adjList = new linkedList[V];
    }

    bool empty()
    {
        return adjList[0].head==NULL ? true : false;
    }

    void insertVertices(int v)
    {
        V = v;
        adjList = new linkedList[V];
    }

    void add_Edge(int a, char *src, int b, char *dest)
    {
        if(adjList[a].head==NULL)
        {
            adjList[a].insertAtEnd(src, a);
        }
        if(adjList[b].head==NULL)
        {
            adjList[b].insertAtEnd(dest, b);
        }
        adjList[a].insertAtEnd(dest, b);
        adjList[b].insertAtEnd(src, a);
    }

    void BFS(int a, int b)
    {
        if(adjList[a].head==NULL || adjList[b].head==NULL)
        {
            cout << "Wrong INPUT!!";
        }
        int *dist = new int[V];
        int *parent = new int[V];
        for(int i=0; i<V; i++)
        {
            dist[i] = INT_MAX;
            parent[i] = -1;//this parent will be from shortest path
        }

        Queue q;
        q.push(adjList[a].head);
        dist[adjList[a].head->index] = 0;

        while(!q.empty())
        {
            queueNode *f = q.left();
            q.pop();

            linkedListNode *start = f->add;
            linkedListNode *temp = start;
            while(temp)
            {
                if(dist[temp->index]==INT_MAX)
                {
                    q.push(adjList[temp->index].head);
                    dist[temp->index] = dist[start->index] + 1;
                    parent[temp->index] = start->index;
                }
                temp = temp->next;
            }
        }

        cout << "\n\nDistance between " << adjList[a].head->place << " and " << adjList[b].head->place << " is " << dist[adjList[b].head->index] << endl << endl;
        int start = b;
        while(start!=a)
        {
            cout << adjList[start].head->place << " <-- ";
            start = parent[start];
        }
        cout << adjList[start].head->place;
    }

    void printAdjList()
    {
        for(int i=0; i<V; i++)
        {
            adjList[i].print();
        }
    }
};
#endif // GRAPH_H
