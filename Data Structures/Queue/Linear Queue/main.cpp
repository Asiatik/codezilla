#include <iostream>
using namespace std;
int frontq=0,rearq=0;
void insertq(int x[],int p)
{
    if(rearq==p)
    cout<<"Queue is full"<<endl;
    else
    {
        int e;
        cout<<"Element to insert: ";
        cin>>e;
        x[rearq++]=e;
    }
}
void deleteq()
{
    if((frontq==0 && rearq==0)|| frontq==rearq)
    cout<<"Queue is empty"<<endl;
    else
    frontq++;
}
void display(int x[],int p)
{
    if((frontq==0 && rearq==0) || frontq==rearq)
    cout<<"Queue is empty"<<endl;
    else
    {
        int i;
        for(i=frontq;i<rearq;i++)
        cout<<x[i]<<" ";
        cout<<endl;
    }
}
int main()
{
    int s,c;
    cout << "Size of queue: ";
    cin>>s;
    int q[s];
    while(1)
    {
        cout<<"1. Insert"<<endl<<"2. Delete"<<endl<<"3. Display"<<endl<<"Choice: ";
        cin>>c;
        if(c==1)
        insertq(q,s);
        else if(c==2)
        deleteq();
        else if(c==3)
        display(q,s);
        else
        return 0;
    }
    return 0;
}

