#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string.h>

#define INF 213456789
#define NO_ROOT 1000 * 1000 + 1
#define INFINITY "INFINITY"
#define UNREACHABLE "UNREACHABLE"
#define MAX_V 100

using namespace std;

bool reachable[MAX_V][MAX_V];
int V, W;

int bellman2(int src, int target, vector< vector<pair<int, int> > > &v){
	vector<int> cost(V, INF);
	cost[0] = 0;
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			int vSize = v[j].size();
			for(int k = 0; k < vSize; k++){
				int nextHole = v[j][k].first;
				int nextCost = v[j][k].second;
				if(cost[j] + nextCost < cost[nextHole]){
					cost[nextHole] = cost[j] + nextCost;
				}
			}
		}
	}
		
	for(int i = 0;  i < V; i++){
		int vSize = v[i].size();
		for(int j = 0; j < vSize; j++){
			int nextHole = v[i][j].first;
			int nextCost = v[i][j].second;
			if(cost[i] + nextCost < cost[nextHole])
				if(reachable[src][i] && reachable[i][target]){
					return -INF;
				}
		}	
	}
	return cost[target];
} 

void floyd(){
	//for(int i = 0; i < V; i++) reachable[i][i] = true;
	for(int k = 0; k < V; k++)
		for(int i = 0; i < V; i++)
			for(int j = 0; j < V; j++)
				if(reachable[i][k] && reachable[k][j])
					reachable[i][j] = true;
				
}
int main(void){
	int C;
	int a, b, d;
	scanf("%d",&C);
	while(C--){
		scanf("%d %d",&V, &W);
		vector< vector< pair<int,int> > > v(V, vector< pair<int, int> >() );
		vector< vector< pair<int,int> > > inverseV(V, vector< pair<int, int> >() );
		
		memset(reachable, 0, sizeof(reachable));
		
		for(int i = 0; i < W; i++){
			scanf("%d %d %d",&a ,&b, &d);
			v[a].push_back(make_pair(b, d));
			inverseV[a].push_back(make_pair(b, -d));
			reachable[a][b] = true;
		}
		
		floyd();
		
		/*for(int i = 0; i < V; i++){
			for(int j = 0; j < V; j++){
				printf("%d ",reachable[i][j]);
			}
			printf("\n");
		}*/
		
		int res = bellman2(0, 1, v);
		int res2 = bellman2(0, 1, inverseV);
		
		if(!reachable[0][1]){
			printf("%s\n",UNREACHABLE);
			continue;
		}else if(res == -INF){
			printf("%s ",INFINITY);
		}else{
			printf("%d ",res);
		}
		if(res2 == -INF){
			printf("%s\n",INFINITY);
		}else{
			printf("%d\n",-res2);
		}
	}
}