#ifndef BSTREE_HPP
#define BSTREE_HPP 1
#include "BinaryTree.hpp"

template <class Key,class  Value>
class BSTree : public BinaryTree<Key, Value> 
{

/* Inherit as many functions as possible from BinaryTree.
 * Only override those where you can decrease the time complexity and where you absolutely need to do it.
 * Also make sure that all inherited functions work correctly in the context of a binary search tree.
 */
protected:
  // BinaryNode <Key , Value > *root ;
  using BinaryTree <Key, Value> :: root ;

public:
  using BinaryTree <Key , Value > :: print_in_order ;
  using BinaryTree <Key , Value > :: print_pre_order ;
  using BinaryTree <Key , Value > :: print_post_order ;
  using BinaryTree <Key , Value > :: preorder_max ;
  // BSTree()s
  // {
        
  //      left=NULL;
  //      right=NULL;
  //      parent = NULL;
  // }

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
  

  virtual  Key  minimum()
  {

    BinaryNode <Key , Value > *x = this->root;
    
      while(x->left!=NULL)
      {
          x= x->left;
      }
      // cout<<"goo\n"<<x->key<<endl;
      return x->key;
  }

  virtual Key maximum()
  {
    BinaryNode <Key , Value > *x = this->root;
      while(x->right!=NULL)
      {
          x= x->right;
      }
      return x->key;
  }
  // BinaryNode <Key , Value > *root = NULL;

  

  void put(const Key& key , const Value& value )
  {
      BinaryNode <Key , Value > *temp = new BinaryNode <Key , Value > ;
      //cout<<"55";
      temp->key= key;
       temp->val = value;
       BinaryNode < Key , Value > *p;
      p = insert( temp);
       
       // temp->parent = p;
       //return temp;
  }

  BinaryNode <Key , Value > * insert(BinaryNode <Key , Value > *z)
  {   
      //cout<<"56";
      BinaryNode < Key   , Value > *node ;
      node = root;
      // cout<<endl<<z->key<<" "<<z->val<<endl;
      BinaryNode < Key ,Value > *y = NULL ;
       //BinaryTree <Key , Value > p;
       // cout<<"76";
       //cout<<"---"<<node;
       while(node != NULL)
       {
           y = node ;
           if(z->key < node->key)
           {
               node = node->left;
           }
          else
          {
              node= node->right;
          }
       }
        z->parent = y;
        if(y==NULL)
            root = z;
        else if(z->key < y->key)
            y->left = z;
        else
          y->right = z;
        
        //cout<<endl<<" "<<z->key;
        return z;



      // if(len == 0)
      // {
          
      //     node = p.func(NULL , key ,value);
      //     cout<<"after calling of func"<<node->key<<"-"<<node->left<<"-"<<node->right<<endl;

      // }

      // else
      // {
      //      while(node != NULL)
      //     {
      //         y = node ;
      //         if(key < node->key)
      //         {
      //           cout<<"hello";
      //             node = node->left;
      //         }
      //         else
      //         {
      //             node = node->right;
      //         }
      //     }
      //     // if(y==NULL)
      //     // {
              
      //     // }
      //     // else if(key < y->key)
      //     // {
      //     //     y->left = p.func(y,key , value);
      //     // }
      //     // else
      //     // {
      //     //     y->right = p.func(y , key , value);
          
      //     // }
      //  }
      
     
  }
  void use_delete(BinaryNode <Key , Value > *a , const Key& key)
  {
      if(a==NULL)
      {
          return ;
      }
      else
      {
          if(key < a->key)
            use_delete(a->left,key);
          else if(key > a->key)
            use_delete(a->right,key);
          else
          {
              if(a->left==NULL and a->right == NULL)
              {
                if(a== a->parent->left)
                  a->parent->left = NULL;
                else
                a->parent->right = NULL ;
              }
               if(a->left == NULL and a->right != NULL)
              {
                  // a->parent->key = a->right->key;
                  // a->parent->val = a->right->val;
                if(a->parent != NULL and a == a->parent->right)
                  a->parent->right = a->right;
                else if(a->parent != NULL and a == a->parent->left ) 
                  a->parent->left = a->right ;
                else
                root = a->right;
                  //delete [] a;
              }
              if(a->right == NULL and a->left != NULL )
              {
                  // a->parent->key = a->left->key;
                  // a->parent->val = a->left->val;
                if(a->parent != NULL and a== a->parent->right)
                  a->parent->right = a->left ;
                else if(a->parent != NULL and a== a->parent->left)
                  a->parent->left = a->left;
                else
                  root = a->left;

                  //delete(a);
              }
              
                //delete(a);
              if(a->left != NULL and a->right != NULL)
              {
                  BinaryNode <Key ,Value > *temp = Successor_for_delete(this->root , a->key);
                  a->key = temp->key ;
                  a->val = temp->val ;
                  use_delete(temp , temp->key ) ;
              }
          }
      } 
  }

