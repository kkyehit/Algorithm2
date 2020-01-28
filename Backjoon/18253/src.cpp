#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <queue>

#define MAX_N 5
#define MAX_M 100000
using namespace std;

typedef long long int int64;
const int d[4][2] = {{1, 0},{-1, 0},{0, 1},{0, -1}};

int64 graph[MAX_N][MAX_M];
int64 isVisited[MAX_N][MAX_M];
int N, M, Q;
int r1, c1, r2, c2;

bool isRange(int y, int x, int minM, int maxM){
	if(y < 0 || y >= N || x < minM || x > maxM) return false;
	return true;
}

int64 search(int minM, int maxM){
	priority_queue< pair<int64, pair<int , int> >, vector< pair<int64, pair<int , int> > >, greater<pair<int64, pair<int , int> > > > q;
	memset(isVisited, 0, sizeof(isVisited));
	q.push(make_pair(graph[r1][c1],make_pair(r1, c1)));
	isVisited[r1][c1] = graph[r1][c1];
	
	while(!q.empty()){
		int y = q.top().second.first, x = q.top().second.second;
		int64 cost = q.top().first;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nextY = y + d[i][0], nextX = x + d[i][1];
			if(!isRange(nextY, nextX, minM, maxM)) continue;
			int64 nextCost = cost + graph[nextY][nextX];
			if(isVisited[nextY][nextX] == 0 || nextCost < isVisited[nextY][nextX] ){
				isVisited[nextY][nextX] = nextCost;
				q.push(make_pair(nextCost,make_pair(nextY, nextX)));
			}
		}
	}
	return isVisited[r2][c2];
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			scanf("%lld", &graph[i][j]);
	scanf("%d", &Q);
	for(int i = 0; i < Q; i++){
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		r1--;c1--;r2--;c2--;
		printf("%lld\n",search(min(c1, c2), max(c1, c2)));
		/*for(int k = 0; k < N; k++){
			for(int j = 0; j < M; j++){
				printf("%lld ", isVisited[k][j]);
			}
			printf("\n");
		}
		printf("\n");*/
	}
}