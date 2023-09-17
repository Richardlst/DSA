#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* pre;
    Node* next;
};
struct doublelinkedlist
{
    Node* tail;
    Node* head;
};
doublelinkedlist* append(doublelinkedlist* list, int data)
{
    Node* newnode= new Node();
    newnode->data= data;
    newnode->pre= list->tail;
    newnode->next=NULL;
    if(list->head==NULL)
    {
        list->head= newnode;
    }
    if(list->tail != NULL)
    {
        list->tail->next=newnode;
    }
    list->tail=newnode;
    return list;
}
int main()
{
    int n, t=0;
    cin>>n;
    int a[n];
    doublelinkedlist* ll= new doublelinkedlist();
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++)
    {
        append(ll, a[i]);
    }
    Node* p= ll->head;
    while(p!=NULL)
    {
        if(p->pre!=NULL&&p->next!=NULL&&p->pre->data+p->data+p->next->data==0) t++;
        p=p->next;
    }
    cout<<t;
    return 0;
}
