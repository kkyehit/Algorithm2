#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>

#define IMPOSSIBLE "IMPOSSIBLE"
#define INF 2123456789
#define MAX_M 500
#define MAX_MIN 200

using namespace std;

int A[MAX_M];
int B[MAX_M];
int M;

int main(void){
	int C;
	scanf("%d",&C);
	while(C--){
		scanf("%d",&M);
		for(int i = 0; i < M; i++){
			scanf("%d %d", &A[i], &B[i]);
		}
		
		vector<int> cost( MAX_MIN*2, INF);
		priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
		
		pq.push(make_pair(0,200));
		
		while(!pq.empty()){
			int sum = pq.top().first, dif = pq.top().second;
			pq.pop();
			
			for(int i = 0; i < M; i++){
				int newDif = dif + (A[i] - B[i]);
				if(newDif < 0 || newDif >= MAX_MIN*2) continue;
				//printf("dif %d / sum %d / a %d / b %d\n",dif, sum, A[i], B[i]);
				//printf("new Difference : %d\n",newDif);
				if(sum + A[i] + B[i] < cost[newDif]){
					pq.push(make_pair(sum + A[i] + B[i], newDif));
					//printf("change cost %d to %d\n",cost[newDif],sum + A[i] + B[i]);
					cost[newDif] = sum + A[i] + B[i];
				}
			}
		}
		if(cost[MAX_MIN] == INF) printf("%s\n",IMPOSSIBLE);
		else printf("%d\n", cost[MAX_MIN]/2);
	}
}