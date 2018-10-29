#ifndef AVL_HPP
#define AVL_HPP 1
#include "BSTree.hpp"
#include "BinaryTree.hpp"
template <class Key, class Value>
class AVL : public BSTree<Key, Value> {

	protected :
		using BinaryTree <Key, Value> :: root ;		

	public :
		using BinaryTree <Key , Value >  :: print_in_order ;
		using BSTree <Key , Value > :: find_height ;
		using BinaryTree <Key , Value > :: func ;
		using BinaryNode <Key , Value > :: height ;
		using BSTree <Key , Value > :: print ;
		using BSTree <Key , Value > :: insert ;
		using BinaryTree <Key , Value >  :: print_post_order ;
		using BinaryTree <Key , Value >  :: print_pre_order ;
		using BSTree <Key , Value > :: successor ;
		using BSTree <Key , Value > :: Successor_for_delete ;
		using BSTree <Key , Value > :: minimum ;
		using BSTree <Key , Value > :: maximum ;
		using BSTree <Key , Value > :: removeBST ;
		using BSTree <Key , Value > :: search ;
		using BSTree <Key , Value > :: size ;
  /*
   * Inherit as much functionality as possible from the BSTree class.
   * Then provide custom AVL Tree functionality on top of that.
   * The AVL Tree should make use of as many BST functions as possible.
   * Override only those methods which are extremely necessary.
   */
  /*
   * Apart from that, your code should have the following four functions:
   * getBalance(node) -> To get the balance at any given node;
   * doBalance(node) -> To fix the balance at the given node;
   * rightRotate(node) -> Perform a right rotation about the given node.
   * leftRotate(node) -> Perform a left rotation about the given node.
   *
   * The signature of these functions are not provided in order to provide you
   * some flexibility in how you implement the internals of your AVL Tree. But
   * make sure these functions are there.
   */




	int getheight()
	{
		//cout<<"hello";
		BinaryNode <Key , Value > * node = this->root ;
		return height_balance(this->root);
	}

	int height_balance(BinaryNode <Key , Value > *temp)
	{
		if(temp->left != NULL and temp->right != NULL)
		{
				//cout<<"temp->left->height"<<temp->left->height<<endl<<"temp->right->height"<<temp->right->height<<endl;
		 		return (1 + max(temp->left->height , temp->right->height));
		}
		 	else if(temp->left != NULL and temp->right == NULL)
		 		return (temp->left->height +1)  ;
		 	else if(temp->right == NULL and temp->left == NULL)
		 		return  0;
		 	else
		 		return (temp->right->height +1) ;
	}

	

	int getBalance(BinaryNode <Key , Value > *temp)
	{

		if(temp == NULL)
			return -1;
		else
		{
			if(temp->left == NULL and temp->right != NULL )
				return -1 - temp->right->height ;
			else if( temp->left != NULL and temp->right == NULL )	
				return temp->left->height + 1;
			else if(temp->left == NULL and temp->right == NULL)
			{
			
				return 0;
			}
			else
			return temp->left->height - temp->right->height;
		}
	}

	BinaryNode <Key , Value > * rightRotate(BinaryNode <Key , Value > *temp)
	{
		BinaryNode <Key , Value > *U = temp;
		BinaryNode <Key , Value > *X = temp->parent ;
		BinaryNode <Key , Value > *Y = temp->left ;
		temp->left = Y->right ;
		if(Y->right != NULL)
			Y->right->parent = temp;
		Y->parent = temp->parent  ;
		if(temp->parent == NULL)
			root = Y;
		else if(temp == X->right)
			X->right = Y;
		else
			temp->parent->left = Y ;
		Y->right = temp;
		temp->parent = Y ;
		temp->height = height_balance(temp);
		Y->height = height_balance(Y) ; 
		if(X!= NULL)
			X->height = height_balance(X);

		return Y;
		

	}

	BinaryNode <Key , Value > * leftRotate(BinaryNode <Key , Value > *temp)
	{
		BinaryNode <Key , Value > *X = temp->parent;
		BinaryNode <Key , Value > *Y = temp->right ;
		temp->right = Y->left ;
		if(Y->left != NULL)
			Y->left->parent = temp;
		Y->parent = temp->parent ;
		if(temp->parent == NULL)
			root = Y;
		else if(temp == temp->parent->left)
			temp->parent->left = Y;
		else 
			temp->parent->right = Y;
		Y->left = temp;
		temp->parent = Y;
		temp->height = height_balance(temp);
		Y->height = height_balance(Y);
		if(X != NULL)
			X->height = height_balance(X);
		
		return Y;



		

	}


		

	

