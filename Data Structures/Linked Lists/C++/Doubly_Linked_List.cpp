//Implementation of Doubly Linked List in C++.

#include <iostream>

struct node{
    int info;
    node *left,*right;
};

void display();
void insertNode(int data);
void deleteNode(int item);

node* start;
node* last;

int main(){

    int counter=1,data,item;
    start=last=NULL;

    while(counter<4 && counter>0){
        std::cout<<"1.Insert\n2.Deletion\n3.Linked List\n";
        std::cin>>counter;

        switch(counter){
            case 1:
            std::cout<<"Enter Data\n";
            std::cin>>data;

            insertNode(data);
            break;

            case 2:
            if(start==NULL){
                std::cout<<"Underflow\n";
            }

            else{
                std::cout<<"Enter Item to be Deleted\n";
                std::cin>>item;

                deleteNode(item);
            }
            break;

            case 3:
            display();
            break;

            default:
            std::cout<<"Wrong Choice\nExiting...\n";
        }
    }

    return 0;
}

void insertNode(int data){
    node* ptr=new node;
    ptr->info=data;
    ptr->left=last;
    ptr->right=NULL;

    if(start==NULL){
        start=last=ptr;
    }

    else{
        last->right=ptr;
        last=ptr;
    }
    std::cout<<"Data Inserted\n";
}

void deleteNode(int item){
    bool isFound=false;
    node* ptr=start;

    while(ptr!=NULL){
        if(ptr->info==item){
            isFound=true;
            if(ptr==start){
                start->left=NULL;
                start=start->right;
            }
            else if(ptr==last){
                ptr->left->right=NULL;
                last=last->left;
            }
            else{
                ptr->left->right=ptr->right;
                ptr->right->left=ptr->left;
            }

            delete ptr;
            std::cout<<"Item Deleted\n";
            break;
        }
        ptr=ptr->right;
    }
    
    if(!isFound){
        std::cout<<"Item Does not exist\n";
    }
}

void display(){
    node* ptr=start;

    while(ptr!=NULL){
        std::cout<<ptr->info<<"->";
        ptr=ptr->right;
    }
    std::cout<<"X\n";
}
