
BinaryTreeMain :	BT.cpp BinaryTree.hpp 
					g++ -o BinaryTreeMain BT.cpp
BSTreeMain:	BST.cpp BSTree.hpp BinaryTree.hpp 
					g++ -o BSTreeMain BST.cpp
AVLMain:	AVL.cpp AVL.hpp BSTree.hpp BinaryTree.hpp 
					g++ -o AVLMain AVL.cpp
RBTreeMain:	RBT.cpp RBTree.hpp BSTree.hpp BinaryTree.hpp
					g++ -o RBTreeMain RBT.cpp

prob2:	prob2.cpp AVL.cpp AVL.hpp BSTree.hpp BinaryTree.hpp 
					g++ -o prob2 prob2.cpp
clean :
					rm BinaryTreeMain BSTreeMain AVLMain RBTreeMain  prob2
