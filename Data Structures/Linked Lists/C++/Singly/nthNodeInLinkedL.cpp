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

void getNthNode(Node *head,int index)
{
    int count=0;
    Node *current=head;
    while(current!=NULL)
    {
        if(count==index)
        {
            cout<<current->data<<" found at index :- "<<count;
        }
        count++;
        current=current->next;
    }
}

int main()
{
    Node *head=NULL;
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);
    getNthNode(head,4);
}
