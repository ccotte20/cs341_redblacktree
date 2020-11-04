// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "TreeNode.h"

TreeNode::TreeNode(int data) : Node(data), parent_(nullptr), leftChild_(nullptr), rightChild_(nullptr), color_(true)
{
	
}

TreeNode::~TreeNode()
{
	delete leftChild_;
	delete rightChild_;
}

TreeNode * TreeNode::getParent()
{
	return parent_;
}

void TreeNode::setParent(TreeNode * parent)
{
	parent_ = parent;
}

TreeNode * TreeNode::getLeftChild()
{
	return leftChild_;
}

void TreeNode::setLeftChild(TreeNode * leftChild)
{
	leftChild_=leftChild;
}

TreeNode * TreeNode::getRightChild()
{
	return rightChild_;
}

void TreeNode::setRightChild(TreeNode * rightChild)
{
	rightChild_=rightChild;
}

bool TreeNode::getColor()
{
	return color_;
}

void TreeNode::setColor(bool color)
{
	color_=color;
}