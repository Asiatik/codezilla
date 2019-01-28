/* 
  P.Kishore
  Segment- Tree Implementation 
          Version 1: Range minimum query with point updates
*/

#include<bits/stdc++.h>
using namespace std;
const int max_size=100005;
int arr[max_size],seg[4*max_size];

// Initially building the tree with the given array arr

void build(int low,int high,int pos)
{
  if(low==high)
  {
   seg[pos]=arr[low];
   return;
  }
  
  int mid=(low+high)/2;

  build(low,mid,2*pos+1);

  build(mid+1,high,2*pos+2);
  
  seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}


// Updating some position in array (ie: arr[index]=value)

void update(int low,int high,int pos,int index,int value)
{
  if(low==high)
  {
    arr[index]=value;
    seg[pos]=arr[index];
    return; 
  }
  
  int mid=(low+high)/2;

  if(index<=mid)
  	update(low,mid,2*pos+1,index,value);
  else
  	update(mid+1,high,2*pos+2,index,value);
  
  seg[pos]=min(seg[2*pos+1],seg[2*pos+2]);
}


// QUERY - Returns minimum in the range arr[qlow,qhigh]

int query(int low,int high,int pos,int qlow,int qhigh)
{
  if(high<qlow || qhigh<low) // Out of range
  	return INT_MAX;
  
  else if(qlow<=low && high<=qhigh) // Completely within range
  	return seg[pos];

  int mid=(low+high)/2;

  int q1=query(low,mid,2*pos+1,qlow,qhigh);
  int q2=query(mid+1,high,2*pos+2,qlow,qhigh);
  
  return min(q1,q2);
}

int main()
{
  cout<<"Enter the number of elements \n";
  int n;
  cin>>n;
  int i;

  for(i=0;i<n;i++)
  	cin>>arr[i];

  build(0,n-1,0);

  cout<<"Enter the total number of updates and queries\n";

  int m;

  cin>>m;

  cout<<"Enter them in the form\n";
  cout<<"For Update : 1 index value\n";
  cout<<"For query  : 2 left right\n";

 
  int type,L,R,index,value;

 for(i=0;i<m;i++)
 {
   cin>>type;

   if(type==1)
   {
     cin>>index>>value;
     update(0,n-1,0,index,value);	
   }
   
   else
   {
   	cin>>L>>R;  
   	cout<<query(0,n-1,0,L,R)<<endl;
   }

 }
   
 return 0;	
}