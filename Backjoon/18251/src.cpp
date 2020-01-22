#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>

#define MAX_N 262143
#define log2(a) log(a) / log(2)
#define INF 1e9 + 1

using namespace std;

typedef long long int int64;
vector< pair<int, int> > v;
int64 cost[MAX_N + 1];
int N;

void bfs(int node, int depth){
	if(node > N) return;
	
	bfs(node * 2, depth + 1);
	v.push_back(make_pair(depth, cost[node]));
	bfs(node * 2 + 1, depth + 1);
}

int main(void){
	scanf("%d",&N);
	for(int i = 1; i <= N; i++) scanf("%lld",&cost[i]);
	v.push_back(make_pair(0, 0));
	bfs(1, 0);
	 
	int64 res = -INF;
	for(int i = 1; i <= N; i++) res = max(res, cost[i]);
	if(res > 0){
		for(int i = 0; i < log2(N) + 1; i++){
			for(int j = 0; j < log2(N) + 1; j++){
				int64 partialMax = -INF;
				int64 nowCost = 0;
				for(int k = 1; k <= N; k++){
					if(v[k].first < i || j < v[k].first ) continue;
					if(nowCost + v[k].second > 0) nowCost += v[k].second;
					else nowCost = 0;
					partialMax = max(partialMax, nowCost);
				}
				res = max(res, partialMax);
			}	
		}
	}
	printf("%lld\n",res);
}