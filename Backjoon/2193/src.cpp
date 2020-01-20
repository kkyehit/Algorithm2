#include <stdio.h>
#include <string.h>

#define MAX_N 90

using namespace std;

long long int cache[MAX_N + 1];

long long search(int N, int index){
	if(index == N || index == N + 1) return 1;
	if(index > N + 1) return 0;
	
	if(cache[index] != -1) return cache[index];
	
	return cache[index] = search(N, index + 1) + search(N, index + 2);
}

int main(void){
	int N;
	scanf("%d",&N);
	memset(cache, -1, sizeof(cache));
	printf("%lld\n",search(N, 2));
}