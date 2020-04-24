#include <stdio.h>
#include <vector>
#include <cstring>
#include <iostream>

#define MAX_N 1000
using namespace std;

int n;
int p[MAX_N + 1];
int cache[MAX_N + 1];

int DP(int index){
	if(index >= n ) return 0;
	
	int &ret = cache[index];
	if(ret != -1) return ret;
	
	for(int i = 1; index + i <= n; i++){
		ret = max(ret, p[i] + DP(index + i));
	}
	return ret;
}

int main(void){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
	memset(cache, -1, sizeof(cache));
	printf("%d\n",DP(0));
}