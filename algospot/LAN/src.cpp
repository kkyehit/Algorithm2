#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string.h>

#define MAX_N 500
#define MAX_M 2000
using namespace std;

int n, m;
int x[MAX_N], y[MAX_M];

double getDistance(int i, int j){
	return sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])* (y[i] - y[j]) ); 
}

struct group{
	int groupArray[MAX_N];
	int rank[MAX_N];
	group(int _n){
		for(int i = 0; i < _n; i++)
			groupArray[i] = i;
		memset(rank, -1, sizeof(rank));
	}
	bool isSameGroup(int _a, int _b){
		return (findGroup(_a) == findGroup(_b));
	}
	int findGroup(int _a){
		if(groupArray[_a] == _a) return _a;
		return groupArray[_a] = findGroup(groupArray[_a]);
	}
	void joinGroup(int _a, int _b){
		int a = findGroup(_a), b = findGroup(_b);
		if(a == b) return ;
		if(rank[a] > rank[b]) swap(a, b);
		groupArray[a] = b;
		if(rank[a] == rank[b]) rank[b]++;
	}
};

int main(void){
	int c;
	scanf("%d",&c);
	while(c--){
		scanf("%d %d",&n, &m);
		for(int i =0; i < n; i++) scanf("%d",&x[i]);
		for(int i =0; i < n; i++) scanf("%d",&y[i]);
		vector< pair< double, pair<int, int> > > v;
		
		int a, b;
		double dis;
		for(int i = 0; i < m; i++){
			scanf("%d %d", &a, &b);
			v.push_back(make_pair(0,make_pair(a, b)));
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				v.push_back(make_pair(getDistance(i, j),make_pair(i, j)));
		
		sort(v.begin(), v.end());
		group g(n);
		double res = 0;
		int vSize = v.size();
		for(int i = 0; i < vSize; i++){
			a = v[i].second.first; b = v[i].second.second;
			dis = v[i].first;
			if(g.isSameGroup(a, b)) continue;
			g.joinGroup(a, b);
			res += dis;
		}
		printf("%lf\n",res);
	}
}