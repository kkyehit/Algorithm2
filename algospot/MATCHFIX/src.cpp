#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 12
#define MAX_M 100
#define MAX_V (2 + MAX_N + MAX_M)
#define INF 987654321
using namespace std;

int N, M, V;
int winCount[MAX_N];
int capacity[MAX_V][MAX_V], flow[MAX_V][MAX_V];

/*포드 폴커슨 알고리즘*/
int networkFlow(int source, int sink){
	memset(flow, 0, sizeof(flow));
	int totalFlow = 0;
	while(true){
		vector<int> parent(MAX_V, -1);
		queue<int> q;
		parent[source] = source;
		q.push(source);
		while(!q.empty() && parent[sink] == -1){
			int here = q.front(); q.pop();
			for(int there = 0; there < V; there++)
				if(capacity[here][there] - flow[here][there] > 0 && parent[there] == -1){
					q.push(there);
					parent[there] = here;
				}
		}
		
		if(parent[sink] == -1) break;
		int amount = INF;
		for(int p = sink; p != source; p = parent[p])
			amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
		for(int p = sink; p != source; p = parent[p]){
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalFlow += amount;
		
	}
	return totalFlow;
}

int main(void){
	int C;
	scanf("%d",&C);
	while(C--){
		vector< pair<int, int> > v;
		int a, b, res = -1, matchWithZero = 0;;
		scanf("%d %d",&N, &M);
		for(int i = 0; i < N; i++) scanf("%d",&winCount[i]);
		for(int i = 0; i < M; i++){
			scanf("%d %d", &a, &b);
			v.push_back(make_pair(a, b));
			if ( a== 0 || b == 0) matchWithZero++;
		}
		for(int i = winCount[0]; i <= winCount[0] + matchWithZero; i++){
		//printf("%d %d \n",i, *max_element(winCount + 1, winCount + N));
			if(*max_element(winCount + 1, winCount + N) >= i) continue;
			memset(capacity, 0, sizeof(capacity));
			V = N + M + 2;
			for(int j = 0; j < M; j++){
				capacity[0][2 + j] = 1;
				capacity[2 + j][2 + M + v[j].first] = 1;
				capacity[2 + j][2 + M + v[j].second] = 1;
			}
			for(int j = 0; j < N; j++){
				int maxWin = (j == 0 ? i : i - 1);
				capacity[2 + M + j][1] = maxWin - winCount[j];
			}
			if(networkFlow(0, 1) == M){
				res = i;
				break;
			}
		}
		printf("%d\n",res);
	}
}