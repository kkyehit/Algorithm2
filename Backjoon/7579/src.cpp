#include <stdio.h>
#include <iostream>
#include <cstring>

#define MAX_N 100
#define MAX_C 101 * 100
#define MAX_M 10000000
#define INF 2123456789
using namespace std;

int N, M;
int memory[MAX_N + 1];
int cost[MAX_N + 1];
int cache[MAX_N + 1][MAX_C + 1];

int dp(){
	int res = INF;
	memset(cache, -1, sizeof(cache));
	
	cache[0][cost[0]] = memory[0];
	cache[0][0] = 0;
	for(int i = 1; i < N; i++){
		for(int j = 0; j <= MAX_C; j++) cache[i][j] = cache[i - 1][j];
		
		for(int j = 0; j <= MAX_C; j++){
			if(cache[i - 1][j] != -1) 
				cache[i][j + cost[i]] = max(cache[i][j + cost[i]], cache[i - 1][j] + memory[i]); 
			if(cache[i][j] >= M) res = min(res, j);
		}
	}
	return res;
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i = 0 ; i < N; i++) scanf("%d", &memory[i]);
	for(int i = 0 ; i < N; i++) scanf("%d", &cost[i]);
	
	printf("%d\n",dp());
}