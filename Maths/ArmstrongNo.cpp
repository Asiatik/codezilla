#include <iostream.h>
int pow(int,int);
int main()
{
	int num,temp,rem,len=0;
	cout<<"Enter a no"<<endl;
	cin>>num;
	temp=num;
	while(num>0)
	{
		rem = num%10;
		num = num/10;
		len++;
	}
	num=temp;
	int sum = 0;
	while(num>0)
	{
		rem = num%10;
		sum += pow(rem,len);
		num = num/10;
	}
	if(sum==temp)
		cout<<"Its an armstrong no";
	else
		cout<<"Not an armstrong no.";
	return 0;
}

int pow(int a, int b)
{
	int res=1;
	while(b>0)
	{
		res = res*a;
		b--;
	}
	return res;
}