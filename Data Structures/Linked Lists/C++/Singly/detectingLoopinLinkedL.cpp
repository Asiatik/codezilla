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

int detectloop(Node *list)
{
    Node *slowp=list;
    Node *fastp=list;
    while(slowp && fastp && fastp->next)
    {
        slowp=slowp->next;
        fastp=fastp->next->next;
        if(slowp==fastp)
        {
            cout<<"found Loop";
            return 1;
        }
    }
    return 0;
}

int main()
{
    Node* head = NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
    /* Create a loop for testing */
    head->next->next->next->next = head;
    detectloop(head);

    return 0;
}
