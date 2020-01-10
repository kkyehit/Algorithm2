#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#define MAX_V 500
#define INF 501 * 100
using namespace std;

int V, E;
int C[MAX_V];
int isReached[MAX_V][MAX_V];
int minReached[MAX_V][MAX_V];
int main(void){
	int T;
	int a, b, c;
	
	for(int i = 0; i < MAX_V; i++)
		for(int j = 0; j < MAX_V; j++)
			isReached[i][j] = minReached[i][j] = INF;
		
	
	scanf("%d %d",&V, &E);
		
	for(int i = 0; i < V; i++)
		scanf("%d",&C[i]);
		
	for(int i = 0; i < E; i++){
		scanf("%d %d %d",&a, &b, &c);
		isReached[a - 1][b - 1] = minReached[a - 1][b - 1] = c;
		isReached[b - 1][a - 1] = minReached[b - 1][a - 1] = c;
	}
	scanf("%d",&T);
	
	vector<pair<int, int> >order;
	for(int i = 0; i < V; i++) order.push_back(make_pair(C[i], i));
	sort(order.begin(), order.end());
	
	for(int i =0 ; i < V; i++) {
		isReached[i][i] = minReached[i][i] = 0;
	}
	for(int g = 0; g < V; g++){
		int k = order[g].second;
		for(int i = 0; i < V; i++)
			for(int j = 0; j < V; j++){
				minReached[i][j] = min(minReached[i][k] + minReached[k][j], minReached[i][j]);
				isReached[i][j] = min(minReached[i][k] + C[k] + minReached[k][j], isReached[i][j]);
			}
	}
	
	while(T--){
		int s, t;
		scanf("%d %d", &s, &t);
		printf("%d\n",isReached[s-1][t-1]);
		//printf("%d\n",maxC[s-1][t-1]);
	}
}