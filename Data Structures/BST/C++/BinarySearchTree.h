#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

template <typename T>
class Node {
    T data;
    Node<T> *left, *right;

    public:
        Node(T &d) : data(d), left(0), right(0) {}
        Node(const Node &N) : data(N.data), left(0), right(0) {}

        template <typename V>
        friend class BST;
};

template <typename T>
class BST {
    Node<T> *root;
    
    //Copy Constructor
    static Node<T>  *copyAs(const Node<T> *node) {
        if(!node)
            return NULL;

        Node<T> *newnode = new Node<T>(*node);
        newnode->left = copyAs(node->left);
        newnode->right = copyAs(node->right);

        return newnode;
    }

    //Check if two trees are same
    static bool isSame(const Node<T> *node1, const Node<T> *node2) {
        if(!node1 && !node2)
            return true;

        if((!node1 && node2) || (node1 && !node2))
            return false;

        if(node1->data != node2->data)
            return false;

        bool verdictLeft = isSame(node1->left, node2->left);
        bool verdictRight = isSame(node1->right, node2->right);

        if(!(verdictLeft && verdictRight))
            return false;

        return true;
    }

    //Clear Tree Recursively
    static Node<T> *clearTreeRecursively(Node<T> *node) {
        if(!node)
            return NULL;

        if(!node->left && !node->right){
            delete(node);
            return NULL;
        }

        node->left = clearTreeRecursively(node->left);
        node->right = clearTreeRecursively(node->right);
        return node;
    }
    public:
        BST(): root(0) {}
        BST(const BST &BT) : root(0) {
            root = copyAs(BT.root);
        }

        //Construct BST using sorted array
        BST(const T (&ar)[10], int len) : root(0) {
            int mid = len/2;
            insertRecursively(ar[mid]);
            for(int i=mid-1; i>=0; i--)
                insertRecursively(ar[i]);

            for(int i=mid+1; i<len; i++) 
                insertRecursively(ar[i]);
        }

        ~BST() {
            root = clearTreeRecursively();
        }

        // = Operator
        const BST & operator=(const BST &BT) {
            root = clearTreeRecursively();
            root = copyAs(BT.root);
        }

        //Clear
        void clear() {
            if(isEmpty())
                return;
            root = clearTreeRecursively(root);
        }

        // is Empty
        bool isEmpty() const {
            return root==NULL;
        }
        
        // == Operator
        bool operator==(const BST &BT) {
            return isSame(root, BT.root);
        }
        
        //Size
        int size() const {
            return sizeHelper(root);
        }
    //Size Helper
    private:
        static int sizeHelper(const Node<T> *node) {
            if(!node)
                return 0;
            return sizeHelper(node->left) + sizeHelper(node->right) + 1;
        }    
    public:        
        //Insert Iteratively
        void insertIteratively(T el) {
            Node<T> *newnode = new Node<T>(el);

            Node<T> *it = root;
            Node<T> *prev = NULL;
            while(it) {
                prev = it;
                if(it->data > el){
                    it = it->left;
                }
                else{
                    it = it->right;
                }
            }
            if(!prev){
                root = newnode;               
            }
            else {
                if(prev->data > el) {
                    prev->left = newnode;
                }
                else {
                    prev->right = newnode;
                }
            }
            return;
        }

        //Insert Recursively
        void insertRecursively(T el) {
            root = insertRecursivelyHelper(root, el);
            return;
        }

    //Insert Recursively Helper
    private:
        static Node<T> *insertRecursivelyHelper(Node<T> *node, T el) {
            if(!node) {
                Node<T> *newnode = new Node<T>(el);
                return newnode;
            }
            if(node->data > el)
                node->left = insertRecurisvelyHelper(node->left, el)
            else
                node->right = insertRecursivelyHelper(node->right, el);

            return node;
        }

