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
bool searchElement(Node *head,int value) //iterative method
{
    Node *current=head;
    while(current!=NULL)
    {
        if(current->data==value)
        {
            return true;
        }
        current=current->next;
    }
    return false;
}
*/

bool searchElement(Node *head,int value) //recursive method
{
    if(head==NULL)
    {
        return false;
    }
    if(head->data==value)
    {
        return true;
    }
    return (searchElement(head->next,value));

}


int main()
{
    Node *head=NULL;
    push(&head,10);
    push(&head,30);
    push(&head,11);
    push(&head,21);
    push(&head,14);
    searchElement(head,11)?cout<<"yes":cout<<"no";

}
