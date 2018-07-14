#include "Binary_Tree.h"

Node* createNode(int nVal) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = nVal;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void destroyNode(Node* node) {
	free(node);
}

void destroyTree(Node* root) {
	if (root->left != NULL) {
		destroyTree(root->left);
	}
	if (root->right != NULL) {
		destroyTree(root->right);
	}
	root->left = NULL;
	root->right = NULL;
	destroyNode(root);
}

Node* SearchNode(Node* root, int target) {
	if (root == NULL) {
		return NULL;
	}
	if (root->data == target) {
		return root;
	}
	else if (root->data > target) {
		return SearchNode(root->left, target);
	}
	else {
		return SearchNode(root->right, target);
	}
}

Node* SearchMinNode(Node* root) {
	if (root == NULL) {
		return NULL;
	}
	if (root->left == NULL) {
		return root;
	}
	return SearchMinNode(root->left);
}

void insertNode(Node* root, Node* child) {
	if (root == NULL) {
		return;
	}
	if (root->data < child->data) {
		if (root->right == NULL) {
			root->right= child;
		}
		else {
			insertNode(root->right, child);
		}
	}
	if (root->data > child->data) {
		if (root->left == NULL) {
			root->left = child;
		}
		else {
			insertNode(root->left, child);
		}
	}
}

Node* removeNode(Node* root, Node* parent, int target){
	Node* Removed = NULL; //지울 변수값을 지정하고 시작합니다.
	if (root == NULL) {
		return NULL;
	}
	if (root->data > target) {
		Removed = removeNode(root->left, root, target);
	}
	else if (root->data < target) {
		Removed = removeNode(root->right, root, target);
	}
	else {
		Removed = root;
	}
	if (root->left == NULL && root->right == NULL) {
		if (parent->left == root) {
			parent->left = NULL;
		}
		else {
			parent->right = NULL;
		}
	}
	else {
		if (root->left != NULL && root->right != NULL) {
			Node* minNode = SearchMinNode(root->right);
			minNode = removeNode(root , NULL, minNode->data);
			root->data = minNode->data;
		}
		else {
			Node* temp = NULL;
			if (root->left != NULL) {
				temp = root->left;
			}
			else {
				temp = root->right;
			}
			if (parent->left == root) {
				parent->left = temp;
			}
			else {
				parent->right = temp;
			}
		}
	}
	return Removed;
}

void inorder(Node* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}


