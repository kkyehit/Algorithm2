#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>

#define LIMITE_N 200000
#define MAX_N 100000
#define INF 2123456789

using namespace std;
int n ,k;
int isVisiting[LIMITE_N + 1];

bool isRange(int x){
	if( 0 <= x && x <= LIMITE_N) return true;
	 return false;
}

int BFS(int *cnt){
	int res = INF;
	queue<pair<int, int> > q;
	memset(isVisiting, -1, sizeof(isVisiting));
	
	q.push(make_pair(n, 0));
	
	while(!q.empty()){
		int now = q.front().first, cost = q.front().second;
		q.pop();
		
		if(res < cost) break;
		
		if(isVisiting[now] != -1 && isVisiting[now] < cost) continue;
		isVisiting[now] = cost;
		
		if(now == k){
			res = cost;
			(*cnt)++;
			continue;
		}
		
		if(isRange(now + 1)) q.push(make_pair(now + 1, cost + 1));
		if(isRange(now - 1)) q.push(make_pair(now - 1, cost + 1));
		if(isRange(now * 2)) q.push(make_pair(now * 2, cost + 1));
	}
	return res;
}

int main(void){
	scanf("%d %d", &n, &k);
	int cnt = 0;
	printf("%d\n", BFS(&cnt));
	printf("%d\n",cnt);
}