	BinaryNode <Key , Value > * doBalance(BinaryNode <Key , Value > *ptr  , int balance)
	{
		// Left Left Case 
		if(balance > 1)
		{
			if ( getBalance(ptr->left) > 0) 
			{
				
			 	return rightRotate(ptr);
			}
			else
			{
				ptr->left =  leftRotate(ptr->left); 
				return  rightRotate(ptr); 
			}
		}
		else
		{
			if ( getBalance(ptr->left) < 0) 
			{
				
			 	return leftRotate(ptr);
			}
			else
			{
				// ptr->left =  leftRotate(ptr->left); 
				// return  rightRotate(ptr); 
				ptr->right = rightRotate(ptr->right); 
        		//cout<<ptr->right->left->key;
        	 	return leftRotate(ptr); 
			}
		}
	}		
			
			 	
		
		
    	//Right Right Case 
    	
    		// if (balance < -1 && getBalance(ptr->right) < 0) 
    		// {
    			
      //   	  return  leftRotate(ptr) ; 
    		// }
    	
    	
  
    	// Left Right Case 
    	
    		// if (balance > 1 && getBalance(ptr->left) < 0 ) 
    		// { 
    		
    			
    		// 	//return ptr;
    		// 	//ptr->left =  leftRotate(ptr->left); 
      //   		//cout<<endl;
      //   		// print_post_order();
      //   		//cout<<endl;
      //   		//cout<<"======"<<endl<<ptr->left->right->key<<" "<<ptr->left->parent->key<<" "<<ptr->left->left->key;
        		
    		// } 
    	
    	
  
    	// Right Left Case 
    	
    		// if (balance < -1 && getBalance(ptr->left) > 0) 
    		// { 
    		// 	//cout<<endl<<"128"<<endl;
        		
    		// }
    	
    	

	


/*	BinaryNode <Key , Value > * doBalance1(BinaryNode <Key ,  Value > *ptr  ,const Key& key, int balance)
	{

		//Left left case.
		if(ptr->left != NULL)
		{
			
			if (balance > 1 && key < ptr->left->key) 
			{
				cout<<endl<<" 316";
			 	//cout<<"roht";
			 	return rightRotate(ptr);
			}
			 	
			
        	  
  
		}
		
    	//Right Right Case 
    	if(ptr->right != NULL)
    	{
    		if (balance < -1 && key > ptr->right->key) 
    		{
    			
        	  return  leftRotate(ptr) ; 
    		}
    	}
    	
  
    	// Left Right Case 
    	if(ptr->left != NULL)
    	{
    		if (balance > 1 && key > ptr->left->key ) 
    	{ 
    		
    		ptr->left =  leftRotate(ptr->left); 
    		//return ptr;
    		//ptr->left =  leftRotate(ptr->left); 
        	//cout<<endl;
        	// print_post_order();
        	//cout<<endl;
        	//cout<<"======"<<endl<<ptr->left->right->key<<" "<<ptr->left->parent->key<<" "<<ptr->left->left->key;
        	return  rightRotate(ptr->left->parent); 
    	} 
    	}
    	
  
    	// Right Left Case 
    	if(ptr->right !=NULL)
    	{
    		if (balance < -1 && key < ptr->right->key) 
    		{ 
    			//cout<<endl<<"128"<<endl;
        		ptr->right = rightRotate(ptr->right); 
        		//cout<<ptr->right->left->key;
        	 	return leftRotate(ptr->right->parent); 
    		}
    	}
    	

	} */

	void help_put( const Key& key , const Value& value)
	{

		BinaryNode <Key , Value > * temp = new BinaryNode <Key , Value > ;
		temp->key = key ;
		temp->val = value ;
		BinaryNode <Key , Value > *ptr ;
		// if(ptr == NULL ) 
		// 	return  func(NULL , key,10) ;
		// else if(key < ptr->key)
		// 	return  insertion1(ptr->left , key) ;
		// else if(key > ptr->key)
		// 	return  insertion1(ptr->right , key) ;
		 //else return ptr ;         					//Equal keys cannot be allowed.
		//print_in_order();
		//cout<<"rohit";

		ptr = insert(temp) ;
		BinaryNode <Key , Value > *p=ptr;
		 // if(ptr->key == 6)
		 // 	cout<<"-+"<<ptr->parent->key<<" "<<ptr->parent->parent->key<<" "<<ptr->parent->parent->parent->key;
		//BinaryNode <Key , Value > *p = ptr;
		 while(p != NULL)
		 {
		 	//cout<<p->key;
		 	if(p->left != NULL and p->right != NULL)
		 		p->height = 1 + max(p->left->height , p->right->height);
		 	else if(p->left != NULL and p->right == NULL)
		 		p->height = p->left->height +1 ;
		 	else if(p->right == NULL and p->left == NULL)
		 		p->height = 0;
		 	else
		 		p->height = p->right->height +1 ;
		 	p= p->parent ;
		 }
		//cout<<find_height(p)<<endl;
		  while(ptr != NULL)
		  {

			if(ptr != NULL)
			{
				
				int balance = getBalance(ptr) ;
				//cout<<"balance of "<<ptr->key<< " is "<<balance<<endl; 
		  	  if(balance == 0 || balance == 1  || balance == -1 )
		  	  {
		  	  	ptr = ptr->parent ;
		  	  	continue ;
		  	  }
		 	  else 
		 	  {
		 	  	
		 	  	// if( ptr->parent != NULL and ptr == ptr->parent->left)
		 	  	// 	ptr->parent->left = doBalance(ptr , key , balance);
		 	  	// else if(ptr->parent != NULL and ptr== ptr->parent->right)
		 	  	
		 	  		ptr = doBalance(ptr   , balance);
		 	  	
		 	  	if(ptr->parent == NULL)
		 	  		root = ptr;
		 	  	
		 	  }
		 	   
		 	
			}
			else 
				break;

		  	ptr = ptr->parent ;
		
	}
}

