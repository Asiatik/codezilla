#include<iostream>
using namespace std;


bool isSorted(int*a ,int n)
{
    if(n==1)
    {
        return true;

    }
    if(a[0]<a[1]&& isSorted(a+1,n-1))
    {
        return true;
    }

    return false;


}
int main()
{

    int N,i,arr[10];
    cin>>N; //no_of_elements
    for(i=0; i<N; i++)
    {
        cin>>arr[i];

    }
    if(isSorted(arr,N)){
        cout<<"True";

    }
    else{
        cout<<"False";
    }
    return 0;
}
