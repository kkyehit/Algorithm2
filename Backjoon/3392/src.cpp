#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX_Y 30000
#define MAX_N 10000

using namespace std;

typedef long long int int64;

struct rectangle{
	int x, y1, y2, state;
	bool operator < (rectangle &r) const{
		return x < r.x;
	}
};

int64 segTree[MAX_Y * 4];
int64 isLine[MAX_Y * 4];
int N;

void update(int node, int nodeLeft, int nodeRight, int state, int left, int right){
	if(nodeRight < left || right < nodeLeft) return;
	if(left <= nodeLeft && nodeRight <= right){
		isLine[node] += state;
	}else{
		int mid = (nodeLeft + nodeRight) / 2;
		update(node * 2, nodeLeft, mid, state, left, right);
		update(node * 2 + 1, mid + 1, nodeRight, state, left, right);
	}
	if(isLine[node]) segTree[node] = nodeRight - nodeLeft + 1;
	else if(nodeLeft == nodeRight) segTree[node] = 0;
	else segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
	//printf("left %d right %d nodeLeft %d nodeRight %d isLine %lld ", left, right, nodeLeft, nodeRight, isLine[node]);
	//printf(" segTree[%d] = %lld\n",node, segTree[node]);
	return;
}

int main(void){
	scanf("%d", &N);
	vector<rectangle> v;
	for(int i = 0; i < N; i++){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		v.push_back({x1, y1 , y2 - 1, 1});
		v.push_back({x2, y1 , y2 - 1, -1});
	}

	memset(segTree, 0,sizeof(segTree));
	memset(isLine, 0,sizeof(isLine));	
	sort(v.begin(), v.end());
	
	int64 res = 0;
	int64 left = 0, right = 0;
	for(int i = 0; i < v.size(); i++){
		right = v[i].x;
		res += segTree[1] * ( right - left);
		//printf("push %lld %lld %lld %lld  ",segTree[1], left, right, res);
		//printf("%d %d\n", v[i].y1, v[i].y2);
		update(1, 0, MAX_Y, v[i].state, v[i].y1, v[i].y2);
		left = right;
	}
	printf("%lld\n",res);
}