  void removeBST(const Key& key )
  {
      if(root->left == NULL and root->right == NULL and root->key == key)
        root = NULL;
      else{
         use_delete(root,key);
      }
     

  }

  BinaryNode <Key , Value >  * return_node_of_key(const Key& key , BinaryNode <Key , Value > *temp )
  {
    
      if(temp == NULL)
        return NULL ;
      if(temp->key == key)
        return temp;
      if(key > temp->key)
      {
        BinaryNode <Key , Value > *k ;
        k =   return_node_of_key(key , temp->right) ;
        return k;
        //cout<<"k->key"<<endl<<endl<<k->key<<endl;
      }
      else 
         return  return_node_of_key(key , temp->left) ;
        
        
  }

   virtual BinaryNode<Key , Value > * min(BinaryNode <Key , Value > *x)
  {
     
      while(x->left!=NULL)
      {
          x= x->left;
      }
      return x ;
  }

  BinaryNode <Key , Value > * Successor_for_delete( BinaryNode<Key , Value > *node , const Key& key)
  {
      BinaryNode <Key , Value > *ptr = return_node_of_key(key , node);
      cout<<endl<<ptr->key<<" "<<ptr->val<<endl;
      BinaryNode <Key , Value > *b =NULL ;
      if(ptr->right != NULL)
      {
        b=min(ptr->right) ;
        return b;
      }
      BinaryNode <Key ,Value > *y ;
      y= ptr->parent;
      while(y!=NULL and ptr==y->right)
      {
          ptr = y ;
          y = y->parent ; 
      }
      return y ;
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
        BinaryNode <Key , Value > *ptr = return_node_of_key(key , root);
      //cout<<endl<<ptr->key<<" "<<ptr->val<<endl;
      BinaryNode <Key , Value > *b =NULL ;
      if(ptr->right != NULL)
      {
        b=min(ptr->right) ;
        return b->key;
      }
      BinaryNode <Key ,Value > *y ;
      y= ptr->parent;
      while(y!=NULL and ptr==y->right)
      {
          ptr = y ;
          y = y->parent ; 
      }
      return y->key;
      }
      
  }

  Key predecessor_tree(BinaryNode <Key , Value > *node)
  {
    //cout<<"-"<<endl<<node->left->key ;
    BinaryNode <Key , Value > *x = node;
      while(1)
      {
        if(node->left != NULL)
        {
          
          return preorder_max(node->left) ;
        }
        if(node->parent!= NULL)
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
    
    BinaryNode <Key , Value > *temp = root;
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



     int find_height(BinaryNode < Key , Value > *node)
     {
      
          if(node == NULL)
          return -1;    
          if(node->left == NULL  and node->right == NULL)
            return 0;
          else if(node->left == NULL )
          return find_height(node->right) +1;
        else if(node->right==NULL)
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
      if(root==NULL)
        return 0;
      else
        return find_height(root);

  }

//   /*
//    * This method returns the total number of elements in the binary search tree.
//    */

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
    if(root == NULL)
      return 0;
    else
      return size_of_tree(root);
   }
//   /*
//    * This method prints the key value pairs of the binary search tree, sorted by
//    * their keys.
//    */
  virtual void print()
  {
      print_in_order();
  }
 };

 #endif /* ifndef BSTREE_HPP */