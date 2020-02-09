#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#define MAX_N 100000
using namespace std;

typedef long long int int64;

int N, Q;
int64 arr[MAX_N + 1];
int64 segTree[(MAX_N+1) * 4];

int64 init(int node, int nodeLeft, int nodeRight){
	//printf("init %d %d %d \n", node, nodeLeft, nodeRight);
	if(nodeRight == nodeLeft) return segTree[node] = arr[nodeLeft];
	
	int mid = (nodeLeft + nodeRight) >> 1;
	//printf("call init (%d %d %d) init (%d %d %d)\n", node * 2, nodeLeft, mid, node * 2 + 1,mid + 1, nodeRight);
	return segTree[node] = init(node * 2, nodeLeft, mid) + init(node * 2 + 1,mid + 1, nodeRight) ;
}

void update(int node, int nodeLeft, int nodeRight, int loc, int64 value){
	if(nodeRight < loc || loc < nodeLeft) return;
	//printf("update %d %d %d %d %lld\n", node, nodeLeft, nodeRight, loc, value);
	if(nodeLeft == nodeRight){
		segTree[node] = arr[loc] = value;
		return ;
	}
	int mid = (nodeLeft + nodeRight) >> 1;
	update(node * 2, nodeLeft, mid, loc, value);
	update(node * 2 + 1, mid + 1, nodeRight, loc, value);
	
	segTree[node] = segTree[node*2] + segTree[node*2+1];
}

int64 query(int node, int nodeLeft, int nodeRight, int left, int right){
	if(nodeRight < left || right < nodeLeft) return 0;
	if(left <= nodeLeft && nodeRight <= right) return segTree[node];
	
	int mid = (nodeLeft + nodeRight) >> 1;
	return query(node * 2, nodeLeft, mid, left, right) + query(node * 2 + 1, mid + 1, nodeRight, left, right);
}

int main(void){
	memset(arr, 0, sizeof(arr));
	memset(segTree, 0, sizeof(segTree));
	scanf("%d %d", &N, &Q);
	for(int i = 1; i <= N; i++){
		scanf("%lld",&arr[i]);
	}
	init(1, 0, N);
	for(int i = 0; i < Q; i++){
		int64 x,y,a,b;
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		if(y < x) swap(y, x);
		printf("%lld\n",query(1, 0, N, x, y));
		update(1, 0, N, a, b);
	}
}