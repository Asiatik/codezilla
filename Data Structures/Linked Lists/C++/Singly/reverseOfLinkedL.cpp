#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node (int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    void push(int data)
    {
        Node *temp=new Node(data);
        temp->next=head;
        head=temp;
    }

    void print()
    {
        Node *cur=head;
        while(cur!=NULL)
        {
            cout<<cur->data<<"->";
            cur=cur->next;
        }
    }

    void reverse()
    {
        Node *prev=NULL;
        Node *cur=head;
        Node *next=NULL;
        while(cur!=NULL)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        head=prev;
    }
};

int main()
{
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
    cout << "Given linked list\n";
    ll.print();
    ll.reverse();
    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}
