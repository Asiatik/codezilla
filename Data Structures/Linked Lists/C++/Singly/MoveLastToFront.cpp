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
    while(cur!=NULL)
    {
        cout<<cur->data<<"->";
        cur=cur->next;
    }
    cout<<endl;
}

void moveToFront(Node **head)
{
    if(*head==NULL  || (*head)->next==NULL)
    {
        return;
    }
    Node *secLast=NULL;
    Node *last=*head;
    while(last->next!=NULL)
    {
        secLast=last;
        last=last->next;
    }
    secLast->next=NULL;
    last->next=*head;
    *head=last;

}

int main()
{
    Node *start=NULL;
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
    printList(start);
    moveToFront(&start);
    printList(start);
    return 0;
}
