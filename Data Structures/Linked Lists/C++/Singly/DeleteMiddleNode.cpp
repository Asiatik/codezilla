#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

Node *newNode(int data)
{
    Node *temp=new Node();
    temp->data=data;
    temp->next=NULL;
    return temp;
}

void printList(Node *n)
{
    while(n!=NULL)
    {
        cout<<n->data<<"-> ";
        n=n->next;
    }
}

Node *deleteMid(Node *head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    Node *slowptr=head;
    Node *fastptr=head;
    Node *prev;
    while(fastptr!=NULL && fastptr->next!=NULL)
    {
        fastptr=fastptr->next->next;
        prev=slowptr;
        slowptr=slowptr->next;
    }
    prev->next=slowptr->next;
    delete slowptr;
    return head;

}

int main()
{
    Node *head= newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    printList(head);
    head=deleteMid(head);
    cout << "Linked List after deletion of middle\n";
    printList(head);
}
