// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte
#include "RedBlackTree.h"
#include <fstream>
int main()
{
	//open file, check for errors
	std::ifstream inStream;
	inStream.open("data.txt");
	if(inStream.fail())
	{
		std::cout<<"Input file opening failed" << std::endl;
		exit(1);
	}
	
	RedBlackTree * tree = new RedBlackTree();
	
	int inputInt(0);
	while(inStream>>inputInt)
	{
		tree->insert(inputInt);
	}
	inStream.close();
	
	std::cout<<"Red Nodes: ";
	tree->printRedNodes(tree->getRoot());
	std::cout<<"\nBlack Nodes: ";
	tree->printBlackNodes(tree->getRoot());
	std::cout<<"\nRoot: " <<tree->getRoot()->getData()<<std::endl;
	
	delete tree;
	
	return 0;
}