    //Delete Element
    public:
        void deleteElement(T &el) {
            root = deleteElementHelper(root, el);
            return;
        }
    //Delete Element Helper
    private:
        Node<T> *deleteElementHelper(Node<T> *node, T &el) {
            if(!node)
                return NULL;

            if(node->data > el)
                node->left = deleteElementHelper(node->left, el);
            else if(node->data < el)
                node->right = deleteElementHelper(node->right, el);

            else{
                if(node->left == NULL) {
                    Node<T> *temp = node->right;
                    delete(node);
                    return temp;
                }
                else if(node->right == NULL) {
                    Node<T> *temp = node->left;
                    delete(node);
                    return temp;
                }
                else {
                    Node<T> *temp = minValueNode(node->right);
                    node->data = temp->data;
                    node->right = deleteElement(node->right, temp->key);
                }
            }
            return node;
        }

        Node<T> *minValueNode(Node<T> *node) {
            Node<T> *current = node;
            while(current->left != NULL)
                current = current->left;
            return current;
        }

    public:
        //Print Tree Iteratively
        void printTreeIteratively() const{
            if(isEmpty()) {
                cout << "NULL TREE" << endl;
                return;
            }
            cout << endl;
            queue<const Node<T> *> Q;
            Q.push(root);
            Q.push(NULL);
            while(!Q.empty()) {
                const Node<T> *temp = Q.front();
                Q.pop();
                if(temp == NULL) {
                    if(!Q.empty()){
                        cout << endl;
                        Q.push(NULL);
                    }
                    continue;
                }
                cout << temp->data << " "; 
                if(temp->left)
                    Q.push(temp->left);
                if(temp->right)
                    Q.push(temp->right);
            }
            cout << endl;
        }
        
        //Find Element ( Keeping Const )
        const Node<T> *findElement(const T &el) const {
            if(isEmpty())
                return NULL;

            const Node<T> *temp = findElementHelper(root, el);

            if(!temp){
                cout << "\nElement Not Found!" << endl;
                return NULL;
            }
            else
                cout << "\nElement Found!" << endl;
            return temp;
        }

        //Find Element
        Node<T> *findElement(T &el) {
            if(isEmpty())
                return NULL;
            Node<T> *temp = findElementHelper(root, el);
            
            if(!temp){
                cout << "\nElement Not Found!" << endl;
                return NULL;
            }
            else
                cout << "\nElement Found!" << endl;
            return temp;
        }

    private:
        //Find Element Helper ( Const )
        static const Node<T> *findElementHelper(const Node<T> *node, const T &el) {
            if(!node)
                return NULL;
            if(node->data == el)
                return node;
            const Node<T> *temp;
            if(node->data > el) {
                temp = findElementHelper(node->left, el);
            }
            else {
                temp = findElementHelper(node->right, el);
            }
            return temp;
        }
        
        //Find Element Helper
        static Node<T> *findElementHelper(Node<T> *node, T &el) {
            if(!node)
                return NULL;
            if(node->data == el)
                return node;

            Node<T> *temp;

            if(node->data > el)
                temp = findElementHelper(node->left, el);
            else
                temp = findElementHelper(node->right,el);

            return temp;
        }  

    //Find Min Max
    public:
        Node<T> *findMin() const { // Making const
            if(isEmpty())
                return NULL;
            return findMinHelper(root); // Parameter Type Const
        }

        Node<T> *findMax() { // NOT Making Const
            if(isEmpty())
                return NULL;
            return findMaxHelper(root); // Return Type NOT Const
        }

    //Find Min Max Helper
    private:
        static const Node<T> *findMinHelper(const Node<T> *node) {
            if(!node)
                return NULL;

            if(!node->left)
                return node;

            return findMinHelper(node->left);            
        }
        static Node<T> *findMaxHelper(const Node<T> *node) {
            if(!node)
                return NULL;

            if(!node->right)
                retun node;

            return findMaxHelper(node->right);
        }

    //Delete Min Max
    public:
        void deleteMinIteratively() {
            if(isEmpty())
                return;
            Node<T> *it = root;
            Node<T> *prev = NULL;

            while(it->left) {
                prev = it;
                it = it->left;
            }
            if(prev)
                prev->left = it->right;
            else
                root = 0;
            
            delete(it);
            return;
        }

