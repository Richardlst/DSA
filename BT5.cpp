#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int value){
        data=value;
        next=NULL;
    }
};
struct Stack{
    Node* top=NULL;
    Stack(){
        top= NULL;
    }
bool isempty(){
return (top==NULL);
}
void push(int value){
    Node* newnode=new Node(value);
    newnode->next=top;
    top=newnode;
}
void pop(){
    if(isempty()) return;
    else{
        Node* temp=top;
        top=top->next;
        delete temp;
    }
}
};
int main(){
    int n;
    Stack stack;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        if(s=="push"){
            int x; cin>>x;
            stack.push(x);
        }
        else {
            stack.pop();
        }
    }
    Node* p = stack.top;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
return 0;
}
