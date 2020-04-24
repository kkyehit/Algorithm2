#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_N 100

using namespace std;
typedef pair<int, pair<int , int> > pqNode ;

const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int Cost[MAX_N][MAX_N];
char board[MAX_N][MAX_N];
int n, m;

bool isRange(int y, int x){
	if(0<=y && y<n && 0<=x && x<m) return true;
	return false;
}

int dijkstra(){
	priority_queue<pqNode, vector<pqNode >, greater<pqNode > >pq;
	memset(Cost, -1, sizeof(Cost));
	
	pq.push(make_pair(0, make_pair(0, 0)));
	Cost[0][0] = 0;
	while(!pq.empty()){
		int cost = pq.top().first, y = pq.top().second.first, x = pq.top().second.second;
		pq.pop();
		
		if(Cost[y][x] < cost) continue;
		//printf("y %d x %d cost %d\n", y, x, cost);
		
		for(int i = 0; i < 4; i++){
			int nextY = y + d[i][0], nextX = x+ d[i][1];
			if(isRange(nextY, nextX)){
				int nextCost = cost + (board[nextY][nextX] - '0');
				//printf("next %d %d %d\n",nextY, nextX, nextCost);
				if(Cost[nextY][nextX] == -1 || nextCost < Cost[nextY][nextX]){
					pq.push(make_pair(nextCost, make_pair(nextY, nextX)));
					Cost[nextY][nextX] = nextCost;
				}
			} 
		}
	}
	return Cost[n-1][m-1];
}

int main(void){
	scanf("%d %d", &m, &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%c", &board[i][j]);
			if(board[i][j] == '\n') j--;
		}
	}
	printf("%d\n",dijkstra());
}