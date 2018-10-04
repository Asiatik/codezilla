#include<iostream>
using namespace std;

int l;
void FindLocation();
struct student{
  int data;
  student* link; 
} *start,*loc,*ptr1;

void insertion_begin(int y){
  student* temp=new student();
 temp->data=y;
 temp->link=start;
 start=temp;
}
void insertion_end(int y){
 student* temp=new student();
 temp->data=y;
 if(start==NULL){
 temp->link=NULL;
 start=temp;
}
 else{
 student* ptr=start;
 while(ptr->link!=NULL) 
 ptr=ptr->link;
 temp->link=NULL;
 ptr->link=temp;
}
}
void insertion_after(int y){
	
	student* temp=new student();
	temp->data=y;
	cout<<endl<<"enter the element after which to be inserted: ";                   
	cin>>l;
	FindLocation();
	
   		if(loc==NULL){
		  temp->link=start;
		  start=temp;
		}
     	  	else{
		  temp->link=loc->link;
		  loc->link=temp;
		}
}
void insertion_at(){
	int a,count=1,item;
	cout<<"enter the location at which data to be inserted: ";
	cin>>a;
	cout<<endl<<"enter the element to be inserted: ";
	cin>>item;
	student* temp=new student();
	student* ptr=start;
	while(ptr->link!=NULL){
	if(count==a){
	  temp->data=item;
	  temp->link=ptr->link;
	  ptr->link=temp;
   	}
	 else{
		count++;
		ptr=ptr->link;

	  }
}

}
void FindLocation(){
	 ptr1=start;
	while(ptr1!=NULL){
	if(ptr1->data==l){
	  loc=ptr1;
	  return;
	}
	else
	 ptr1=ptr1->link;
	}
   loc=NULL;
   
}
void display()
{
  student* temp=start;
  while(temp!=NULL){
  cout<<temp->data<<" ";
  temp=temp->link;
}
cout<<endl<<endl;
}
int main()
{
	start=NULL;
	int i,n,x,k,m;
	 
         while(1){
	cout<<"select from the following: "<<endl;
	cout<<"1.insertion at the beginning "<<endl;
	cout<<"2.insertion at the end"<<endl;
	cout<<"3. insertion after a given element"<<endl;
	cout<<"4.insertion at a given location"<<endl;
	cout<<"5.display the given list"<<endl;
	cout<<"6.exit"<<endl; 
	cin>>k;
	switch(k)
	{
	  case 1: cout<<endl<<"Enter the number of elements: ";
       		  cin>>n;
	   cout<<"enter the number:";
           for(i=0;i<n;i++){
            cin>>x;
            insertion_begin(x);
      }
	   break;
	  case 2: cout<<endl<<"Enter the number of elements: ";
        	  cin>>n;
	   cout<<"enter the number:";
           for(i=0;i<n;i++){
            cin>>x;
	    insertion_end(x);
	}
	   break;
	  case 3: cout<<"enter the element to be inserted: ";
		  cin>>m;
		   insertion_after(m);
	  break;
	  case 4: insertion_at();
	  break;
	  case 5: display();
	  break;
	  case 6: return(0);
	   default: cout<<"incorrect choice"<<endl;
        	 
	}	
	}
    return(0);   
}
