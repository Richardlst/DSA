#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int value;
    Node* next;
};
Node* insert(int p, int x, Node* head)
{
    Node* newnode = new Node();
    newnode->value=x;
    newnode->next = NULL;
    if(head==NULL)
    {
        head=newnode;
        return head;
    }
    else if(p==0)
    {
        newnode->next=head;
        head=newnode;
        return head;
    }
    else
    {
        Node* head1= head;
        for(int i=0; i<p-1; i++)
        {
            head1=head1->next;
        }
        if(head1==NULL) return head;
        newnode->next=head1->next;
        head1->next=newnode;
        return head;
    }
}
Node* delete1(int p, Node* head){
    Node* head1=head;
    Node* head2=head;
    for(int i=0; i<p-1; i++){
        head1=head1->next;
        head2=head2->next;
    }
    head2=head2->next;
    if(head2==NULL) return head;
    head1->next=head2->next;
    return head;
}
int main()
{
    int n, a1,a2;
    cin>>n;
    Node* head=NULL;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(s=="insert") {
            int p, x;
            cin>>p>>x;
            head=insert(p,x,head);
        }
        else {
            int p;
            cin>>p;
            head=delete1(p,head);
        }
    }
    Node* p=head;
    while(p!=NULL)
    {
        cout<<p->value<<" ";
        p=p->next;
    }
    return 0;
}


