#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>

#define MAX_N 100
#define INF 2123456789

using namespace std;
int n, m;
vector<int> v[MAX_N + 1];
int sum[MAX_N + 1];
bool isVisited[MAX_N + 1];

void BFS(int top){
	queue<pair<int, int> > q;
	q.push(make_pair(top, 0));
	isVisited[top] = true;
	
	while(!q.empty()){
		int x = q.front().first, cost = q.front().second;
		int vSize = v[x].size();
		q.pop();
		
		sum[top] += cost;
		//printf("%d -> %d (%d)\n",top, x, cost);
		
		for(int i = 0 ; i < vSize; i++){
			if(!isVisited[v[x][i]]){
				q.push(make_pair(v[x][i], cost + 1));
				isVisited[v[x][i]] = true;
			}
		}
	}
}

int search(){
	int person = INF, cost = INF;
	memset(sum, 0, sizeof(sum));
	for(int i = 1; i <= n; i++){
		memset(isVisited, 0, sizeof(isVisited));
		BFS(i);
	}
	for(int i = 1; i <= n; i++){
		//printf("sum[%d] = %d\n", i, sum[i]);
		if(sum[i] < cost){
			cost = sum[i];
			person = i;
		}
	}
	return person;
}

int main(void){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	printf("%d\n",search());
}