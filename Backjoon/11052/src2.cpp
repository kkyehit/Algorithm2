#include <stdio.h>
#include <vector>
#include <cstring>
#include <iostream>

#define MAX_N 1000
using namespace std;

int n;
int p[MAX_N + 1];
int cache[MAX_N + 1];

int main(void){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
	memset(cache, 0, sizeof(cache));
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; i - j >= 0; j++){
			cache[i] = max(cache[i], cache[i-j] + p[j]);
		}
	}
	printf("%d\n",cache[n]);
}