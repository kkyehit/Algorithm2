#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>

#define MAX_N 75000

using namespace std;
typedef long long int int64;

struct Node1{
	int64 x, y;
	int index;
	Node1(int64 _x, int64 _y, int _index){
		x = _x; y = _y; index = _index;
	}
	bool operator < (Node1 &n) const{
		//printf("compare %lld %lld\n",x, n.x);
		if (x == n.x) return y > n.y;
		return x < n.x;
	}
};
struct Node2{
	int64 x, y;
	int index;
	Node2(int64 _x, int64 _y, int _index){
		x = _x; y = _y; index = _index;
	}
	bool operator < (Node2 &n) const{
		if( y < n.y) return true;
		if( y == n.y) return n.x < x;
		return false;
	}
};

// x기준으로 정렬 후 index 번호 입력.
// y기준으로 정렬 후 끝에서 부터 query로 index ~ N까지에 존재하는 점 확인 후 자신 update

int64 segTree[MAX_N * 4];
int n;

void update(int node, int nodeLeft, int nodeRight, int loc){
	if(loc < nodeLeft || nodeRight < loc) return;
	if(nodeRight == nodeLeft){
		segTree[node]++;
		return;
	}
	int mid = (nodeLeft + nodeRight) >> 1;
	update(node*2, nodeLeft, mid, loc);
	update(node*2+1, mid + 1, nodeRight, loc);
	segTree[node] = segTree[node*2] + segTree[node*2+1];
}
int64 query(int node, int nodeLeft, int nodeRight, int left, int right){
	if(nodeRight < left || right < nodeLeft) return 0;
	if(left <= nodeLeft && nodeRight <= right) return segTree[node];
	
	int mid = (nodeLeft + nodeRight) >> 1;
	return query(node*2, nodeLeft, mid, left, right) + query(node*2+1, mid + 1, nodeRight, left, right);
}

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		int64 res = 0;
		memset(segTree, 0, sizeof(segTree));
		vector<Node1> v1;
		vector<Node2> v2;
		int64 x, y;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%lld %lld", &x, &y);
			v1.push_back(Node1(x, y, i));
			//printf("input ... %d ... ok\n",i);
		}
		sort(v1.begin(), v1.end());
		
		for(int i = 0; i < n; i++){
			v2.push_back(Node2(v1[i].x, v1[i].y, i));
			//printf("copy ... %d ... ok\n",i);
		}
		sort(v2.begin(), v2.end());
		for(int i = 0; i < n; i++){
			res += query(1, 0, n, v2[i].index, n);
			update(1, 0, n, v2[i].index);
			//printf("updated %d %d %d\n", v2[i].x, v2[i].y, v2[i].index);
			//printf("[%d] segTree[1] %d res %d\n",i,segTree[1],res);
			
			//printf("calculate ... %d ... ok\n",i);
		}
		printf("%lld\n",res);
	}
}