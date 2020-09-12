#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

#define MAX_K 100
#define MAX_N 1000
#define MAX_M 2000000

using namespace std;

int n, m, k;
priority_queue<int> value[MAX_N + 1];
vector<pair<int, int> > v[MAX_N + 1];

int main(void){
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i = 0;i < m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
	}
	
	priority_queue< pair<int, int >, vector< pair<int, int > >, greater< pair<int, int > > > pq;
	pq.push(make_pair(1, 0));
	value[1].push(0);
	
	while(!pq.empty()){
		int x = pq.top().first, c = pq.top().second;
		pq.pop();
		
		for(int i = 0; i < v[x].size(); i++){
			int nextX = v[x][i].first;
			int nextC = c + v[x][i].second;
			
			if(value[nextX].size() < k){
				value[nextX].push(nextC);
			}else if(nextC < value[nextX].top()){
				value[nextX].pop();
				value[nextX].push(nextC);
			}else{
				continue;
			}
			pq.push(make_pair(nextX, nextC) ) ;
		}
		
	}
	for(int i = 1; i <= n; i++){
		if(value[i].size() < k) printf("-1\n");
		else printf("%d\n",value[i].top());
	}
}