#include<stdlib.h>
#include<stdio.h>
struct Node{
int data;
struct Node*next;
};
void Print(struct Node*head){
    while(head!=NULL){
        printf("%d|",head->data);
        head=head->next;
    }
}
struct Node* enterNodes(int size){
int i,data;
struct Node*head=(struct Node*)malloc(sizeof(struct Node));
printf("Enter the data at the head node:");
scanf("%d",&data);
head->data=data;
struct Node*tail=head;
    for(i=1;i<size;i++){
        struct Node*temp=(struct Node*)malloc(sizeof(struct Node));
        tail->next=temp;
        tail=tail->next;
        printf("Enter the data at %d node:",i+1);
        scanf("%d",&data);
        tail->data=data;
    }
    tail->next=NULL;
return head;
}
//Reversing Linked Lists without recursion
struct Node* reverse(struct Node*head){
struct Node* prev,*current,*next;
current=head;
prev =NULL;
while(current!=NULL){
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
}
head=prev;
return head;
};
//Revering using recursion
/*
struct Node* reverse(struct Node*prev,struct Node*current){
    struct Node*next;
    if(current==NULL){
        return prev;
    }
    if(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        return reverse(prev,current);
    }
};*/
// Alternate way(Recursion) to reverse the Linked Lists
/*struct Node*temp;
void reverse(struct Node*head){
    if(head->next==NULL){
        temp=head;
        return;
    }
    reverse(head->next);
    struct Node*prev=head->next;
    prev->next=head;
    head->next=NULL;
}
*/
int main(){
int size;
struct Node*head;
printf("Enter the size of Linked Lists:");
scanf("%d",&size);
if(size<=0){
    printf("Invalid size !");
}
else{
    head =enterNodes(size);
    printf("\n:::::::::Linked Lists:::::::::\n");
    Print(head);
    printf("\n:::::::::Reversing Linked Lists::::::::::\n");
    //Uncomment the code if reversing is done using recursion(1st Way)
    /*struct Node*current,*prev;
    current=head;
    prev=NULL;
    head=reverse(prev,current);
    */
    head =reverse(head);
    Print(head);
}
return 0;
}
