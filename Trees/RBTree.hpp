#ifndef RBTree_HPP_
#define RBTree_HPP_ 1
#include "BSTree.hpp"
/* The color enumeration.
 * Please use this and not integers or characters to store the color of the node
 * in your red black tree.
 * Also create a class RBTNode which should inherit from BinaryNode and has the attribute color in it. 
 */

#define clr(x) (((RBTNode <Key , Value > *)x)->color1)
#define node_ptr BinaryNode <Key ,Value >*
enum color { RED, BLACK } ;

template <class Key, class Value>
class RBTNode  : public BinaryNode < Key , Value >
{
public : 
	 color color1 ; 
	
RBTNode() : BinaryNode<Key ,Value >()
{
	color1 = RED  ;
}

RBTNode( Key key ,Value  val ) : BinaryNode <Key , Value > (key , val)
{
	color1 = RED ;
}

};


template <class Key, class Value>
class RBTree : public BSTree<Key, Value> {


protected :

RBTNode <Key , Value > *nil ;
//node_ptr root  = NULL;
/* Inherit as many functions as possible from BSTree.
 * Only override those which absolutely need it.
 * Also make sure that all inherited functions work correctly in the context of a red black tree.
 * node_ptr in the following piece of code refers to a pointer to the node you may be using for your red black tree.
 * Use a typedef to refer to a pointer to your node via node_ptr
 */

	/* Function insertRBFixup
	 *
	 * Used for:
	 * Used after an insertion in the rb tree.
	 * It applies fixing mechanisms to make sure that the tree remains a valid red black tree after an insertion.
	 */
	void insertRBFixup(node_ptr root) ;

/* Function deleteRBFixup
	 * Used for:
	 * Used after a deletion in the rb tree.
	 * It applies fixing mechanisms to make sure that the tree remains a valid red black tree after a deletion.
	 */

	void RBTransplant(node_ptr u, node_ptr v);


	void deleteRBFixup(node_ptr root);


	 node_ptr mini1( node_ptr x)
  {
     
      while(x->left!= nil)
      {
          x= x->left;
      }
      return x ;
  }

	
	void RBDelete(node_ptr Z)
	{
		node_ptr x ;
		node_ptr y = Z ;
		color y_orignal_color = clr(y);


		if(Z->left == nil )
		{
			x = Z->right ;
			RBTransplant(Z, Z->right);
		}
		else if(Z->right == nil )
		{
			x = Z->left ;
			RBTransplant(Z, Z->left);
		}
		else
		{
			y = mini1(Z->right);
			y_orignal_color = clr(y) ;
			x = y->right ;
			if(y->parent == Z)
				x->parent =y;
			else 
			{
				RBTransplant(y,y->right );
				y->right = Z->right ;
				y->right->parent = y ;
			}
			RBTransplant(Z,y);
			y->left = Z->left ;
			y->left->parent = y;
			clr(y) = clr(Z) ;

		}
		if(y_orignal_color == BLACK)
			deleteRBFixup(x) ;

	}
	
	
public :

	// using BSTree <Key , Value > :: min ;
	// using BSTree <Key , Value > :: return_node_of_key ;
	// using BinaryTree<Key , Value > :: print_in_order ;
	// using BSTree <Key , Value > :: MINIMUM ;
	// using BSTree <Key , Value > :: successor ;
	/* Function : blackHeight
	 * 
	 * Returns:
	 * the black height of the red black tree which begins at node_ptr root
	 */
	RBTree()
	{
		nil = new RBTNode <Key , Value > ;
		nil->left = NULL;
		nil->right = NULL;
		clr(nil) = BLACK ;
		nil->parent = NULL;
		this->root = nil;
	}

	node_ptr return_node_of_key(const Key& key ,  node_ptr temp )
  {
      
      if(temp->key == key)
        return temp;
      else if(key > temp->key)
          return_node_of_key(key , temp->right);
      else
          return_node_of_key(key , temp->left);
        
        
  }


