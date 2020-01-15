#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define MAX_N 2000
#define MAX_M 4000
using namespace std;

struct group{
	int root[MAX_N], rank[MAX_N];
	int n;
	group(int _n){
		n = _n;
		memset(rank, 0, sizeof(rank));
		for(int i = 0; i < _n; i++) root[i] = i;
	}
	
	int findRoot(int _a){
		if(root[_a] == _a) return _a;
		return root[_a] = findRoot(root[_a]);
	}
	
	bool isSameGroup(int _a, int _b){
		return root[_a] == root[_b];
	}
	
	void mergeGroup(int _a, int _b){
		int a = findRoot(_a), b = findRoot(_b);
		if(a == b) return;
		if(rank[a] > rank[b]) swap(a, b);
		root[a] = b;
		if(rank[a] == rank[b]) rank[b]++;
	}
	bool isConnected(){
		if(findRoot(0) != findRoot(n - 1)) return false;
		return true;
	}
};

int n, m;
int main(void){
	int C;
	scanf("%d",&C);
	
	while(C--){
		scanf("%d %d", &n, &m);
		vector<pair<int, pair< int, int > > >v;
		double mean = 0;
		for(int i = 0; i < m; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			v.push_back(make_pair(c, make_pair( a, b)));
		}
		
		sort(v.begin(), v.end());
		
		int res = 987654321;
		int left = 0, right = 1000;
		int mid = (left + right) / 2;
		while(left < right){
			mid = (left + right) / 2;
			group g(n);
			int vSize = v.size();
			int maxV = -987654321, minV = 987654321;
			for(int i = 0; i < v.size(); i++){
				int c = v[i].first, a = v[i].second.first, b = v[i].second.second;
				if( c < mid ) continue;
				g.mergeGroup(a, b);
				minV = min(minV, c);
				if(g.isConnected()){
					maxV = c;
					break;
				}
			}
			if(g.isConnected()){
				res = min(res, maxV - minV);
				left = mid + 1;
			}else{
				right = mid;
			}
		}
		printf("%d\n",res);
	}
}