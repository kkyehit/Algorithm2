#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

#define MAX_N 500000
#define MAX_NUM 1000001

using namespace std;
typedef long long int int64;

int N;
int A[MAX_N];
int B[MAX_NUM];
int segTree[MAX_N * 4];

void update(int node, int nodeLeft, int nodeRight, int value){
	if(value < nodeLeft || nodeRight < value) return;
	if(nodeLeft == nodeRight) {
		segTree[node] = 1;
	}else{
		int mid = (nodeLeft + nodeRight) >> 1;
		update(node*2, nodeLeft, mid, value);
		update(node*2+1, mid + 1, nodeRight, value);
		segTree[node] = segTree[node*2] + segTree[node*2 + 1];
	}
}

int64 query(int node, int nodeLeft, int nodeRight, int left, int right){
	//printf("[%d] %d %d -> %d (%d %d)\n",node, nodeLeft, nodeRight, segTree[node], left, right);
	if(nodeRight < nodeLeft) return 0;
	if(nodeRight < left || right < nodeLeft) return 0;
	if(left <= nodeLeft && nodeRight <= right) return segTree[node];
	
	//printf("[%d] %d %d -> %d\n",node, nodeLeft, nodeRight, segTree[node]);
	
	int mid = (nodeLeft + nodeRight) >> 1;
	return query(node*2, nodeLeft, mid, left, right) + query(node*2+1, mid + 1, nodeRight, left, right);
}

int main(void){
	scanf("%d", &N);
	memset(B, 0, sizeof(B));
	memset(segTree, 0, sizeof(segTree));
	
	for(int i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
	for(int i = 0; i < N; i++){
		int value;
		scanf("%d", &value);
		B[value] = i;
	}
	
	int64 res = 0;
	for(int i = 0; i < N; i++){
		int value = A[i];
		res += query(1, 0, N, B[value], N);
		//printf("%d %d \n",query(1, 0, N, B[value], N),segTree[1]);
		update(1,0,N,B[value]);
	}
	//printf("%d %d\n",res,segTree[1]);
	printf("%lld\n",res);
}