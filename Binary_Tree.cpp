#include <iostream>
using namespace std;
//DEF Node
typedef struct tagNode {
	int data;
	struct tagNode* left; 
	struct tagNode* right;
}Node;

//CREATE NODE FUNCTION

Node* createNode(int nVal) {
	Node* newNode = (Node*)malloc(sizeof(tagNode));
	newNode->data = nVal;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void appendNode(Node* root, Node* NVal) {
	if (NVal->data < root->data) {
		if (root->left == NULL) {
			root->left = NVal;
		}
		else {
			Node* temp = root->left;
			appendNode(temp, NVal);
		}
	}
	else {
		if (root->right == NULL) {
			root->right = NVal;
		}
		else {
			Node* temp = root->right;
			appendNode(temp, NVal);
		}
	}
}
void display(Node* NVal) {
	if (NVal == NULL) {
		return;
	}
	cout << NVal->data << "   ";
}

//inorder for low - high display data
void INORDER(Node* root) {
	if (root == NULL) {
		return;
	}
	INORDER(root->left);
	display(root);
	INORDER(root->right);
}

//DEF REMOVE_FUNCTION
Node* removeNode(Node* root, Node* parent, int target) {
	if (target < root->data) {
		//target이 root보다 작을경우
		Node* parent = root;   //부모 설정
		Node* child = root->left;  //아이 설정
		if (child->data == target) { //적중했을 경우
			if (child->left == NULL && child->right == NULL) {//왼쪽노드 오른쪽 노드 모두 없을때
				Node* temp = child;
				parent->left = NULL; //부모의 왼쪽 지워버려서 삭제 후 
				return temp; //temp 리턴 후 종료
			}
			else if (child->left != NULL && child->right != NULL) {//왼쪽 노드 오른쪽 노드 모두 있을때
				Node* temp_1 = child;
				Node* temp_2 = child->right;
				if (temp_2->left == NULL) {
					parent->left = temp_2;
					temp_2->left = temp_1->left;
					return child;
				}
				else {
					while (temp_2->left != NULL) {
						temp_1 = temp_2; //타겟의 부모는 temp_1;
						temp_2 = temp_2->left;
					}
					Node* target = temp_2; //타겟
					temp_1->left = target->right; //타겟의 오른쪽 값을 타겟 부모에게 할당
					Node* del = child; //삭제할 대상
					parent->left = target;
					target->left = del->left; //타겟에게 차일드의 정보 줌
					target->right = del->right;//타겟에게 차일드의 정보 줌
					return del;
				}
			}
				else {
				 if(child->left == NULL && child->right != NULL){
					 Node* del = child;
					 parent->left = child->right;
					 return del;
				}
				 else {
					 Node* del = child;
					 parent->left = child->left;
					 return del;
				 }
			}
		}
		else {
			return removeNode(child, child->left, target);
		}
	}
	else {
		Node* parent = root;   //부모 설정
		Node* child = root->right;  //아이 설정
		if (child->data == target) { //적중했을 경우
			if (child->left == NULL && child->right == NULL) {//왼쪽노드 오른쪽 노드 모두 없을때
				Node* temp = child;
				parent->right = NULL; //부모의 왼쪽 지워버려서 삭제 후 
				return temp; //temp 리턴 후 종료
			}
			else if (child->left != NULL && child->right != NULL) {//왼쪽 노드 오른쪽 노드 모두 있을때
				Node* temp_1 = child;
				Node* temp_2 = child->right;
				if (temp_2->left == NULL) {
					parent->right = temp_2;
					temp_2->left = temp_1->left;
					return child;
				}
				else {
					while (temp_2->left != NULL) {
						temp_1 = temp_2; //타겟의 부모는 temp_1;
						temp_2 = temp_2->left;
					}
					Node* target = temp_2; //타겟
					temp_1->left = target->right; //타겟의 오른쪽 값을 타겟 부모에게 할당
					Node* del = child; //삭제할 대상
					parent->right = target;
					target->left = del->left; //타겟에게 차일드의 정보 줌
					target->right = del->right;//타겟에게 차일드의 정보 줌
					return del;
				}
			}
			else {
				if (child->left == NULL && child->right != NULL) {
					Node* del = child;
					parent->right = child->right;
					return del;
				}
				else {
					Node* del = child;
					parent->right = child->left;
					return del;
				}
			}
		}
		else {
			return removeNode(child, child->right, target);
		}
	}
}


//main_Function
int main(void) {
	Node* root = createNode(19);
	appendNode(root, createNode(16));
	appendNode(root, createNode(24));
	appendNode(root, createNode(8));
	appendNode(root, createNode(17));
	appendNode(root, createNode(23));
	appendNode(root, createNode(30));
	appendNode(root, createNode(28));
	appendNode(root, createNode(33));
	appendNode(root, createNode(25));
	appendNode(root, createNode(29));
	appendNode(root, createNode(26));
	INORDER(root);
	cout << "\n";
	removeNode(root, NULL, 16);
	INORDER(root);
	cout << "\n";
	removeNode(root, NULL, 8);
	INORDER(root);
	cout << "\n";
	removeNode(root, NULL, 17);
	INORDER(root);
	cout << "\n";
	removeNode(root, NULL, 23);
	INORDER(root);
	cout << "\n";
	removeNode(root, NULL, 24);
	INORDER(root);
	cout << "\n";
	removeNode(root, NULL, 25);
	INORDER(root);
	cout << "\n";
	removeNode(root, NULL, 30);
	INORDER(root);
	cout << "\n";
	removeNode(root, NULL, 33);
	INORDER(root);.
	cout << "\n";
	removeNode(root, NULL, 29);
	INORDER(root);
	cout << "\n";
	removeNode(root, NULL, 26);
	INORDER(root);
	cout << "\n";
	removeNode(root, NULL, 28);
	INORDER(root);
	cout << "\n";
}