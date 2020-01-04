 //Do Left and Right rotate given the number n and the shift-by value d
 //Number is n
 //The number of bits by which n should be rotated is given by d
 //Both rotate right and rotate left is provided
 //32 bit frame is taken

#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 32
int bit_rright(int n, int l)
{
	int a = n<<(MAX-l);
	int b = n>>l;
	return (a|b);
}
int bit_rleft(int n , int l)
{
	int a = n<<l;
	int b = n>>(MAX-l);
	return (a|b);
}

int main()
{
	int n,d;
	cin>>n>>d;
	int x=bit_rright(n,d);
	int y = bit_rleft(n,d);
	cout<<x<<" "<<y<<endl;
}
