// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "RedBlackTree.h"
RedBlackTree::RedBlackTree() : BinaryTree()
{
	
}

RedBlackTree::~RedBlackTree()
{
	
}

void RedBlackTree::insert(int data)
{
	// default color for treenode constructor is red
	TreeNode * newNode = new TreeNode(data);
	
	setRoot(insertNode(getRoot(), newNode));
	
	balanceColor(getRootReference(), newNode);
}

void RedBlackTree::printRedNodes(TreeNode * root)
{
	if (root != nullptr)
	{
		printRedNodes(root->getLeftChild());
		if(root->getColor()==true)
			std::cout << root->getData() << " ";
		printRedNodes(root->getRightChild());
	}
}

void RedBlackTree::printBlackNodes(TreeNode * root)
{
	if (root != nullptr)
	{
		if(root->getColor()==false)
			std::cout << root->getData() << " ";
		printBlackNodes(root->getLeftChild());
		printBlackNodes(root->getRightChild());
	}
}

void RedBlackTree::rotateLeft(TreeNode *& root, TreeNode *& newNode)
{
	TreeNode * newNodeRight = newNode->getRightChild();
	newNode->setRightChild(newNodeRight->getLeftChild());
	
	if (newNode->getRightChild() != nullptr)
		newNode->getRightChild()->setParent(newNode);
	
	newNodeRight->setParent(newNode->getParent());
	
	if (newNode->getParent() == nullptr)
		root = newNodeRight;
	else if (newNode == newNode->getParent()->getLeftChild())
		newNode->getParent()->setLeftChild(newNodeRight);
	else
		newNode->getParent()->setRightChild(newNodeRight);
	
	newNodeRight->setLeftChild(newNode);
	newNode->setParent(newNodeRight);
}

void RedBlackTree::rotateRight(TreeNode *& root, TreeNode *& newNode)
{
	TreeNode * newNodeLeft = newNode->getLeftChild();
	newNode->setLeftChild(newNodeLeft->getRightChild());
	
	if (newNode->getLeftChild() != nullptr)
		newNode->getLeftChild()->setParent(newNode);
	
	newNodeLeft->setParent(newNode->getParent());
	
	if (newNode->getParent() == nullptr)
		root = newNodeLeft;
	else if (newNode == newNode->getParent()->getLeftChild())
		newNode->getParent()->setLeftChild(newNodeLeft);
	else
		newNode->getParent()->setRightChild(newNodeLeft);
	
	newNodeLeft->setRightChild(newNode);
	newNode->setParent(newNodeLeft);
}

void RedBlackTree::balanceColor(TreeNode *& root, TreeNode *& newNode)
{
	TreeNode * newNodeParent = nullptr;
	TreeNode * newNodeGrandparent = nullptr;
	
	while((newNode != root) && (newNode->getColor() != false) && (newNode->getParent()->getColor() == true))
	{
		newNodeParent = newNode->getParent();
		newNodeGrandparent = newNode->getParent()->getParent();
		
		if(newNodeParent == newNodeGrandparent->getLeftChild())
		{
			TreeNode * newNodeUncle = newNodeGrandparent->getRightChild();
			
			if (newNodeUncle != nullptr && newNodeUncle->getColor() == true)
			{
				newNodeGrandparent->setColor(true);
				newNodeParent->setColor(false);
				newNodeUncle->setColor(false);
				newNode = newNodeGrandparent;
			}
			else
			{
				if(newNode == newNodeParent->getRightChild())
				{
					rotateLeft(root, newNodeParent);
					newNode = newNodeParent;
					newNodeParent = newNode->getParent();
				}
				else
				{
					rotateRight(root, newNodeGrandparent);
					bool temp = newNodeParent->getColor();
					newNodeParent->setColor(newNodeGrandparent->getColor());
					newNodeGrandparent->setColor(temp);
					newNode = newNodeParent;
				}
			}
		}
		else
		{
			TreeNode * newNodeUncle = newNodeGrandparent->getLeftChild();
			
			if ((newNodeUncle != nullptr) && (newNodeUncle->getColor() == true))
			{
				newNodeGrandparent->setColor(true);
				newNodeParent->setColor(false);
				newNodeUncle->setColor(false);
				newNode = newNodeGrandparent;
			}
			else
			{
				if(newNode == newNodeParent->getLeftChild())
				{
					rotateRight(root, newNodeParent);
					newNode = newNodeParent;
					newNodeParent = newNode->getParent();
				}
				else
				{
					rotateLeft(root, newNodeGrandparent);
					bool temp = newNodeParent->getColor();
					newNodeParent->setColor(newNodeGrandparent->getColor());
					newNodeGrandparent->setColor(temp);
					newNode = newNodeParent;
				}
			}
		}
	}
	root->setColor(false);
}