	void delete_nodes(const Key& key)
	{
		node_ptr temp = return_node_of_key(key , this->root) ;
		//cout<<"node of key"<<temp->key;
		RBDelete(temp);

	}

	
	int blackHeight(node_ptr root)
	{
		node_ptr node = root ;
		int num = 0;
		while(node)
		{
			if( (clr(node)) == BLACK)
				num++ ;
			node = node->left ;
		}
		return num ;
	}
	/*
	 * Apart from these functions, also provide functions for rotations in the tree.
	 * The signature of the rotation functions is omitted to provide you flexibility in how you implement the internals of your node.
	 */

	node_ptr  leftRotate(node_ptr temp)
	{
		node_ptr X = temp->parent;
		node_ptr Y = temp->right ;
		temp->right = Y->left ;
		if(Y->left != nil)
			Y->left->parent = temp;
		Y->parent = temp->parent ;
		if(temp->parent == nil)
			this->root = Y;
		else if(temp == temp->parent->left)
			temp->parent->left = Y;
		else 
			temp->parent->right = Y;
		Y->left = temp;
		temp->parent = Y;
		
		return Y ;
	}

	BinaryNode <Key , Value > * rightRotate(BinaryNode <Key , Value > *temp)
	{
		BinaryNode <Key , Value > *U = temp;
		BinaryNode <Key , Value > *X = temp->parent ;
		BinaryNode <Key , Value > *Y = temp->left ;
		temp->left = Y->right ;
		if(Y->right != nil)
			Y->right->parent = temp;
		Y->parent = temp->parent  ;
		if(temp->parent == nil)
			this->root = Y;
		else if(temp == X->right)
			X->right = Y;
		else
			temp->parent->left = Y ;
		Y->right = temp;
		temp->parent = Y ;
		// temp->height = height_balance(temp);
		// Y->height = height_balance(Y) ; 
		// if(X!= NULL)
		// 	X->height = height_balance(X);

		return Y;
		

	}



	void insert_node(const Key& key , const Value& value);
	void insertRB(node_ptr root );

	void help_print_in_order(node_ptr temp)
	{
		if(temp == nil)
		return ;	
		
		help_print_in_order(temp->left);
		cout<<temp->key<<" "<<temp->val<<endl;
		help_print_in_order(temp->right );
	}
	void print_in_order()
	{
		//BinaryNode <Key , Value > * minim = mini1(this->root);
		//cout<<endl<<"minim is :"<<minim->key;
		help_print_in_order(this->root);
		//cout<<this->root->key<<clr(this->root);
	}

	void help_print_pre_order(node_ptr temp)
	{
		if(temp == nil)
		return ;	
		cout<<temp->key<<" "<<temp->val<<endl;
		help_print_pre_order(temp->left);
		help_print_pre_order(temp->right );
	}
	void print_pre_order()
	{
		//BinaryNode <Key , Value > * minim = mini1(this->root);
		//cout<<endl<<"minim is :"<<minim->key;
		help_print_pre_order(this->root);
		//cout<<this->root->key<<clr(this->root);
	}

	void help_print_post_order(node_ptr temp)
	{
		if(temp == nil)
		return ;	
		
		help_print_post_order(temp->left);
		help_print_post_order(temp->right );
		cout<<temp->key<<" "<<temp->val<<" "<<endl;
	}
	void print_post_order()
	{
		//BinaryNode <Key , Value > * minim = mini1(this->root);
		//cout<<endl<<"minim is :"<<minim->key;
		help_print_post_order(this->root);
		//cout<<this->root->key<<clr(this->root);
	}

	virtual  Key  minimum()
  {

    BinaryNode <Key , Value > *x = this->root;
    
      while(x->left!= nil)
      {
          x= x->left;
      }
      // cout<<"goo\n"<<x->key<<endl;
      return x->key;
  }

  virtual Key maximum()
  {
    BinaryNode <Key , Value > *x = this->root;
      while(x->right!= nil)
      {
          x= x->right;
      }
      return x->key;
  }

