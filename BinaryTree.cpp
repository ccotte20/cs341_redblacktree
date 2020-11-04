// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	
}

BinaryTree::~BinaryTree()
{
	// Ryan: Always check to make sure this isn't the nullptr first.
	delete root_;
}

TreeNode * BinaryTree::getRoot()
{
	return root_;
}

TreeNode *& BinaryTree::getRootReference()
{
	return root_;
}

void BinaryTree::setRoot(TreeNode * root)
{
	root_=root;
}

void BinaryTree::insert(int data)
{
	// for red black the tree node will have a color set here
	TreeNode * newNode = new TreeNode(data);
	
	root_ = insertNode(root_, newNode);
	
	// rebalance & recolor
}

void BinaryTree::printPostOrder(TreeNode * root) 
{
	if (root != nullptr)
	{
		printPostOrder(root->getLeftChild());
		printPostOrder(root->getRightChild());
		std::cout << root->getData() << " ";
	}
}

TreeNode * BinaryTree::insertNode(TreeNode * root, TreeNode * newNode)
{
	if(root == nullptr)
	{
		return newNode;
	}
	else
	{
		if(newNode->getData() > root->getData())
		{
			// right subtree
			root->setRightChild(insertNode(root->getRightChild(), newNode));
			root->getRightChild()->setParent(root);
		}
		else if(newNode->getData() < root->getData())
		{
			// left subtree
			root->setLeftChild(insertNode(root->getLeftChild(), newNode));
			root->getLeftChild()->setParent(root);
		}
		else
		{
			// keep count of duplicates
		}
		return root;
	}
}