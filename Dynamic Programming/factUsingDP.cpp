#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number whose factorial you want:-"<<endl;
    cin>>n;
    int arr[n];
    arr[0] = 1;

    for( int i = 1; i < n; i++)
        arr[i] = (i+1)*arr[i-1];
    cout<<"Factorial of "<<n<<" is: "<<arr[n-1]<<endl;
    return 0;
}