   virtual BinaryNode<Key , Value > * min(BinaryNode <Key , Value > *x)
  {
     
      while(x->left!= nil)
      {
          x= x->left;
      }
      return x ;
  }



   virtual Key  successor(const Key& key)
  {
      
      Key k =  maximum();
      //cout<<"key si"<<k<<" "<<key<<"\n" ;
      if(k <= key)
      {
        cout<<endl<<"Cannot find the successor of given key since maximum element is ";
        return k;
      }
      else
      {
        BinaryNode <Key , Value > *ptr = return_node_of_key(key , this->root);
      //cout<<endl<<ptr->key<<" "<<ptr->val<<endl;
      BinaryNode <Key , Value > *b = nil ;
      if(ptr->right != nil )
      {
        b=min(ptr->right) ;
        return b->key;
      }
      BinaryNode <Key ,Value > *y ;
      y= ptr->parent;
      while(y!= nil  and ptr==y->right)
      {
          ptr = y ;
          y = y->parent ; 
      }
      return y->key;
      }
      
  }

  Key preorder_max( BinaryNode <Key ,Value > *temp)
  {
      
      if(temp == NULL)
        return Key();
      Key res = temp->key;
      Key lres = preorder_max(temp->left);
      Key Rres = preorder_max(temp->right);
      if(res< lres)
        res = lres;
      if(Rres > res)
        res = Rres;
      // if(temp->key > max1)
      // {

      //   max1= temp->key;
      //   cout<<"max 1 is "<<max1<<endl;
      // }
      // preorder_max(max1,temp->left);
      // preorder_max(max1,temp->right);
       return res;

  }

  virtual bool search(const Key& key)
  {
    BinaryNode <Key , Value > *node = this->root ;
    while(node)
    {
      if(key < node->key )
        node  = node->left ;
      else if(node->key < key)
        node = node->right ;
      else {
        return true ;
      }
    }
    return false ;
  }



  Key predecessor_tree(BinaryNode <Key , Value > *node)
  {
    //cout<<"-"<<endl<<node->left->key ;
    BinaryNode <Key , Value > *x = node;
      while(1)
      {
        if(node->left != nil )
        {
          
          return preorder_max(node->left) ;
        }
        if(node->parent!= nil )
        {
          node = node->parent ;
          while(node->key > x->key)
          {
              node = node->parent ;
          }
        }
          
          return node->key ;
      } 
  }

  virtual Key predecessor(const Key& key)
  {
    
    BinaryNode <Key , Value > *temp = this->root;
      while(1)
      {
          if(key < temp->key)
            temp = temp->left;
          else if(key > temp->key)
            temp= temp->right ;
          else
          {
            Key name = predecessor_tree(temp );
            if(name == key)
              {
                cout<<"predecessor does not exist since minimum element is "<<endl ;
                return name ;
              }
            else 
              return name ;
          }
      }
  }

   int size_of_tree(BinaryNode <Key , Value > *temp)
    {
        if(temp->left!=NULL and temp->right!=NULL )
          return (size_of_tree(temp->left)) + (size_of_tree(temp->right)) +1;
        else if(temp->left != NULL)
          return   size_of_tree(temp->left) + 1;
        else if(temp->right != NULL)
          return  size_of_tree(temp->right) + 1;
        else
          return 1;

    }

   virtual int size()
   {
    if(this->root == nil )
      return 0;
    else
      return size_of_tree(this->root);
   }

   virtual Value get(const Key& key)
  {
    BinaryNode <Key , Value > *node = this->root ;
    while(node)
    {
      if(key < node->key )
        node  = node->left ;
      else if(node->key < key)
        node = node->right ;
      else {
        return node->val ;
      }
    }
    return Value() ;
  }


