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

void append(Node **head,int data)
{
    Node *temp=new Node();
    temp->data=data;
    temp->next=NULL;
    Node *last=*head;
    if(*head==NULL)
    {
        *head=temp;
        return;

    }
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=temp;
}

void insertAfter(Node *preNode,int data)
{
    if(preNode==NULL)
    {
        cout<<"previous node cannot be NULL";
        return;
    }
    Node *temp=new Node();
    temp->data=data;
    temp->next=preNode->next;
    preNode->next=temp;
}
void print(Node *temp)
{
    while(temp!=NULL)
    {
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
}

int main()
{
    Node *head=NULL;
    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);
    print(head);
}


