// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "BinaryTree.h"
#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
class RedBlackTree : public BinaryTree
{
	public:
		RedBlackTree();
		~RedBlackTree();
		virtual void insert(int data);
		void printRedNodes(TreeNode * root); // inorder traversal
		void printBlackNodes(TreeNode * root); // preorder traversal
	private:
		void rotateLeft(TreeNode *& root, TreeNode *& newNode);
		void rotateRight(TreeNode *& root, TreeNode *& newNode);
		void balanceColor(TreeNode *& root, TreeNode *& newNode);
};
#endif