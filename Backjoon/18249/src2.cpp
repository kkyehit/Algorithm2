#include <iostream>
#include <stdio.h>
#include <cstring>

#define MAX_N 191229
#define MOD (1000000000 + 7)
using namespace std;

int cache[MAX_N + 1];
int n;

int main(void){
	int T;
	scanf("%d",&T);
	
	cache[0] = 1;
	cache[1] = 2;
	
	for(int i = 2; i <= MAX_N; i++)
		cache[i] = (cache[i - 2] + cache[i - 1]) % MOD;
	
	while(T--){
		scanf("%d", &n);
		printf("%d\n",cache[n - 1]);
	}
}