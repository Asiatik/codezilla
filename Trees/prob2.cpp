#include <iostream>
#include "BinaryTree.hpp"
#include "BSTree.hpp"
#include "AVL.hpp"

using namespace std;

int main()
{
	typedef  long long datatype ;
	BSTree <  datatype, datatype> object;
	datatype n;
	datatype second_key , second_val ;
	datatype num1 , num2 ;
	
	
	cin >> n;
	datatype num ;
	for( num=1; num<=n; num++)
	{
        
        datatype val;
        cin >> val;
        object.put(num, val);
	}

	for( num =1; num<n; num++)
	{



		// for( datatype i=0;i<n;i++)
		// {
		// 	if()
		// }
		datatype variable = 0;
		second_key = object.successor(num);
		second_val = object.get(second_key);


		
		while(1)
		{
			if(second_val < object.get(num))
			{
				variable++;
			}
			if(second_key == object.maximum())
			{
				break;
			}
			second_key = object.successor(second_key);
			second_val = object.get(second_key);
		}
		
	    cout << variable << " "; 	
	}






	cout << "00"<<endl ;
}

