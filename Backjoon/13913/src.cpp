#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>
#include <cstring>

#define MAX_N 100000
#define LIMIT_N (MAX_N * 2)

using namespace std;
int n, k;
int preLocation[LIMIT_N + 1];

bool isRange(int x){
	if( 0 <= x && x <= LIMIT_N) return true;
	return false;
}

int BFS(){
	queue<pair<pair<int, int>, int > > q;
	fill(preLocation, preLocation + LIMIT_N + 1, -2 );
	
	q.push(make_pair( make_pair(n, 0), -1 ));
	
	while(!q.empty()){
		int x = q.front().first.first, cost = q.front().first.second, prev = q.front().second;
		q.pop();
		
		if(x == k){
			preLocation[x] = prev;
			return cost;
		}
		
		if(preLocation[x] != -2) continue;
		preLocation[x] = prev;
		
		if(isRange(x + 1)) q.push(make_pair(make_pair(x + 1, cost + 1), x));
		if(isRange(x - 1)) q.push(make_pair(make_pair(x - 1, cost + 1), x));
		if(isRange(x * 2)) q.push(make_pair(make_pair(x * 2, cost + 1), x));
	}
	return -1;
}

int main(void){
	scanf("%d %d", &n, &k);
	printf("%d\n",BFS());
	stack<int> s;
	for(int i = k; i != -1; i = preLocation[i]){
		s.push(i);
	}
	while(!s.empty()) {
		printf("%d ",s.top());
		s.pop();
	}
	printf("\n");
}