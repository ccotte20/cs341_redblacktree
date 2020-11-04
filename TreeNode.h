// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "Node.h"
#ifndef TREENODE_H
#define TREENODE_H
class TreeNode : public Node
{
	public:
		TreeNode(int data);
		~TreeNode();
		TreeNode * getParent();
		void setParent(TreeNode * parent);
		TreeNode * getLeftChild();
		void setLeftChild(TreeNode * leftChild);
		TreeNode * getRightChild();
		void setRightChild(TreeNode * rightChild);
		bool getColor();
		void setColor(bool color);
	private:
		TreeNode * parent_;
		TreeNode * leftChild_;
		TreeNode * rightChild_;
		bool color_; // red = true, black = false
	protected:
		TreeNode() {}
};
#endif