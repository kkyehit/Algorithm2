#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define MAX_N 500
#define MAX_M 6000
#define INF 2123456789

using namespace std;

struct node{
	int b, c;
};

int N, M;
vector<node> v[MAX_N];
int cost[MAX_N];

bool Bellman_ford(){
	cost[0]=0;
	
	for(int i = 0; i < N; i++){
		for(int now = 0; now < N; now++){
			if(cost[now] == INF) continue;
			for(auto edge:v[now]){
				int nextCost = cost[now] + edge.c;
				if( nextCost < cost[edge.b]){
					cost[edge.b] = nextCost;
				}
			}
		}
	}
	
	for(int now = 0; now < N; now++){
		if(cost[now] == INF) continue;
		for(auto edge:v[now]){
			int nextCost = cost[now] + edge.c;
			if( nextCost < cost[edge.b]){
				return false;
			}
		}
	}
	return true;
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--;b--;
		v[a].push_back({b, c});
	}
	
	for(int i = 0; i < N; i++) cost[i] = INF;
	
	if(!Bellman_ford()) printf("-1\n");
	else 
		for(int i = 1; i < N; i++) 
			printf("%d\n", (cost[i]==INF)? -1 : cost[i]);
}