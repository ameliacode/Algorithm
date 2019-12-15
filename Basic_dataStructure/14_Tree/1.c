#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct treeNode {
	element data;
	int id;
	struct treeNode *left;
	struct treeNode* right;
}treeNode;

treeNode* makeRootNode(int index, element data, treeNode* leftNode, treeNode *rightNode) {
	treeNode *root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	root->id = index;
	return root;
}

void preorder(treeNode *root) {
	if (root) {
		printf(" %d", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(treeNode *root) {
	if (root) {
		inorder(root->left);
		printf(" %d", root->data);
		inorder(root->right);
	}
}

void postorder(treeNode *root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf(" %d", root->data);
	}
}

int main() {
	treeNode *n[8] = { NULL };
	n[7] = makeRootNode(8, 80, NULL, NULL);
	n[6] = makeRootNode(7, 130, NULL, NULL);
	n[5] = makeRootNode(6, 120, n[6], n[7]);
	n[4] = makeRootNode(5, 90, NULL, NULL);
	n[3] = makeRootNode(4, 70, NULL, NULL);
	n[2] = makeRootNode(3, 50, NULL, n[5]);
	n[1] = makeRootNode(2, 30, n[3], n[4]);
	n[0] = makeRootNode(1, 20, n[1], n[2]);

	int order;
	int index;

	scanf("%d %d", &order, &index);

	if (index < 9) {
		switch (order) {
		case 1:
			preorder(n[index - 1]);
			break;
		case 2:
			inorder(n[index - 1]);
			break;
		case 3:
			postorder(n[index - 1]);
			break;
		default:
			break;
		}
	}
	else printf("-1");

	return 0;
}
