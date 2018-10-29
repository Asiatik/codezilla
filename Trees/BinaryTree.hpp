#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP 1

using namespace std;

template <class Key ,class Value>
class BinaryNode
{
public:
	Key key;
	Value val;
  int height ;
	BinaryNode<Key,Value> *root, * left,* right,* parent  ;
  
    /*Default constructor. Should assign the default value to key and value
     */
	BinaryNode()
  {

      key=Key();
      root= NULL;
      left=NULL;
      right=NULL;
      parent=NULL;
      height = 0;
      val=Value();
    

  }
	/*This contructor should assign the key and val from the passed parameters
     */
	BinaryNode(Key key, Value value)
  {
      key=key;
      val=value;
  }
};

template<class Key,class  Value> 
class BinaryTree  : public BinaryNode<Key,Value>
{
	/* You can implement your own helper functions whenever required.
	 */
protected:
	BinaryNode<Key,Value> * root ;

public:

  BinaryTree()
  {
    root = NULL;
      //BinaryNode <Key , Value > *r= new BinaryNode <Key , Value> ;
  }
  
  /* Implement get function to retrieve the value corresponding to given key in binary tree.
   */
   Value help_get(BinaryNode <Key , Value > *temp , const Key& key)
   {

      Value num = Value();

      if(temp == NULL)
      {
        return Value();
      }
      else
      {
        if(key == temp->key)
          return temp->val;
        else
        {
          num = help_get(temp->left,key);
          if(num != Value())
            return num;
          num = help_get(temp->right,key);
        }
      }

      return num;

   }

  Value get(const Key& key)
  {
    Value  num;
    BinaryNode <Key ,Value > *node = root ;
    num = help_get(root,key);
    
    return num;
  }
  // // }
   /* Implement remove function that can delete a node in binary tree with given key. 
    */

  BinaryNode <Key , Value > * r(const Key& key , BinaryNode<Key , Value > *temp)
  {
    BinaryNode <Key , Value > *k;
    if(temp == NULL)
      return NULL;
    if(temp != NULL and temp->key == key)
      return temp;
    else{
          k = r(key , temp->left);
          if( k!= NULL and k->key == key)
            return k ;
          else
        {
         
            k = r(key , temp->right);
            return k ;

        }
        }     
        
       //return temp ;
    }
  

  void  remove1(const Key& key , BinaryNode <Key ,Value > *node  , BinaryNode <Key ,Value > *temp )
  {
    
           while(temp->left != NULL)
           {
              temp = temp->left ;
              
           }
           if(temp->right == NULL)
              {

                node->key = temp->key ;
                node->val = temp->val ;
                temp->parent->left = NULL;
              }
              else {
                    node->key = temp->right->key ;
                node->val = temp->right->val ;
                temp->right = NULL;
              }
      
      // }
  }
  virtual void remove(const Key& key) 
  {
     if(root == NULL)
      return ;
    BinaryNode <Key , Value > *u = r(key , root) ;
    remove1(key , u , root);
    //remove1(key , root , root->right ) ;
    // if(root->left == NULL and root->right == NULL and root->key == key)
    //   root = NULL ;
    // else
    // {
      
    //   //Key max_key=preorder_max(temp) ;

    //   while(1)
    //   {

    //     if(node->key==key)
    //     {
            
    //         // if((node->left == NULL ) || (node->right == NULL))
    //         //   delete(node->key);
    //         // else
    //         //   {
    //         //     node->key=temp->max_key;
    //         //     delete(temp);
    //         //   }
    //     }

        

    // }

    // }
  }
  /* Implement has function which will return true if the given key is present in binary tree 
   * otherwise return false.  
   */

  virtual bool check_preorder(BinaryNode <Key,Value >  *temp ,const Key& key )
  {
      bool num =false;
      if(temp==NULL)
        return false;
      if(temp->key==key)
        return true;
      else
      {
          num = check_preorder(temp->left , key);
          if(num==true)
            return true;
          else
            num = check_preorder(temp->right , key);
      }
      return num ;
  }


  virtual bool has(const Key& key) 
  {
      BinaryNode <Key ,Value > *temp = root ;
      return check_preorder(temp ,key);
  }
  /* Implement put function such that newly inserted node keep the tree balanced. 
   */	

  BinaryNode < Key , Value > * func(BinaryNode <Key , Value > *p,const Key& key , const Value& value )
  {
      BinaryNode <Key , Value > *temp = new BinaryNode <Key , Value > ;
      temp->key= key;
      temp->val = value;
      temp->parent = p;
      return temp;
  }

  void insert_preorder( BinaryNode <Key , Value > *temp  , const Key& key , const Value& value )
  {
    int num=0;

    if(temp->left==NULL || temp->right==NULL)
    {
        num=1;
        if(temp->left==NULL)
          temp->left=func(temp ,key , value);
        else
          temp->right=func(temp , key , value);
    }
    else
    {
        insert_preorder(temp->left,key,value);
        if(num == 1)
          return ;   
    }
    // else
    // {
    //     temp = temp->left;
    //     insert_preorder(key,value);
    //     temp =temp->right;
    //     insert_preorder(key,value);
    // }

    
    // if(num==0)
    // {
    //     while(temp!=NULL)
    //     {
    //         if(temp->left=NULL)
    //         {
    //             temp->left=func(temp , key,value);
    //         }
    //     }
    // }

      
  }

