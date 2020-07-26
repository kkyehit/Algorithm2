#include <stdio.h>
#include <cstring>
#define MAX_N 10000

using namespace std;

struct tree{
	int val;
	tree *left, *right;
	tree(int val);
}typedef tree;

tree::tree(int _val){
	val = _val;
}

void setTree(tree *node, int value){
	if(node->val < value){
		if(node->right == NULL) node->right = new tree(value);
		else setTree(node->right, value);
	}else{
		if(node->left == NULL) node->left = new tree(value);
		else setTree(node->left, value);
	}
}

void DFS(tree *node){
	if(node == NULL) return;
	
	DFS(node -> left);
	DFS(node -> right);	
	printf("%d\n",node->val);
}

int main(void){
	int a;
	tree *root = NULL;
	while(scanf("%d", &a) != -1){
		if(root == NULL) root = new tree(a);
		else setTree(root, a);
	}
	DFS(root);
}