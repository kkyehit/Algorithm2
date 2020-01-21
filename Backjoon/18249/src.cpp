#include <iostream>
#include <stdio.h>
#include <cstring>

#define MAX_N 191229
#define MOD (1000000000 + 7)
using namespace std;

int cache[MAX_N];
int n;

int search(int index){
	if(index >= n - 1) return 1;
	if(cache[index] != -1) return cache[index];
	return ( cache[index] = ( search(index + 1) + search(index + 2) ) % MOD );
}

int main(void){
	int T;
	scanf("%d",&T);
	
	while(T--){
		scanf("%d", &n);
		memset(cache, -1, sizeof(cache));
		printf("%d\n", search(0) );
	}
}