#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAX_N 1000
#define MAX_K 100000

using namespace std;

int main(void){
	int T;
	int N, K;
	int edge[MAX_N], D[MAX_N], cost[MAX_N];
			
	
	int x, y, w;
	scanf("%d", &T);
	while(T--){
		vector<int> v[MAX_N];
		memset(edge, 0, sizeof(edge));
		memset(cost, 0, sizeof(cost));
		queue<int > q;
		scanf("%d %d", &N, &K);
		for(int i = 0; i < N; i++) scanf("%d", &D[i]);
		for(int i = 0; i < K; i++){
			scanf("%d %d", &x, &y);
			v[--x].push_back(--y);
			edge[y]++;
		}
		scanf("%d", &w);
		w--;
		for(int i = 0; i < N; i++)
			if(edge[i] == 0) {
				cost[i] = D[i];
				q.push(i);
			}
		
		while(!q.empty()){
			int now = q.front();
			int vSize = v[now].size();
			q.pop();
			
			//printf("now : %d\n",now);
			
			for(int i = 0; i < vSize; i++){
				int next = v[now][i];
				cost[next] = max(cost[next], cost[now] + D[next]);
				//printf("cost[%d] : %d ( %d)\n", next, cost[next],cost[now] + D[next]);
				if(--edge[next] == 0) q.push(next);
			}
		}
		printf("%d\n",cost[w]);
	}
}