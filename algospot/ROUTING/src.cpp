#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <vector>

#define MAX_N 10000
#define MAX_M 20000
#define INF 1.79E+308

using namespace std;

int n, m;
int main(void){
	int c;
	scanf("%d",&c);
	while(c--){
		scanf("%d %d",&n, &m);
		vector< vector<pair<int, double> > > v(n, vector< pair<int,double> >() );
		int a, b;
		double c;
		for(int i = 0; i < m; i++){
			scanf("%d %d %lf",&a, &b, &c);
			v[a].push_back(make_pair(b, c));
			v[b].push_back(make_pair(a, c));
		}
		
		vector<double> costVector(n, INF);
		priority_queue<pair< int, double>, vector<pair<int, double> >, greater<pair<int, double> > > pq;
		pq.push(make_pair(0,1));
		costVector[0] = 1;
		
		while(!pq.empty()){
			int b = pq.top().first;
			double cost = pq.top().second;
			int v_size = v[b].size();
			pq.pop();
			
			for(int i = 0; i < v_size; i++){
				if(cost * v[b][i].second < costVector[v[b][i].first]){
					costVector[v[b][i].first] = cost * v[b][i].second;
					pq.push(make_pair(v[b][i].first, costVector[v[b][i].first]));
				}
			}
		}
		//for(int i = 0; i < n; i++){
		//	printf("#%d: %lf\n",i,costVector[i]);
		//}
		printf("%.10lf\n",costVector[n - 1]);
	}
}