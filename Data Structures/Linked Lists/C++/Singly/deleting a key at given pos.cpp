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

void deleteNode(Node **head,int pos)
{
    if(*head==NULL)
    {
        return;
    }
    Node *temp=*head;
    if(pos==0)
    {
        *head=temp->next;
        free(temp);
        return;
    }
    for(int i=0;temp!=NULL && i<pos-1;i++)
    {
        temp=temp->next;
    }
    if(temp==NULL || temp->next==NULL)
    {
        return;
    }
    Node *next=temp->next->next;
    free(temp->next);
    temp->next=next;

}

void print(Node *temp)
{
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
}
int main()
{
    Node *head=NULL;
    push(&head,7);
    push(&head,1);
    push(&head,3);
    push(&head,2);
    push(&head,8);
    print(head);
    deleteNode(&head,4);
    cout<<"After Deletion"<<endl;
    print(head);
    return 0;
}
