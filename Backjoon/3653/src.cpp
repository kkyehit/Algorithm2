#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <cstring>

#define MAX_N 100000
using namespace std;

int N, M;
int segTree[MAX_N * 8];
int order[MAX_N + 1];
void update(int node, int nodeLeft, int nodeRight, int loc, int val){
	//printf("update(%d %d %d %d %d %d)\n",node, nodeLeft, nodeRight, left, right, value);
	if(nodeRight < loc || loc < nodeLeft) return ;
	if(nodeLeft == nodeRight){
		segTree[node] = val;
		return;
	}
	int mid = (nodeLeft + nodeRight) >> 1;
	update(node*2, nodeLeft, mid, loc, val);
	update(node*2+1, mid + 1, nodeRight, loc, val);
	segTree[node] = segTree[node*2] + segTree[node*2+1];
}

int query(int node, int nodeLeft, int nodeRight, int left, int right){
	//printf("query(%d %d %d %d %d)\n",node, nodeLeft, nodeRight, left, right);
	if(nodeRight < left || right < nodeLeft) return 0;
	if(left <= nodeLeft && nodeRight <= right) return segTree[node];
	
	int mid = (nodeLeft + nodeRight) >> 1;
	return query(node*2, nodeLeft, mid, left, right) + query(node*2+1, mid+1, nodeRight, left, right);
}

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int top = 0;
		scanf("%d %d", &N, &M);
		
		top = N;
		memset(segTree, 0, sizeof(segTree));
		for(int i = 1; i <= N; i++){
			update(1, 0 , N + M + 1, i - 1,1);
			order[i] = N - i;
		}
		
		for(int i = 0; i < M; i++){
			int a;
			scanf("%d", &a);
			//printf("(%d)[%d %d->%d] ",segTree[1], a, order[a],top);
			printf("%d",query(1, 0, N + M + 1, order[a] + 1, N + M + 1));
			if(i != M -1) printf(" ");
			update(1, 0, N + M + 1, order[a], 0);
			update(1, 0, N + M + 1, top, 1);
			order[a] = top++;
		}
		printf("\n");
	}
}