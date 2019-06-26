#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

int countNode(Node *n)
{
    int count=1;
    Node *temp=n;
    while(temp->next!=n)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

int countNodesinLoop(Node *list)
{
    Node *slowp=list;
    Node *fastp=list;
    while(slowp && fastp && fastp->next)
    {
        slowp=slowp->next;
        fastp=fastp->next->next;
        if(slowp==fastp)
        {
            return countNode(slowp);
        }
    }
}

Node *newNode(int data)
{
    Node *temp=new Node();
    temp->data=data;
    temp->next=NULL;
    return temp;
}

int main()
{
    Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next;
    cout<<countNodesinLoop(head);
    return 0;
}
