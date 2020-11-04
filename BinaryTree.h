// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "TreeNode.h"
#include <iostream>
#ifndef BINARYTREE_H
#define BINARYTREE_H
class BinaryTree
{
	public:
		BinaryTree();
		virtual ~BinaryTree();
		TreeNode * getRoot();
		TreeNode *& getRootReference();
		void setRoot(TreeNode * root);
		virtual void insert(int data);
		void printPostOrder(TreeNode * root);
		TreeNode * insertNode(TreeNode * root, TreeNode * newNode);
	private:
		TreeNode * root_;
};
#endif