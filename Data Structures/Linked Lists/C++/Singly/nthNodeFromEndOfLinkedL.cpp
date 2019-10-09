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
void printNthFromLast(Node *head,int n) //length method
{
    Node *temp=head;
    int len=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        len++;
    }
    if(len<n)
    {
        return;
    }
    temp=head;
    for(int i=1;i<len-n+1;i++)
    {
        temp=temp->next;
    }
    cout<<temp->data;
    return;
}
*/

void printNthFromLast(Node *head,int n) //2 pointer method
{
    Node *refptr=head;
    Node *mainptr=head;
    int count=0;
    if(head!=NULL)
    {
        while(count<n)
        {
            if(refptr==NULL)
            {
                cout<<n<<" is greater than no. of nodes in list";
                return;
            }
            refptr=refptr->next;
            count++;
        }
        while(refptr!=NULL)
        {
            refptr=refptr->next;
            mainptr=mainptr->next;
        }
        cout<<mainptr->data;
    }
}


int main()
{
    Node *head=NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);
    printNthFromLast(head, 4);
}
