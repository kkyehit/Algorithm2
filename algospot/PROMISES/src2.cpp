#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>

#define MAX_V 200
#define INF 2000000

using namespace std;

int V, M, N;
int graph[MAX_V][MAX_V];

void floyd(){
	for(int k = 0; k < V; k++)
		for(int i = 0; i < V; i++) 
			for(int j = 0; j < V; j++)
				if(graph[i][k] + graph[k][j] < graph[i][j]){
					graph[i][j] = graph[i][k] + graph[k][j];
				}
}

int main(void){
	int C;
	scanf("%d",&C);
	while(C--){
		int res = 0;
		
		scanf("%d %d %d",&V, &M, &N);
		
		for(int i = 0; i < V; i++) 
			for(int j = 0; j < V; j++)
				graph[i][j] = INF;
		for(int i = 0; i < M; i++){
			int a, b, c;
			scanf("%d %d %d",&a ,&b, &c);
			graph[a][b] = min(graph[a][b], c);
			graph[b][a] = min(graph[b][a], c);
		}
		
		for(int i = 0; i < V; i++) graph[i][i] = 0;
			
		floyd();
			
		for(int i = 0; i < N; i++){
			int a, b, c;
			scanf("%d %d %d",&a ,&b, &c);
			
			if(graph[a][b] <= c) 
				res++;
			else
				for(int j = 0; j < V; j++)
					for(int k = 0; k < V; k++)
						graph[j][k] = min(graph[j][k], min(graph[j][a] + c + graph[b][k], graph[j][b] + c + graph[a][k]));
			
		}
		printf("%d\n",res);
	}
}