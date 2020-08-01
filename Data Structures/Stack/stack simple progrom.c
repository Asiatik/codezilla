#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 10
int st[max],top=-1,item,i;
void push();
void pop();
void display();
void main()

 {
     int ch;
     while(1)
     {
         printf("\n1.\tFor push AN Elememt\n");
         printf("2.\tFor pop and element \n");
         printf("3.\tFor Display An Element\n");
         printf("4. \tFor Exit from prrogram\n");

         printf("\n ENTER YOUR CHOICE\n");
         scanf("%d",&ch);
         switch(ch)
         {
         case 1:
            push();
            break;
         case 2:
             pop();
             break;
         case 3:
             display();
             break;
         case 4:
            exit(0);
         default:
            printf("\nInvalid Input\n");
         }
     }
 }

 void push()
 {
     if(top==max-1)
     {
         printf("\n Stack Is overflow\n");
     }
     else
     {
         printf("\n enter the number wants to push\n");
         scanf("%d",&item);

         top++;
         st[top]=item;
     }
 }

 void pop()
 {
     if(top==-1)
     {
         printf("\n stack is underflow\n");

     }
     else
     {

        printf("\n Top item is %d which Deleted from stack",st[top]);
     top--;
     }
 }

 void display()
 {
    if(top>-1)
    {

        printf("\n Stack\n");
     for(i=top;i>-1;i--)
      printf("\n %d",st[i]);
    }
     else
        {
            printf("\n stack is empty");

        }
 }
