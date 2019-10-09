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

void deleteList(Node **head)
{
    Node *current=*head;
    Node *next;
    while(current!=NULL)
    {
        next=current->next;
        free(current);
        current=next;
    }
    *head=NULL;
}

int main()
{
    Node *head=NULL;
    push(&head,1);
    push(&head,4);
    push(&head,1);
    push(&head,12);
    push(&head,1);
    deleteList(&head);
    cout<<"List Deleted"<<endl;
}
