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
int a[MAX_M], b[MAX_M], c[MAX_M];

int kruskal(vector<pair< int, int > > &v, int low){
	group g(n);
	for(int i = 0; i < v.size(); i++){
		if(v[i].first < v[low].first) continue;
		g.mergeGroup(a[v[i].second], b[v[i].second]);
		if(g.isConnected()) return v[i].first;
	}
	return 987654321;
}

int minDifferent(vector<pair< int, int > > &v){
	int res = 987654321;
	for(int i = 0; i < v.size(); i++)
		res = min( res, kruskal(v, i) - v[i].first);
	return res;
}

int main(void){
	int C;
	scanf("%d",&C);
	
	while(C--){
		scanf("%d %d", &n, &m);
		vector<pair< int, int > >v;
		double mean = 0;
		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &a[i], &b[i], &c[i]);
			v.push_back(make_pair(c[i], i));
		}
		int res;
		sort(v.begin(), v.end());
		res = minDifferent(v);
		printf("%d\n",res);
	}
}