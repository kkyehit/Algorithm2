#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

#define MAX_N 100000
using namespace std;

int segTree[MAX_N * 4];
int lazy[MAX_N * 4];

void lazyUpdate(int node, int nodeLeft, int nodeRight, int left, int right){
	if(lazy[node] % 2 == 1){
		segTree[node] = nodeRight - nodeLeft + 1 - segTree[node];
		if(nodeLeft != nodeRight){
			lazy[node*2]++;
			lazy[node*2+1]++;
		}
		lazy[node] = 0;
	}
}

void update(int node, int nodeLeft, int nodeRight, int left, int right){
	lazyUpdate(node, nodeLeft, nodeRight, left, right);
	if(nodeRight < left || right < nodeLeft) return;
	
	if(left<= nodeLeft && nodeRight <= right) {
		segTree[node] = nodeRight - nodeLeft + 1 - segTree[node];
		if(nodeLeft != nodeRight){
			lazy[node*2]++;
			lazy[node*2+1]++;
		}
		return;
	}
	
	int mid = (nodeLeft + nodeRight) >> 1;
	update(node*2, nodeLeft, mid, left, right);
	update(node*2+1, mid+1, nodeRight, left, right);
	segTree[node] = segTree[node*2] + segTree[node*2+1];
}

int query(int node, int nodeLeft, int nodeRight, int left, int right){
	lazyUpdate(node, nodeLeft, nodeRight, left, right);
	if(nodeRight < left || right < nodeLeft) return 0;
	if(left<= nodeLeft && nodeRight <= right) return segTree[node];
	
	int mid = (nodeLeft + nodeRight) >> 1;
	return query(node*2, nodeLeft, mid, left, right) + query(node*2+1, mid+1, nodeRight, left, right);
}

int main(void){
	int N, M;
	int c, a, b;
	scanf("%d %d", &N, &M);
	memset(segTree, 0, sizeof(segTree));
	memset(lazy, 0, sizeof(lazy));
	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &c, &a, &b);
		switch(c){
			case 0:
				update(1, 0, N, a, b);
				break;
			case 1:
				printf("%d\n", query(1, 0, N, a, b));
				break;
		}
	}
}