        void deleteMaxIteratively() {
            if(isEmpty())
                return;
            Node<T> *it = root;
            Node<T> *prev = NULL;

            while(it->right) {
                prev = it;
                it = it->right;
            }
            if(prev) {
                prev->right = it->left;
            }
            else {
                root = 0;
            }
            delete(it);
            return;
        }
        void deleteMin() {
            if(isEmpty())
                return;
            root = deleteMinRecursively(root);
        }

        void deleteMax() {
            if(isEmpty()) 
                return;
            root = deleteMaxRecursively(root);
        }
    
    //Delete Min Max Recursively Helper
    private:
       static Node<T> *deleteMinRecursively(Node<T> *node) {
           if(!node)
               return NULL;

           if(!node->left) {
               Node<T> *temp = node->right;
               delete(node);
               return temp;
           }

           node->left = deleteMinRecursively(node->left);
           return node;
       }

        static Node<T> *deleteMaxRecursively(Node<T> *node) {
            if(!node)
                return NULL;

            if(!node->right) {
                Node<T> *temp = node->left;
                delete(node);
                return temp;
            }

            node->right = deleteMaxRecursively(node->right);
            return node;
            
        }
    public:
        bool isValidBST() const{ 
            return isValidBSTHelper(root, INT_MIN, INT_MAX);
        }

    //Check If BST Helper
    private:
        bool isValidBSTHelper(const Node<T> *node, int min, int max) const {
            if(!node)
                return true;

            if(node->data < min || node->data > max)
                return false;
            // Do not remove below two conditions ( Corner Cases )
            if(node->left && node->left->data >= node->data)
                return false;
            if(node->right && node->right->data <= node->data)
                return false;

            bool verdictLeft =  isValidBSTHelper(node->left, min, node->data-1);
            bool verdictRight = isValidBSTHelper(node->right, node->data+1, max);

            if(!(verdictLeft && verdictRight))
                return false;

            return true;
           // return isValidBSTHelper(node->left, min, node->data-1) && isValidBSTHelper(node->right, node->data+1, max);

        }
        /*bool isValidBSTHelper(const Node<T> *node) const{ //Fails in one case ... See G4G for reference
            if(!node)
                return true;

            if(node->left) {
                if(node->left->data >= node->data)
                    return false;
            }

            if(node->right) {
                if(node->right->data < node->data)
                    return false;
            }

            bool verdictLeft =  isValidBSTHelper(node->left);
            bool verdictRight = isValidBSTHelper(node->right);

            if(!(verdictLeft && verdictRight))
                return false;

            return true;

        }*/
    //Common Ancestor ( LCA )
    public:
        Node<T> *LCA(T n1, T n2) const {
            return LCAHelper(root, n1, n2);
        }
    private:
        Node<T> *LCAHelper(Node<T> *node, T n1, T n2) const{
            if(node == NULL)
                return NULL;

            if(node->data > n1 && node->data > n2)
                return LCAHelper(node->left, n1, n2);

            if(node->data < n1 && node->data < n2)
                return LCAHelper(node->right, n1, n2);

            return node;
        }
    public:
        //Height of BST
        int height(Node<T> *root){
            if(!root)
                return 0;

            lheight = height(root->left);
            rheight = height(root->right);

            return 1 + max(lheight, rheight);
        }

        //Find Diameter(Width) of BST
        int diameter(Node<T> *root){
            if(!root)
                return 0;

            //Get height of left/right sub-tree
            int lheight = height(root->left);
            int rheight = height(root->right);

            //Get diameter of left/right sub-tree
            int ldiameter = diameter(root->left);
            int rdiameter = diameter(root->right);

            /* Return max of following three
             * 1) Diameter of left subtree
             * 2) Diameter of right subtree
             * 3) height of left subtree+right subtree+1
             */
            return max(lheight + rheight + 1, max(ldiameter, rdiameter));
        }

        //Mirror of Given Tree
        void mirror(Node<T>* node){
            if(!node)
                return;
            else{
                Node<T> *temp;

                mirror(node->left);
                mirror(node->right);

                temp = node->left;
                node->left = node->right;
                node->right = temp;
            }
        }

        //Check If Trees Mirror or not
        bool areMirror(Node<T> *a, Node<T> *n){
            if(!a && !b)
                return true;

            if(!a || !b)
                return false;

            if(a->data != b->data)
                return false;

            return areMirror(a->left,b->left) && areMirror(a->right, b->right);
        }

