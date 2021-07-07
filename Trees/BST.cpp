#include <iostream>
#include <string>
#include "BSTree.hpp"
#include "BinaryTree.hpp"

using namespace std;

int main()
{

	BSTree <int , int > p;
	int n;
	// cin>>n;
	int a, b;
	// for(int i=0 ;i <n ;i++)
	// {
	// 	cin>>a>>b;
	// 	obj.function(a,b);
	// }
	// cout<<"inorder"<<endl;
	// obj.print_in_order();
	// cout<<"pre order"<<endl;
	// obj.print_pre_order();
	// cout<<"post order"<<endl;
	// obj.print_post_order();
	// cout<<"minimum element is -:"<<endl;
	// cout<<obj.MINIMUM();
	// cout<<"maximum element is :-"<<endl;
	// cout<<obj.MAXIMUM();
	// int s;
	// cout<<"Enter the element of which you want to find successor"<<endl;
	// cin>>s;
	// cout<<"successor is "<<endl;
	// cout<<obj.successor(s);

	// cout<<"precessor is "<<endl;
	// cout<<obj.predecessor(s);
	// cout<<endl<<"Height of Tree "<<endl;
	// cout<<obj.getHeight();
	// int deleted ;
	// cout<<"Element that you want to delete"<<endl;
	// cin>>deleted;
	// obj.delete_node(deleted);
	// cout<<"After deletion"<<endl;
	// obj.print_in_order();
	// cout<<endl<<"total number of elements in tree is :"<<endl;
	// cout<<obj.size();
	// obj.insert(root,13,2);
	//BinaryNode <int  ,int > *r=obj.MINIMUM(*root);
	//cout<<r->key;

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
			cin>>a; p.put(a, a);
					break ;

			case 2  : cin>>a;
					p.removeBST(a);
					break;

			case 3  : 
					{
						cin>>a ;
					cout<<"bool  "<<p.search(a)<<endl;
					break; }

			case 4  : cout<<"maximum:  "<<p.maximum()<<endl;
					break ;

			case 5  : cout<<"minimum:  "<<p.minimum()<<endl;
					break ;

			case 6  : 
				cin>>a; cout<<"successor : "<<p.successor(a)<<endl;
					break ;

			case 7  : cin>>a;
					 cout<<"predecessor : "<<p.predecessor(a)<<endl;
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