#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define MAX_N 100000
#define LINITE_N (MAX_N * 2)

using namespace std;
int n, k;
bool isVisited[MAX_N * 2 + 1];

bool isRange(int x){
	if( 0<=x && x <= LINITE_N) return true;
	return false;
}

int BFS(){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	memset(isVisited, 0, sizeof(isVisited));
	
	pq.push(make_pair(0, n));
	
	while(!pq.empty()){
		int cost = pq.top().first, x = pq.top().second;
		//printf("%d %d\n",cost,x);
		pq.pop();
		
		if(isVisited[x]) continue;
		isVisited[x] = true;
		
		if(x == k) return cost;
		
		if(isRange(x + 1)) pq.push(make_pair(cost + 1, x + 1));
		if(isRange(x - 1)) pq.push(make_pair(cost + 1, x - 1));
		if(isRange(x * 2)) pq.push(make_pair(cost, x * 2));
	}
	return -1;
}

int main(void){
	scanf("%d %d", &n, &k);
	printf("%d\n",BFS());
}