    int find_height(BinaryNode < Key , Value > *node)
     {
      
          if(node ==  nil )
          return -1;    
          if(node->left == nil  and node->right == nil )
            return 0;
          else if(node->left == nil  )
          return find_height(node->right) +1;
        else if(node->right== nil)
          return find_height(node->left) +1;
        else
          return max(find_height(node->left),find_height(node->right)) +1;
   }

  /*  
   * This method returns the current height of the binary search tree.
   */ 

  virtual int getHeight()
  {
      //BinaryNode < Key,Value > *node = root;
      if(this->root== nil )
        return 0;
      else
        return find_height(this->root);

  }


} ;


template <class Key , class Value >
void RBTree <Key , Value > :: RBTransplant(node_ptr u, node_ptr v)
	{
		if(u->parent == nil )
			this->root = v;
		else if( u == u->parent->left)
			u->parent->left = v;
		else
		{
			u->parent->right = v;
			
		}
		v->parent = u->parent ; 
	}

template <class Key , class Value > 
void RBTree <Key , Value > :: deleteRBFixup(node_ptr root)
	{
		node_ptr x = root ;
		node_ptr w;
		while(x != this->root and clr(x) == BLACK)
		{
			if( x == x->parent->left)
			{
				w = x->parent->right ;
				if(clr(w) == RED)
				{
					clr(w) = BLACK ;
					clr(x->parent) = RED ;
					leftRotate(x->parent);
					w = x->parent->right ;
				}
				if(clr(w->left ) == BLACK and clr(w->right ) == BLACK)
				{
					clr(w) = RED;
					x = x->parent ; 
				}
				else
				{
					if((clr(w->right)) == BLACK)
					{
						clr(w->left) = BLACK ;
						clr(w) = RED ;
						rightRotate(w);
						w = x->parent->right ;
					}
					clr(w) = clr(x->parent) ;
					clr(x->parent) = BLACK ;
					clr(w->right ) = BLACK ;
					leftRotate(x->parent );
					x = this->root ;
				}
			}
			else
			{
				w = x->parent->left ;
				if(clr(w) == RED)
				{
					clr(w) = BLACK ;
					clr(x->parent) = RED ;
					rightRotate(x->parent);
					w = x->parent->left ;
				}
				if(clr(w->right ) == BLACK and clr(w->left ) == BLACK)
				{
					clr(w) = RED;
					x = x->parent ; 
				}
				else
				{
					if((clr(w->left)) == BLACK)
					{
						clr(w->right) = BLACK ;
						clr(w) = RED ;
						leftRotate(w);
						w = x->parent->left ;
					}
					clr(w) = clr(x->parent) ;
					clr(x->parent) = BLACK ;
					clr(w->left ) = BLACK ;
					rightRotate(x->parent );
					x = this->root ;
				}
				
			}

			
			}
			clr(x) = BLACK ;
	}

