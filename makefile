# Honor Pledge:
# I pledge that I have neither given nor 
# received any help on this assignment.
# Clark Otte
tree.exe: Driver.o RedBlackTree.o BinaryTree.o TreeNode.o Node.o
	g++ Driver.o RedBlackTree.o BinaryTree.o TreeNode.o Node.o -o A4.exe

Driver.o: Driver.cpp
	g++ -c Driver.cpp -o Driver.o

RedBlackTree.o: RedBlackTree.cpp
	g++ -c RedBlackTree.cpp -o RedBlackTree.o
	
BinaryTree.o: BinaryTree.cpp
	g++ -c BinaryTree.cpp -o BinaryTree.o

TreeNode.o: TreeNode.cpp
	g++ -c TreeNode.cpp -o TreeNode.o

Node.o: Node.cpp
	g++ -c Node.cpp -o Node.o
	
clean:
	rm -f Driver.o RedBlackTree.o BinaryTree.o TreeNode.o Node.o A4.exe