  virtual void put(const Key& key, const Value& value ) 
  {
      BinaryNode <Key , Value > *node = new BinaryNode <Key , Value > ;
      if(root == NULL )
      {
        
          root = func(NULL,key , value);
          

      }
      else
      {
          
          insert_preorder(root,key,value) ;
      }

  }
  /*
   *This method print all the key value pairs of the binary tree, as
   *observed in an in order traversal.
   */

  void help_print_in_order(BinaryNode <Key , Value > *temp)
  {
    
    if(temp == NULL)
      return ;
      help_print_in_order(temp->left);
      cout<<temp->key<<" "<<temp->val<<endl;
      help_print_in_order(temp->right);
  }

  virtual void print_in_order()
  {

    help_print_in_order(root);

  }
  /*
   *This method print all the key value pairs of the binary tree, as
   *observed in an pre order traversal.
   */

  void help_print_pre_order(BinaryNode <Key , Value > *temp)
  {
    
    if(temp == NULL)
      return ;
    else
    {
       
      cout<<temp->key<<" "<<temp->val<<endl;
      help_print_pre_order(temp->left);
      help_print_pre_order(temp->right);
    }
    
  }

  virtual void print_pre_order()
  {
    help_print_pre_order(root);
  }
  /*
   *This method print all the key value pairs of the binary tree, as
   *observed in a post order traversal.
   */
  void help_print_post_order(BinaryNode <Key , Value > *temp)
  {
    
    if(temp == NULL)
      return ;
    else
    {
        
      help_print_post_order(temp->left);
      help_print_post_order(temp->right);
      cout<<temp->key<<" "<<temp->val<<endl;
    }
    
  }

  virtual void print_post_order()
  {
      help_print_post_order(root);
  }
  

  /*
   *This method returns the minimum element in the binary tree.
   */

  Key help_preorder_min( BinaryNode <Key ,Value > *temp)
  {
      
      if(temp == NULL)
        return Key() ;
      Key res = temp->key;
      Key lres = res ;
      Key Rres = res ;
      //cout<<"res is "<<res<<endl;
      if(temp->left != NULL)
      lres = help_preorder_min(temp->left);
      //cout<<"348-1"<<" "<<lres;
      if(temp->right != NULL)
      Rres = help_preorder_min(temp->right);
      //cout<<"348-2"<<" "<<Rres;
       if(lres < res)
       {

         res = lres ;
       }
       if(res > Rres)
       {
          res = Rres;
       }
        //cout<<"347";
       return res;

  }

  virtual Key minimum()
  {
   

    Key min = help_preorder_min(this->root);
    //cout<<endl<<min;
    return min;

  }

  Key preorder_max( BinaryNode <Key ,Value > *temp)
  {
      
      if(temp == NULL)
        return INT8_MIN;
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
  /*
   * This method returns the maximum element in the binary tree.
   */

  Key help_preorder_max( BinaryNode <Key ,Value > *temp)
  {
      
      if(temp == NULL)
        return Key();
      Key res = temp->key;
      Key lres = help_preorder_max(temp->left);
      Key Rres = help_preorder_max(temp->right);
      if(res< lres)
        res = lres;
      if(Rres > res)
        res = Rres;

       return res;

  }

  virtual Key maximum()
  {
    Key max = help_preorder_max(root);
    return max;
  }
  /*
   *This method returns the successor, i.e, the next larget element in the
   *binary tree, after Key.
   */

  Key helper_Successor(Key res, BinaryNode <Key ,Value > *temp , const Key& key)
  {

      Key lres , Rres;
      if(temp == NULL)
        return Key();

      if(temp->key > key  and temp->key < res )
      {
        res = temp->key;
        //cout<<"res is 1----"<<res<<endl;

      }

      if(temp->left != NULL)
         lres = helper_Successor(res,temp->left,key);
      if(temp->right != NULL)
        Rres = helper_Successor(res,temp->right,key);

      if(lres > key  and lres < res  )
      {

        res = lres;
        //cout<<"res is ----"<<res<<endl;
      }
      if(Rres > key and  Rres < res)
      {

        res = Rres;
        //cout<<"res is ----"<<res<<endl;
      }
      
       return res;

  }

  virtual Key successor(const Key& key)
  {   

      return  helper_Successor(maximum(),root , key);
  }
  /*
   * This method returns the predessor, ie, the next smallest element in the
   * binary tree, after Key.
   */

  Key Predecessor(Key res, BinaryNode <Key ,Value > *temp , const Key& key)
  {
      Key lres, Rres ;
      if(temp == NULL)
        return Key();

      if(temp->key < key && temp->key > res )
      {
          res = temp->key;
          //cout<<"res is 1"<<res<<endl;
      }
      if(temp->left != NULL)
         lres = Predecessor(res,temp->left,key) ;
      if(temp->right != NULL)
         Rres = Predecessor(res,temp->right,key) ;

      if(lres < key  && lres > res  )
      {

        res = lres;
        //cout<<"res is 2"<<res<<endl;
      }
      if(Rres < key && Rres > res)
      {

        res = Rres;
        //cout<<"res is 3"<<res<<endl;
      }
      
       return res;


  }

  virtual Key predecessor(const Key& key)
  {    
      return Predecessor(Key(), root , key);

  }
};

#endif /* ifndef BINARYTREE_HPP */