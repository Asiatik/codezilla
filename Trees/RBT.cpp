#include <iostream>
#include "RBTree.hpp"

using namespace std ;
 
int main()
{
	RBTree <int  , int > p ;
	int a;

	int n;
	//cin >> N ;
	// for(int i=0;i<N;i++)
	// {
	// 	cin>>k>>o;
	// 	p.insert_node(k,o);
	// }
	
	// p.insert_node(23,4) ;
	// p.delete_nodes(23);
	// p.insert_node(45,7);
	// p.insert_node(67,8);
	// p.insert_node(89,9);
	// p.insert_node(125,25);
	// p.insert_node(78,78);
	// p.insert_node(6,76);
	// p.delete_nodes(89);
	// p.insert_node(819,89);
	// p.insert_node(34,89);
	// p.insert_node(134,89);
	// p.insert_node(249,89);
	// p.delete_nodes(819);
	// cout<<endl<<endl;
	// cout<<endl;
	
	//p.print();
	cout<<endl;


	int Q;		//Number of queries.
	cout<<"--------------------------------------"<<endl;
	cout<<"THE QUERIES NUMBER ARE AS :: "<<endl;
	cout<<"1 . Insert into BSTree"<<endl;
	cout<<"2 . Delete from  BSTree"<<endl;
	cout<<"3 . search for x in BStree "<<endl;
	cout<<"4 . maximum element in BStree"<<endl;
	cout<<"5 . minimum element in BStree"<<endl;
	cout<<"6 . successor of x in BStree "<<endl;
	cout<<"7 . predecessor of x in BStree "<<endl;
	cout<<"8 . print inorder"<<endl;
	cout<<"9 . print postorder"<<endl;
	cout<<"10 . print preorder"<<endl;
	cout<<"11 . value corresponding to given key "<<endl;
	cout<<"12 . Size  of BsTree "<<endl;
	cout<<"13 . Height of BsTree "<<endl;

	cout<<"How many queries do you want "<<endl ;
	cin>>Q;
	cout<<endl<<"Enter the query number followed  by key if any "<<endl ;


	for(int i=0;i<Q;i++)
	{
	
		cin>>n;
		switch(n)
		{
			case 1  : 
			cin>>a; p.insert_node(a, a);
					break ;

			case 2  : cin>>a;
					p.delete_nodes(a);
					break;

			case 3  : 
					{
						cin>>a;cout<<endl ;
					cout<<p.search(a)<<endl;
					break; }

			case 4  : cout<<endl<<p.maximum()<<endl;
					break ;

			case 5  : cout<<endl<<p.minimum()<<endl;
					break ;

			case 6  : 
				cin>>a; cout<<endl<<p.successor(a)<<endl;
					break ;

			case 7  : cin>>a;
					 cout<<endl<<p.predecessor(a)<<endl;
					break ;

			case 8  : {cout<<"\n"<<"inorder"<<endl;p.print_in_order();cout<<endl;
					break ;}

			case 9  : {cout<<"\n"<<"postorder"<<endl;p.print_post_order();cout<<endl;
					break ;}

			case 10  :
			{cout<<"\n"<<"preorder"<<endl ;p.print_pre_order();cout<<endl;
					break ;}

			case 11  :
			{ cin>>a ; cout<<"\n"<<"value : "<<endl ;cout<<p.get(a);cout<<endl;
					break ;}

			case 12  :
			{cout<<"\n"<<"Size of tree"<<endl ;cout<<p.size();cout<<endl;
					break ;}

			case 13  :
			{cout<<"\n"<<"Height of tree"<<endl ;cout<<p.getHeight();cout<<endl;
					break ;}
		}
	 	
	 	
	
	}
	
	






}