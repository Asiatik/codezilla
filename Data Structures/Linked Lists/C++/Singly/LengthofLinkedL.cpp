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
/*
void getCount(Node *head) //iterative method
{
    int count=0;
    Node *current=head;
    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
    cout<<count;
}
*/
int getCount(Node *head) //recursive method
{
    if(head==NULL)
    {
        return 0;
    }
    return 1+getCount(head->next);
}

int main()
{
    Node *head=NULL;
    push(&head,1);
    push(&head,3);
    push(&head,1);
    push(&head,2);
    push(&head,1);
    getCount(head); //iterative method
    cout<<getCount(head); //recursive method
}
