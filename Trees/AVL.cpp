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
	// cin>>n;
	// for(int i=0;i<n;i++)
	// {
	// 	cin>>k>>o;
	// 	obj.insertion(k,o);
	// }
	// // obj.insertion(20,23);
	// // obj.insertion(30,213);
	// // obj.insertion(25,23);
	// // obj.insertion(26,23);
	// // obj.insertion(27,23);
	// //     obj.insertion(35,23);
	//   //  obj.insertion(16,23);
	//   //    obj.insertion(17,23);
	//   // //  obj.print_post_order() ;
	//   //    obj.insertion(18,23);
	//   //    obj.insertion(19,23);
	//   //   obj.insertion(24,23);
	//   //  obj.insertion(27,23);
	// cout<<endl<<endl ;
	// obj.print_post_order() ;
	// cout<<endl<<endl;
	// obj.print_in_order();
	// cout<<endl<<endl;
	// obj.print_pre_order();

	// cout<<endl<<"minimum element is " <<obj.minimum()<<endl;
	// cout<<endl<<"maximum element is "<<obj.maximum()<<endl;
	// cout<<endl<<"succcessor of "<<k<<" is "<<obj.successor(k)<<endl;
	// cout<<endl<<"height of tree is "<<obj.getHeight()<<endl;
	// cout<<endl<<"size of tree is "<<obj.size()<<endl;
	// cout<<"Element to be deleted "; 
	// cin>>k;
	// obj.deletion(k);
	
	// // obj.deletion(5);
	// // obj.print_post_order();
	// // cout<<endl;
	// // obj.deletion(7);
	// cout<<"inorder"<<endl;
	// obj.print_in_order();
	// cout<<endl;
	// cout<<"post order"<<endl;
	// obj.print_post_order();
	// // obj.deletion(15);
	// // obj.deletion(14);
	// //obj.print_post_order();
	// //obj.print_post_order() ;
	// //obj.insertion(25,23);
	// //cout<<"--";
	
	// //obj.print1() ;

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
			cin>>a; obj.put(a, a);
					break ;

			case 2  : cin>>a;
					obj.remove(a);
					break;

			case 3  : 
					{
						cin>>a ;
					cout<<obj.search(a);
					break; }

			case 4  : cout<<obj.maximum()<<endl;
					break ;

			case 5  : cout<<obj.minimum()<<endl;
					break ;

			case 6  : 
				cin>>a; cout<<obj.successor(a)<<endl;
					break ;

			case 7  : cin>>a;
					 cout<<obj.predecessor(a)<<endl;
					break ;

			case 8  : {cout<<"\n"<<"inorder"<<endl;obj.print_in_order();cout<<endl;
					break ;}

			case 9  : {cout<<"\n"<<"postorder"<<endl;obj.print_post_order();cout<<endl;
					break ;}

			case 10  :
			{cout<<"\n"<<"preorder"<<endl ;obj.print_pre_order();cout<<endl;
					break ;}

			case 11  :
			{ cin>>a ; cout<<obj.get(a);cout<<endl;
					break ;}

			case 12  :
			{cout<<obj.size();cout<<endl;
					break ;}

			case 13  :
			{cout<<obj.getheight();cout<<endl;
					break ;}
		}
	 	
	 	
	
	}

	return 0;

}