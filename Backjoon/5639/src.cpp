#include <stdio.h>
#include <cstring>
#define MAX_N 10000

using namespace std;

int tree[MAX_N * 4];

void setTree(int node, int value){
	if(tree[node] == -1) {
		tree[node] = value;
	}else{
		if(tree[node] < value) setTree(node * 2 + 1, value);
		else setTree(node * 2, value);
	}
}

void DFS(int node){
	if(tree[node] == -1) return;
	
	DFS(node * 2);
	DFS(node * 2 + 1);	
	printf("%d\n",tree[node]);
}

int main(void){
	memset(tree, -1, sizeof(tree));
	int a;
	while(scanf("%d", &a) != -1){
		setTree(1, a);
	}
	DFS(1);
}