        //Check if Tree is Symmetric
        bool isSymmetric(Node<T> *root){
            return areMirror(root, root);
        }

        //Find Mirror of Given Node
        T findMirrorRec(T target, Node<T> *left, Node<T> *right){
            /* If any of the Node is none then Node itself and
             * decendent have no mirror, so return none
             */
            if(left == NULL || right == NULL)
                return -1;

            /* If left Node is target Node, then return right's
             * key ( mirror ) and vice-versa
             */
            if(left->data == target)
                return right->data;

            if(right->data == target)
                return left->data;

            //First recur external Nodes
            T mirror_val = findMirrorRec(target, left->left, right->right);

            if(mirror_val)
                return mirror_val;

            //If no mirror found, recur internal Nodes
            findMirrorRec(target, left->right, right->left);
        }

        //Level Order Traversal | Spiral Iterative O(n), O(n)
        void printSpiral(Node<T> *root){
            if(!root)
                return;

            stack<Node<T> *> s1;//To print level from R to L
            stack<Node<T> *> s2;//To print level from L to R

            s1.push(root);

            while(!s1.empty() || !s2.empty()){
                while(!s1.empty()){
                    Node<T> *temp = s1.top();
                    s1.pop();
                    cout << temp->data << " ";

                    //Right pushed before left
                    if(temp->right)
                        s2.push(temp->right);
                    if(temp->left)
                        s2.push(temp->left);
                }

                while(!s2.empty()){
                    Node<T> *temp = s2.top();
                    s2.pop();
                    cout << temp->data << " ";

                    //Left pushed before right
                    if(temp->left)
                        s1.push(temp->left);
                    if(temp->right)
                        s1.push(temp->right);
                }
            }
        }
        //PRINT LEFT VIEW
        /* We can also do a level order traversal and
         * print the first node at each level
         */
        /* Recursive Solution */
        void leftView(Node<T> *root){
            int max_level=0;
            leftViewHelper(root, 1, &max_level);
        }

    //LEFT VIEW HELPER
    private:
        void leftViewHelper(Node<T> *root, int level, int *max_level){
            if(!root) return;

            if(*max_level < level){
                cout << root->data << " ";
                *max_level = level;
            }

            leftViewHelper(root->left, level+1, max_level);
            leftViewHelper(root->right, level+1, max_level);
        }
    //PRINT RIGHT VIEW
    /* We can also do a level order traversal and
     * print the last node at each level
     */
    /* Recursive Solution */
    public:
        vector<int> rightSideView(TreeNode* root){
            vector<int> ans;
            rightSideViewHelper(root, 1, ans);
            return ans;
        }
    private:
        void rightSideViewHelper(TreeNode* root, int level, vector<int>& ans){
            if(!root) return;

            if(ans.size() < level)
                ans.push_back(root->val);

            rightSideViewHelper(root->right, level+1, ans);
            rightSideViewHelper(root->left, level+1, ans);
        }

    public:
        //COUNT OF LEAVES IN BST (Recursive)
        unsigned int getLeafCountRecur(Node<T> *root){
            if(!root)
                return 0;

            if(!(root->left) && !(root->right))
                return 1;

            else
                return getLeafCountRecur(root->left)+getLeafCountRecur(root->right);            
        }

        //COUNT OF LEAVES IN BST (Iterative | Using Level Order)
        unsigned int getLeafCount(Node<T> *root){
            if(!root)
                return 0;

            queue<Node<T> *> Q;
            Q.push(root);
            int count=0;
            while(!Q.empty()){
                Node<T> *temp = Q.front();
                Q.pop();
                if(temp->left)
                    Q.push(temp->left);
                if(temp->right)
                    Q.push(temp->right);
                if(!(temp->left) && !(temp->right))
                    count++;
            }

            return count;
        }

        // MERGE TWO BINART TREES
        /* Definition for a binary tree node.
         * int val;
         * TreeNode * left;
         * TreeNode * right;
         * TreeNode(int x): val(x), left(NULL), right(NULL) {}
         */

