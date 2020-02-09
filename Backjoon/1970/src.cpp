#include <stdio.h>
#include <vector>
#include <iostream>
#include <cstring>

#define MAX_N 1000
#define MAX_C 100
using namespace std;

int N;
int cache[2*MAX_N][2*MAX_N];
vector<int> sameList[MAX_C + 1];
int kind[2*MAX_N];

int search(int a, int b){
	if(cache[a][b] != -1) return cache[a][b];
	//printf("search(%d,%d)\n",a,b);
	int res = 0;
	int vSize = sameList[kind[a]].size();
	
	for(int i = 0; i < vSize; i++){
		int tmp;
		int next = sameList[kind[a]][i];
		if( a < next && next < b){
			tmp = search(a + 1, next) + search(next + 1, b) + 1;
			res = max(res, tmp);
		}
		
	}
	//printf("search(%d,%d) = %d\n",a,b,res);
	return cache[a][b] = res;
}

int main(void){
	int res = 0;
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		scanf("%d", &kind[i]);
		sameList[kind[i]].push_back(i);
		sameList[kind[i]].push_back(N + i);
	}
	for(int i = 0; i < N; i++)
		kind[i + N] = kind[i];
	
	memset(cache, -1, sizeof(cache));
	for(int i = 0; i < N; i++)
		res = max(res, search(i, N + i));
	printf("%d\n",res);
}