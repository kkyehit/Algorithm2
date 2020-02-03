#include <iostream>
#include <stdio.h>
#include <cstring>

#define MAX_N 100000
#define MAX_M 10
using namespace std;

int cache[MAX_N][MAX_M];
int satisfy[MAX_N][MAX_M];
int n, m;

int dp(int day, int prevDessert){
	if(day >= n) return 0;
	
	if( cache[day][prevDessert] != -1) return cache[day][prevDessert];
	
	for(int i = 0; i < n; i++){
		if(prevDessert == i) cache[day][prevDessert] = max(cache[day][prevDessert], satisfy[day][i] / 2 + dp(day + 1, i));
		else cache[day][prevDessert] = max(cache[day][prevDessert], satisfy[day][i] + dp(day + 1, i));
	}
	return cache[day][prevDessert];
}

int main(void){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &satisfy[j][i]);
	
	memset(cache, -1, sizeof(cache));
	int ret = -1;
	for(int i = 0; i < n; i++){
		ret = max(ret, satisfy[0][i] + dp(1, i));
	}
	printf("%d\n", ret);
}