        TreeNode * mergeTrees(TreeNode* t1, TreeNode* t2){
            if(!t1)
                return t2;

            if(!t2)
                return t1;

            TreeNode* ans = new TreeNode(t1->val + t2->val);

            ans->left  = mergeTrees(t1->left, t2->left);
            ans->right = mergeTrees(t1->right, t2->right);

            return ans;
        }


        //CHECK IF BST IS BALANCED
        bool isBalanced(Node<T> *root){
            if(!root)
                return 1;

            int lh = height(root->left);
            int rh = height(root->right);

            if( abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right) )
               return 1;

           return 0; 
        }

        //SERIALIZE BST ( PREORDER FORMAT )
        void serialize(Node<T> *root){
            vector<T> v;
            serializeHelper(root, v);
        }

    private:
        void serializeHelper(Node<T> *root, vector<T> &v){
            if(!root){
                v.push_back(-1); // Delimiter
                return;
            }
            
            //preorder
            v.push_back(root->data);
            serializeHelper(root->left, v);
            serializeHelper(root->right, v);
        }

    public:
        //DESERIALIZE Binary Tree ( PREORDER FORMAT + Delimiter)
        int index = 0;
        Node<T>* deserialize(vector<T> v){
            if(index == v.size() || v[i] == -1){
                index++;
                return NULL;
            }            
            Node<T> *root = new Node(v[i]);
            index++;

            root->left = deserialize(v);
            root->right = deserialize(v);
            return root;
        }

        //DESERIALIZE BST ( PREORDER FORMAT )
        //Example : { 5, 2, 1, 3, 4, 7, 6, 8 }
        //We have to keep in mind that in a BST 
        //left value < current value and
        //right value > current value
        
        // O(n^2)
        Node<T>* deserialize(vector<T> v, int low, int high){
            if(low > high) return NULL;

            Node<T> *root = new Node(v[low]);

            int divIndex = findDivision(root->data, v , low+1, high);

            root->left = deserialize(v, low+1, divIndex-1);
            root->right = deserialize(v, divIndex, high);

            return root;
        }

        
        // O(n)                           INT_MIN  INT_MAX
        int currIndex = 0;
        Node<T> *deserialize(vector<T> v, int min, int max, int &currIndex){
            if(currIndex >= v.size()) return NULL;

            if(v[currIndex] > min && v[currIndex] < max){
                Node<T> *root = new Node(v[currIndex++]);
                root->left = deserialize(v, min, root->data, currIndex);
                root->right = deserialize(v, root->data, max, currIndex); 
            }

            return root;
        }

    //DESERIALIZE BST HELPER
    private:
        int findDivision(int rootVal, vector<T> &v, int low, int high){
            for(int i=low; i<=high; i++){
                if(rootValue < v[i])
                    break;
            }

            return i;
        }

   //CONVERT BST TO GREATER BST
   /*Given a Binary Search Tree (BST), convert it to a Greater Tree such that 
    * every key of the original BST is changed to the original key plus 
    * sum of all keys greater than the original key in BST.
    * Input: The root of a Binary Search Tree like this:
    *               5
    *             /   \
    *            2     13
    *
    * Output: The root of a Greater Tree like this:
    *              18
    *             /   \
    *           20     13
    */
    private:
        TreeNode* convertBSTHelper(TreeNode* root, int& add){
            if(!root)
                return root;

            convertBSTHelper(root->right, add);
            root->val += add;
            add = root->val;
            convertBSTHelper(root->left, add);

            return root;
        }
    public:
        TreeNode* convertBST(TreeNode* root) {
            int add = 0;
            return convertBSTHelper(root, add);
        }

	// PRINT INORDER W/O RECURSION
	vector<int> Solution::inorderTraversal(TreeNode* A){
		vector<int> ans;
		Stack<int> st;
		TreeNode* curr = A;
		bool done = false;

		while(!done){
			if(curr){
				st.push(curr);
				curr = curr->left;
			}
			else{
				if(!st.empty()){
					curr = st.top();
					st.pop();
					ans.push_back(curr->val);
					curr = curr->right;
				}
				else{
					done = true;
				}
			}
		}

		return ans;
	}

};

#endif