	void put(const Key& key , const Value& value)
	{

		//cout<<"hello"<<endl;
		 help_put( key , value);
	}
	
	void help_remove(BinaryNode <Key , Value > *p ,  const Key& key)
	{

		 //BinaryNode <Key , Value > *X= root ;
		removeBST(key);
		// if(key < p->key)
		// {

		// 	help_remove( p->left , key );
		// 	return ;
		// }
		// else if(key > p->key)
		// {

		// 	 help_remove(p->right , key) ;
		// 	return ;
		// }
		// else 
		// {
		// 	cout<<"rohit";

		// 	if(p->parent != NULL)
		// 	{
		// 		if( p->left == NULL and  p->right == NULL)
		// 		{
		// 			if(p == p->parent->left)
		// 			{

		// 				p->parent->left = NULL ;
		// 				return ;
		// 				//cout<<"-p"<<p->key<<p->parent->key;
		// 			}
		// 			else
		// 			{
		// 				//cout<<"hello";
		// 				p->parent->right = NULL ;
		// 				return ;
		// 			}
		// 		}	
		// 		if(p->left == NULL || p->right != NULL)
		// 		{
		// 			if(p == p->parent->left)
		// 			{

		// 				p->parent->left = NULL ;
						
		// 			}
		// 			else
		// 				p->parent->right = p->right ;
		// 		}	
		// 		if(p->left != NULL || p->right == NULL)
		// 		{
		// 			if(p == p->parent->left)
		// 			{

		// 				p->parent->left = p->left ;
						
		// 			}
		// 			else
		// 				p->parent->right = NULL ;
		// 		}	
		// 		if(p->left != NULL and p->right != NULL)
		// 		{
		// 			cout<<"menu" ;
		// 			//cout<<"key is "key ;
		// 			//cout<<"p->key"<<p->key<<endl<<p->left->key<<endl ;
		// 			BinaryNode <Key , Value > * possible = Successor_for_delete( p , key) ;
		// 			p->key = possible->key;
		// 			p->val = possible->val;
		// 			cout<<"possible->parent->key"<<possible->parent->parent->key ;
		// 			//cout<<"p->key  "<<p->key<<"p->left "<<p->left->key<<" "<<p->right->key<<endl;
		// 			p->right = NULL ;
		// 			return ;
		// 		}

		// 	}
		// 	else
		// 	{
		// 		BinaryNode <Key , Value > * node = Successor_for_delete(this->root , key) ;
		// 		if(node != NULL)
		// 		{
		// 			root->key = node->key ;
		// 			root->val = node->val ;
		// 			help_remove(node , node->key) ;
		// 		}
		// 		else
		// 		{
		// 			if(root->left != NULL)
		// 			{
		// 				root->left = root ;
		// 				root->left->parent = NULL ;
		// 			}
		// 			else root = NULL ;
					
		// 		}
				
		// 	}
			
		// }
		// cout<<endl;
		// print_post_order();
		// cout<<endl;

		 if(p->parent !=NULL)
		  p->parent->height = height_balance(p->parent) ;
		 // if(p->key == 4 )
		 // 	cout<<endl<<p->left->height<<endl ;
		// else
		// p->parent->height = 1+max(p->left->height , p->right->height) ;
		//cout<<"p is "<<p->key;
		//p = p->parent ;
		while(p != NULL)
		{
			
			int balance =  getBalance(p);
			// if(p->key == 9)
			// cout<<"balance of key is "<<balance;
			if(balance < -1 || balance > 1)
			{
				p = doBalance(p , balance);
			}
			p= p->parent ;
		}

	}

	void remove(const Key& key )
	{
		
		help_remove(root ,key);
	}



};

#endif /* ifndef AVL_HPP */