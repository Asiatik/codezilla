//Program to Calculate String Length in C
#include<stdio.h>

int main(){
  int i=0;
  char given_string[]="hello";
  
  //Loop till end of the String encountered
  while(given_string[i]!='\0')
    i++;
  //Printing Result
  printf("\n String Length : %d \n",i);
  return 0;
}
