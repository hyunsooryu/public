#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct tagNode {
	int data;
	struct tagNode* left;
	struct tagNode* right;
}Node;

Node* createNode(int nVal);
void destroyNode(Node* node);
void destroyTree(Node* root);
Node* SearchNode(Node* root, int target);
Node* SearchMinNode(Node* root);
void insertNode(Node* root, Node* child);
Node* removeNode(Node* root, Node* parent, int target);
void inorder(Node* root);
#endif
