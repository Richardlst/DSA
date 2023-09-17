#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int value)
    {
        data=value;
        next=NULL;
    }
};
struct Queue
{
    Node* first=NULL;
    Node* rear=NULL;
    Queue()
    {
        first=NULL;
        rear=NULL;
    }
    bool isempty()
    {
        return (first==NULL);
    }
    void enqueue(int data)
    {
        Node* newnode= new Node(data);
        if(isempty()) first=rear=newnode;
        rear->next=newnode;
        rear=newnode;
    }
    void dequeue()
    {
        if(isempty()) return;
        Node* temp= first;
        first=first->next;
        delete temp;
    }
};
int main()
{
    int n;
    cin>>n;
    Queue myqueue;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        if(s=="enqueue")
        {
            int x;
            cin>>x;
            myqueue.enqueue(x);
        }
        else
        {
            myqueue.dequeue();
        }
    }
    Node* p= myqueue.first;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    return 0;
}
