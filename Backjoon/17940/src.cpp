#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX_N 1000

using namespace std;

int N, M;
int C[MAX_N + 1];
vector<pair<int, int> > graph[MAX_N + 1];
pair<int, int> resultCost[MAX_N + 1];

void dijkstra(){
	memset(resultCost, -1, sizeof(resultCost));
	priority_queue< pair< pair<int, int>, int >, vector< pair< pair<int, int>, int > >, greater<pair< pair<int, int>, int > > > pq;
	resultCost[0] = make_pair(0, 0);
	pq.push(make_pair(make_pair(0, 0), 0));
	
	while(!pq.empty()){
		int now = pq.top().second;
		int change = pq.top().first.first, cost = pq.top().first.second;
		int vSize = graph[now].size();
		pq.pop();
		
		if(resultCost[now].first != -1 && resultCost[now].first < change) continue;
		
	/*printf("\nnow : %d change : %d cost : %d\n",now, change, cost);
	for(int i = 0; i < N; i++)
	printf("%d %d\n",resultCost[i].first, resultCost[i].second);*/
		
		for(int i = 0; i < vSize; i++){
			int next = graph[now][i].first;
			int nextCost = cost + graph[now][i].second;
			int nextChange = change + ((C[now] == C[next])? 0 : 1);
			if(resultCost[next].first == nextChange){
				if( nextCost < resultCost[next].second ){
					resultCost[next].second = nextCost;
					pq.push(make_pair(make_pair(nextChange, nextCost), next));
				}
			}else if(resultCost[next].first == -1 || nextChange < resultCost[next].first){
				resultCost[next].first = nextChange;
				resultCost[next].second = nextCost;
				pq.push(make_pair(make_pair(nextChange, nextCost), next));
			}
		}
	}
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++) scanf("%d", &C[i]);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			int a;
			scanf("%d", &a);
			if(a != 0) graph[i].push_back(make_pair(j, a));
		}
/*for(int i = 0; i < N; i++){
	for(int j = 0; j < graph[i].size(); j++)
		printf("%d %d//",graph[i][j].first, graph[i][j].second);
	printf("\n");
}
	
	for(int i = 0; i < N; i++)
	printf("%d %d\n",resultCost[i].first, resultCost[i].second);
}*/
	dijkstra();
	printf("%d %d\n",resultCost[M].first, resultCost[M].second);
}