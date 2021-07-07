#include <iostream>
#include <string>
#include "BSTree.hpp"
// #include "BinaryTree.hpp"
#include "AVL.hpp"

using namespace std ;

int main()
{
	AVL < int , int  >   obj;
	int n,a;

	int Q;		//Number of queries.
	cout<<"--------------------------------------"<<endl;
	cout<<"THE QUERIES NUMBER ARE AS :: "<<endl;
	cout<<"1 . Insert into AVLTree"<<endl;
	cout<<"2 . Delete from  AVLTree"<<endl;
	cout<<"3 . search for x in AVLtree "<<endl;
	cout<<"4 . maximum element in AVLtree"<<endl;
	cout<<"5 . minimum element in AVLtree"<<endl;
	cout<<"6 . successor of x in AVLtree "<<endl;
	cout<<"7 . predecessor of x in AVLtree "<<endl;
	cout<<"8 . print inorder"<<endl;
	cout<<"9 . print postorder"<<endl;
	cout<<"10 . print preorder"<<endl;
	cout<<"11 . value corresponding to given key "<<endl;
	cout<<"12 . Height of AvLTree "<<endl;
	cout<<"13 . Size  of AvLtree "<<endl;

	cout<<"How many queries do you want "<<endl ;
	cin>>Q;
	cout<<endl<<"Enter the query number followed  by key if any "<<endl ;


	for(int i=0;i<Q;i++)
	{
	
		cin>>n;
		switch(n)
		{
				case 1  : 
				cin>>a; 

	obj.put(a, a);
	break ;

				case 2  : 
				cin>>a;
	obj.remove(a);
	break;

				case 3  : 
				cin>>a ;
	cout<<obj.search(a);
	break; 

				case 4  : 
				cout<<obj.maximum()<<endl;
	break ;

			case 5  : cout<<obj.minimum()<<endl;
	break ;

			case 6  : 
				cin>>a; 
	cout<<obj.successor(a)<<endl;
	break ;

			case 7  : 
				cin>>a;
	cout<<obj.predecessor(a)<<endl;
	break ;

			case 8  : 
			cout<<"\n"<<"inorder"<<endl;
	obj.print_in_order();cout<<endl;
	break ;

			case 9  : cout<<"\n"<<"postorder"<<endl;
	obj.print_post_order();cout<<endl;
	break ;

			case 10  :
			cout<<"\n"<<"preorder"<<endl ;
	obj.print_pre_order();cout<<endl;
	break ;

			case 11  :
			 cin>>a ; 
	cout<<obj.get(a);
	cout<<endl;
	break ;

			case 12  :
			cout<<obj.size();
	cout<<endl;
	break ;

			case 13  :
			cout<<obj.getheight();
	cout<<endl;
	break ;
		}
	 
	}
	return 0;

}