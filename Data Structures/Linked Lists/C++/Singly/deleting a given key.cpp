#include<iostream>
using namespace std;
struct Node
{
int data;
Node *next;
};

void push(Node **head,int data)
{
    Node *temp=new Node();
    temp->data=data;
    temp->next=*head;
    *head=temp;
}

void deleteNode(Node **head,int key)
{
    Node *temp=*head;
    Node *pre=new Node();
    if(temp!=NULL && temp->data==key)
    {
        *head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key)
    {
        pre=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        return;
    }

    pre->next=temp->next;
    free(temp);
}

void print(Node *temp)
{
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
int main()
{
    Node *head=NULL;
    push(&head,7);
    push(&head,1);
    push(&head,3);
    push(&head,2);
    print(head);
    deleteNode(&head,3);
    cout<<endl<<"After deletion"<<endl;
    print(head);
}