template <class Key, class Value>
void RBTree<Key , Value > :: insertRBFixup(node_ptr Z)
{
	//Z = ( RBTNode<Key , Value >* ) Z;
	/*if(Z->parent != NULL)
	{

		// node_ptr X =  Z->parent->parent;
		if( (clr(Z->parent)) == RED)
		{
			if( Z->parent == Z->parent->parent->left)
			{
				//case 1
				//if(Z->parent->parent != NULL)
				//{
					//node_ptr X =  Z->parent->parent;
					//if(Z->parent->parent->right != NULL)
					//{
						//node_ptr U = X->right ;
						if( Z->parent->parent->right != NULL and clr(Z->parent->parent->right) == RED)
						{
							clr(Z->parent) = BLACK ;
							clr(Z->parent->parent->right) = BLACK ;
							clr(Z->parent->parent) = RED ;
							insertRBFixup(Z->parent->parent);
						}//}	//}
			else if(  Z->parent->parent->right != NULL and  clr(Z->parent->parent->right) == BLACK)
			{	
				//case 2
				if(Z== Z->parent->right)
				{
					Z= Z->parent ;
					leftRotate(Z) ;
				}
			}	
				else 
				{
				//case 3
					clr(Z->parent ) = BLACK;
					clr(Z->parent->parent) = RED ;
					rightRotate(Z->parent->parent);
				}
					
			
			
		}
		else if(Z->parent == Z->parent->parent->right)
		{
			//node_ptr U = X->left ;
			if( Z->parent->parent->left != NULL and clr(Z->parent->parent->left) == RED)
			{
				//case 4
				clr(Z->parent ) = BLACK ;
				clr(Z->parent->parent->left) = BLACK ;
				clr(Z->parent->parent) = RED ;
				insertRBFixup(Z->parent->parent) ;
			}
			else if( Z->parent->parent->left != NULL and  clr(Z->parent->parent->left) == BLACK)
			{	
				//case 5
				if(Z== Z->parent->left)
				{
					Z= Z->parent ;
					rightRotate(Z) ;
				}
			}
			else
			{
				//case 6
				clr(Z->parent) = BLACK;
				clr(Z->parent->parent) = RED ;
				leftRotate(Z->parent->parent);
				
			}
				
			
		}
	}
	}


	//clr(this->root) = BLACK ; 
	
	// } */

		
	while(  (clr(Z->parent)) == RED)
	{
		
			if(Z->parent == Z->parent->parent->left)
			{
				
				//case 1
				//if(Z->parent->parent->right != NULL)
				//{
					node_ptr y = Z->parent->parent->right ;
					if( clr(y) == RED)
					{
						clr(Z->parent) = BLACK;
							clr(y) = BLACK;
						clr(Z->parent->parent) = RED;
						Z= Z->parent->parent  ;
					}//}	
				else
				{
					
					if(  Z == Z->parent->right)
					{
						Z = Z->parent ;
						leftRotate(Z);
				 //Z= Z->left ;
					}	
	
						clr(Z->parent) = BLACK ;
						clr(Z->parent->parent) =  RED ;
						rightRotate(Z->parent->parent) ;
					
				} 
					
				
			
			
		}
		else	
		{
				
					node_ptr y = Z->parent->parent->left ;
					if( clr(y) == RED)
					{
						clr(Z->parent) = BLACK;
							clr(y) = BLACK;
						clr(Z->parent->parent) = RED;
						Z= Z->parent->parent  ;
					}//}	
				else
				{
					if(  Z == Z->parent->left)
					{
						Z = Z->parent ;
						rightRotate(Z);
				 //Z= Z->left ;
					}	
					
						clr(Z->parent) = BLACK ;
						clr(Z->parent->parent) =  RED ;
						//cout<<endl<<Z->key<<" "<<Z->parent->key<<" "<<Z->parent->parent->key ;
						leftRotate(Z->parent->parent) ;
					
				} 
			
			
			
					
		}
		}
		
	
	
	clr(this->root) = BLACK ;

}

template <class Key, class Value>
void RBTree <Key , Value >:: insertRB(node_ptr Z)
{
	
	node_ptr  Y = nil ;
	node_ptr  X = this->root ;
	//node_ptr node = this->root ;
	while(X != nil )
	{
		Y = X;
		if(Z->key < X->key)
			X = X->left ;
		else X = X->right ;
	}
	Z->parent =   Y ;
	if(Y == nil )
	{

		this->root = Z ;

	}
	else if(Z->key < Y->key )
		Y->left = Z;
	else 
		Y->right = Z;
	Z->left = nil ;
	Z->right = nil ;
	clr(Z) = RED ;
	//if(Z->parent != NULL and Z->parent->parent != NULL)
	insertRBFixup(Z);
}

template <class Key, class Value>
void RBTree<Key , Value > :: insert_node(const Key& key , const Value& value)
{
	BinaryNode <Key , Value >  *temp = new RBTNode <Key , Value > ;
	temp->key = key  ;	
	temp->val = value ;
	temp->left = nil;
	temp->right = nil ;
	insertRB(temp) ;
}



#endif /* ifndef RBTree_HPP_ */