#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

#define MAX_N 5
#define MAX_M 100000
#define MAX_Q 100000
using namespace std;

typedef long long int int64;
const int d[4][2] = {{1, 0},{-1, 0},{0, 1},{0, -1}};

int64 graph[MAX_N + 1][MAX_M + 1];
int64 isVisited[MAX_N + 1][MAX_M + 1];
int64 res[MAX_Q];
int N, M, Q;
int r1[MAX_Q], c1[MAX_Q], r2[MAX_Q], c2[MAX_Q];
priority_queue< pair<int64, pair<int , int> >, vector< pair<int64, pair<int , int> > >, greater<pair<int64, pair<int , int> > > > q;

void search(int r, int c, int minM, int maxM){
	for(int i = 1; i <= N; i++)
		for(int j = minM; j <= maxM; j++)
			isVisited[i][j] = 1e18;
	
	q.push(make_pair(graph[r][c], make_pair(r, c)));
	isVisited[r][c] = graph[r][c];
	
	while(!q.empty()){
		int y = q.top().second.first, x = q.top().second.second;
		int64 cost = q.top().first;
		q.pop();
		if(isVisited[y][x] < cost) continue;
		
		for(int i = 0; i < 4; i++){
			int nextY = y + d[i][0], nextX = x + d[i][1];
			if(nextY < 1 || nextY > N) continue;
			if(nextX < minM || nextX > maxM) continue;
			int64 nextCost = cost + graph[nextY][nextX];
			if(nextCost < isVisited[nextY][nextX] ){
				isVisited[nextY][nextX] = nextCost;
				q.push(make_pair(nextCost, make_pair(nextY, nextX)));
			}
		}
	}
}

void division(int left, int right, vector<int> &list){
	if(list.empty()) return;
	if(left > right) return;
	int mid = (left + right) / 2;
	for(int i = 1; i <= N; i++){
		search(i, mid, left, right);

		for(int j = 0; j < list.size(); j++){
			res[list[j]] = min(res[list[j]], isVisited[r1[list[j]]][c1[list[j]]] + isVisited[r2[list[j]]][c2[list[j]]] - graph[i][mid]);
		}
	}
	vector<int> leftList, rightList;
	for(int i = 0; i < list.size(); i++){
		if(c1[list[i]] > mid) rightList.push_back(list[i]);
		if(c2[list[i]] < mid) leftList.push_back(list[i]);
	}
	division(left, mid - 1, leftList);
	division(mid + 1, right, rightList);
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			scanf("%lld", &graph[i][j]);
	scanf("%d", &Q);
	for(int i = 0; i < Q; i++){
		scanf("%d %d %d %d", &r1[i], &c1[i], &r2[i], &c2[i]);
		if(c2[i] < c1[i]){
			swap(c2[i], c1[i]);
			swap(r2[i], r1[i]);
		}
		res[i] = 1e18;
	}
	vector<int> list;
	for(int i = 0; i < Q; i++) list.push_back(i);
	division(0, M, list);
	for(int i = 0; i < Q; i++) printf("%lld\n", res[i]);		
}