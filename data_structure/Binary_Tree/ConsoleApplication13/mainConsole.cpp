#include "Binary_Tree.h"

int main(void) {
	Node* root = createNode(123);
	Node* node = NULL;

	insertNode(root, createNode(22));
	insertNode(root, createNode(9918));
	insertNode(root, createNode(424));
	insertNode(root, createNode(17));
	insertNode(root, createNode(3));

	insertNode(root, createNode(98));
	insertNode(root, createNode(34));

	insertNode(root, createNode(760));
	insertNode(root, createNode(317));
	insertNode(root, createNode(1));

	inorder(root);

}