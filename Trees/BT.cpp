#include <iostream>
#include "BinaryTree.hpp" 

using namespace std ;
int main()
{
	// if(datatype == int)
	// cout<<argv[0]<<argv[1]<<endl;
	// typedef int 
	int Q;
	int  n;
	BinaryTree < int , int  > p  ;
	int   a,b;
	// cout<<"Enter number of integers.;";	
	// cin>>Q;
	
	cout<<"--------------------------------------"<<endl;
	cout<<"THE QUERIES NUMBER ARE AS :: "<<endl;
	cout<<"1 . Insert into tree"<<endl;
	cout<<"2 . Delete from  tree"<<endl;
	cout<<"3 . search for x in tree "<<endl;
	cout<<"4 . maximum element in tree"<<endl;
	cout<<"5 . minimum element in tree"<<endl;
	cout<<"6 . successor of x in tree "<<endl;
	cout<<"7 . predecessor of x in tree "<<endl;
	cout<<"8 . print inorder"<<endl;
	cout<<"9 . print postorder"<<endl;
	cout<<"10 . print preorder"<<endl;
	//cout<<"8 . print inorder"<<endl;
	//cout<<"8 . print inorder"<<endl;
	cout<<"11 . value corresponding to given key "<<endl;

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
					p.remove(a);
					break;

			case 3  : 
					{
						cin>>a ;
					cout<<"bool  "<<p.has(a);
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
			{ cin>>a ;cout<<"\n"<<" Value : "<<endl ;cout<<p.get(a);cout<<endl;
					break ;}
		}
	 	
	 	
	
	}
	

	//  cout<<"Enter number of queries.";
	//  cin>>Q;
	//  p.print_pre_order();
	//  cout<<endl;
	//  p.print_post_order();
	//  cout<<endl;
	//  cout<<"minimum element ::  ";
	// cout<<p.minimum()<<endl;
	// cout<<"maximum element is ::";
	// cout<<endl<<p.maximum();
	// int s;
	// cout<<endl<<"Enter the element you want its successor"<<endl;cin>>s;
	// cout<<"successor of "<<s <<"is ";
	// cout<<endl<<p.successor(s);
	// //cout<<"hell0";
	// cout<<endl<<p.predecessor(s);
	// cout<<endl;cout<<"boolean"<<endl;
	// cout<<p.has(s);
	// cout<<endl<<"Value corresponding to given key is"<<endl;
	// cout<<endl<<p.get(s);

	//cout<<"14"<<endl;
	//p.print_preorder(root);
	return 0;	
}