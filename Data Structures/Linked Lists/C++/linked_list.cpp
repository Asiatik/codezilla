#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data; //Value to be stored in the node. (You can change as per your requirements.)
    struct node * next; //Pointer that will be point to the next node linked to the current node.
};

void insert_at_beginning(struct node * head, int data)
{
    struct node * new_node = new struct node;
    new_node->data = data;
    new_node->next = NULL;
    
    if(head == NULL)
        head = new_node;
    
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

void insert_at_end(struct node * head, int data)
{
    struct node * new_node = new struct node;
    new_node->data = data;
    new_node->next = NULL;

    if(head == NULL)
    {
        head = new_node;
        return;
    }    
    
    struct node * temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    
    temp->next = new_node;
}

void insert_at(struct node * head, int position, int data)
{
    struct node * new_node = new struct node;
    new_node->data = data;
    new_node->next = NULL;

    if(head==NULL)
    {
        head = new_node;
        return;
    }    

    struct node * temp = head; //Consider head being at 1st position of the list
    
    if(position == 1)
    {
        // equivalent to insertion at the beginning
        new_node->next = head;
        head = new_node;
    }

    if(position>=2)
    {
        int moves = position - 2;
        while(moves)
        {
            temp = temp->next;
            --moves;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

vector <int> find(struct node * head, int search_element)
{
    // We will search the whole linkedlist and record all the possible positions where it is found.
    // 1-indexed list.
    vector <int> position;
    int idx=1;
    struct node * temp  = head;
    while(temp->next!=NULL)
    {
        if(temp->data == search_element)
            position.append(idx)
        ++idx;
    }
    // Check the last node of the list as it is not checked in the while loop
    if(temp->data == search_element)
        position.append(idx);
    
    return position;
}

int length(struct node* head)
{
    struct node * temp = head;
    
    if(head == NULL)
        return 0;
    else
    {
        int idx = 1;
        while(temp->next!=NULL)
        {
            temp = temp->next;
            ++idx;
        }
        return idx;    
    }
}

int isempty(struct node * head)
{
    if(head == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    struct node * head = NULL;
    return 0;
}
