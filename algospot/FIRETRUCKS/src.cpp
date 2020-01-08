#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>

#define MAX_V 1000
#define INF 2123456789

using namespace std;

int V, E;
int n, m;
int main(void){
	int C;
	scanf("%d",&C);
	while(C--){
		scanf("%d %d %d %d", &V, &E, &n, &m);
		
		int a, b, t;
		vector< vector<pair<int, int> > > edge(V, vector< pair<int, int> >() );
		vector<int> fire;
		vector<int> cost(V, INF);
		priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
		
		for(int i = 0; i< E; i++){
			scanf("%d %d %d",&a, &b, &t);
			edge[a - 1].push_back(make_pair(b - 1, t));
			edge[b - 1].push_back(make_pair(a - 1, t));
		}
		
		for(int i = 0; i < n; i++){
			scanf("%d",&a);
			fire.push_back(a - 1);
		}
		
		for(int i = 0; i < m; i++){
			scanf("%d",&a);
			pq.push(make_pair(a - 1, 0));
			cost[a - 1] = 0;
		}
		
		
		while(!pq.empty()){
			int now = pq.top().first, value = pq.top().second;
			int v_size = edge[now].size();
			pq.pop();
			
			for(int i = 0; i < v_size; i++){
				int newValue = value + edge[now][i].second;
				int newPoint = edge[now][i].first;
				if(newValue < cost[newPoint]){
					cost[newPoint] = newValue;
					pq.push(make_pair(newPoint, newValue));
				}
			}
		}
		
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += cost[fire[i]];
		}
		printf("%d\n",sum);
	}
}