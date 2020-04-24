#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define MAX_N 2000
using namespace std;
typedef pair<int, pair<int, int> > pqNode;

int n, m, t;
int s, g, h;
int preLocation[MAX_N + 1];
int Cost[MAX_N + 1];

void Dijkstra(vector<pair<int, int> > *v){
	fill(preLocation, preLocation + MAX_N + 1, -2);
	memset(Cost, -1, sizeof(Cost));
	priority_queue<pqNode, vector<pqNode>, greater<pqNode> > pq;
	pq.push(make_pair(0, make_pair(s, -1)));
	Cost[s] = 0;
	
	while(!pq.empty()){
		int cost = pq.top().first, now = pq.top().second.first, pre = pq.top().second.second;
		int vSize = v[now].size();
		pq.pop();
		//printf("cost : %d Cost : %d now : %d pre : %d\n",cost, Cost[now] , now, pre);
		
		if(Cost[now] < cost) continue;
		
		for(int i = 0; i < vSize; i++){
			int next = v[now][i].first, nextCost = cost + v[now][i].second;
			//printf("\tnextcost : %d Cost : %d next : %d\n", nextCost,  Cost[next],next);
		
			if((preLocation[next] != now)&&(Cost[next] == -1 || nextCost <= Cost[next])){
				if((now == g && next == h)||(now == h && next == g)){
					pq.push(make_pair(nextCost - 1, make_pair(next, now)));
					Cost[next] = nextCost - 1;
					preLocation[next] = now;
					//printf("\t\tequal push(%d, %d, %d)\n",nextCost -1, next, now);
				}
				else{
					pq.push(make_pair(nextCost, make_pair(next, now)));
					Cost[next] = nextCost;
					preLocation[next] = now;
					//printf("\t\tnot equal push(%d, %d, %d)\n",nextCost, next, now);
				}
			}
		}
	}
}
bool isContainGH(int x){
	//printf("(%d %d)isContainGH\n", h, g);
	while(x != -1 && x != -2){
		//printf("%d ",x);
		if((x == g && preLocation[x] == h) || (x == h && preLocation[x] == g) ) return true;
		x = preLocation[x];
	}
	//printf("%d ",x);
	//printf(" finish.\n");
	return false;
}

int main(void){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);
		vector<pair<int,int> > v[n + 1];
		vector<int> x;
	
		for(int i = 0; i < m; i++){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			v[a].push_back(make_pair(b,c));
			v[b].push_back(make_pair(a,c));
		}
	
		for(int i = 0; i < t; i++){
			int a;
			scanf("%d", &a);
			x.push_back(a);
		}
		
		Dijkstra(v);
		sort(x.begin(), x.end());
		for(int i = 0; i < t; i++){
			if(isContainGH(x[i])) printf("%d ",x[i]);
		}
		printf("\n");
	}
}