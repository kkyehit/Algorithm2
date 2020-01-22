#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>

#define MAX_N 200000
#define MAX_M 300000

using namespace std;

int group[MAX_N];
int groupSize[MAX_N];
int groupRank[MAX_N];
void init(int _n){
	memset(groupRank, 0, sizeof(groupRank));
	for(int i = 0; i < _n; i++){ 
		group[i] = i; 
		groupSize[i] = 1;
	} 
}
	
int findRoot(int _a){
	if(group[_a] == _a) return _a;
	return group[_a] = findRoot(group[_a]);
}
	
int getGroupSize(int _a){
	return groupSize[_a];
}
	
void merge(int _a, int _b){
	int a = findRoot(_a), b = findRoot(_b);
	if(a == b) return;
	if(groupRank[a] > groupRank[b]) swap(a, b);
	group[b] = a;
	if(groupRank[a] == groupRank[b]) groupRank[b]++;
	groupSize[a] += groupSize[b];
}


int main(void){
	int N, M;
	int deg[MAX_N] = {0};
	int oddCnt[MAX_N] = {0};
	int res = 0;
	scanf("%d %d", &N, &M);
	init(N);
	
	for(int i = 0; i < M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		merge(a - 1, b - 1);
		deg[a - 1]++; deg[b - 1]++;
	}	
	
	for(int i = 0; i < N; i++){
		int a = findRoot(i);
		if(deg[i] % 2 == 1) oddCnt[a]++;
	}
	
	for(int i = 0; i < N; i++){
		int a = findRoot(i);
		if(a != i) continue;
		if(getGroupSize(a) == 1) continue;
		if(oddCnt[a] == 0) res++;	
		else res += oddCnt[a] / 2;
	}
	
	printf("%d\n",res);
}