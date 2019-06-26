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

void printList(Node *cur)
{
cout<<endl;
    while(cur!=NULL)
    {
        cout<<cur->data<<"->";
        cur=cur->next;
    }
    cout<<endl;
}

void printMiddle(Node *head)
{
    Node *slowptr=head;
    Node *fastptr=head;
    if(head!=NULL)
    {
        while(fastptr!=NULL && fastptr->next!=NULL)
        {
            fastptr=fastptr->next->next;
            slowptr=slowptr->next;
        }
        cout<<slowptr->data<<" is the middle element";
    }
    cout<<endl;
}

int main()
{
    Node *head=NULL;
    for(int i=5;i>0;i--)
    {
        push(&head, i);
        printList(head);
        printMiddle(head);
    }
    return 0;
}
