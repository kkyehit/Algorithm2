#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>

#define MAX_N 1000
using namespace std;

int n, m, s, t;
vector<pair<int, int> > v[MAX_N + 1];
int Cost[MAX_N + 1];

int dijkstra(){
	memset(Cost, -1, sizeof(Cost));
	priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > >pq;
	pq.push(make_pair(0, s));
	Cost[s] = 0;
	
	while(!pq.empty()){
		int cost = pq.top().first, now = pq.top().second;
		int vSize = v[now].size();
		pq.pop();
		
		//printf("%d %d %d\n",cost, now, vSize);
		
		if(Cost[now] != -1 && Cost[now] < cost) continue;
		Cost[now] = cost;
		
		for(int i = 0; i < vSize; i++){
			int next = v[now][i].first, nextCost = cost + v[now][i].second;
			if(Cost[next] == -1 || nextCost < Cost[next]) pq.push(make_pair(nextCost, next));
		}
	}
	return Cost[t];
}

int main(void){
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i =0 ; i < m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
	}
	scanf("%d %d", &s, &t);
	printf("%d\n",dijkstra());
}