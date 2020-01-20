#include <stdio.h>
#include <iostream>
#include <string.h>

#define MAX_N 10
#define MAX_M 10

using namespace std;

const int d[6][2] = {{0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

char classRoom[MAX_N][MAX_M];
char cache[MAX_N][MAX_M][1<<10][1<<10];
int N, M;

bool isRange(int y, int x){
	if(x < 0 || x >= M || y < 0 || y >= N) return false;
	return true;
}

bool isCanSit(int y, int x){
	if(classRoom[y][x] == 'X' || classRoom[y][x] == 'x') return false;
	for(int i = 0; i < 6; i++){
		if(isRange(y + d[i][0], x + d[i][1]) &&
		  classRoom[y + d[i][0]][x + d[i][1]] == 's') return false;
	}
	return true;
}

char search(int y, int x, int prev, int now){
	if(y >= N) return 0;
	if(x >= M) return search(y + 1, 0, now, 0);
	
	bool is_can_sit = isCanSit(y, x);
	if(cache[y][x][prev][now] != -1) return cache[y][x][prev][now];
	
	if(is_can_sit){
		classRoom[y][x] = 's';
		cache[y][x][prev][now] = 1 + search(y, x + 1, prev, now | (1<<x));
		classRoom[y][x] = '.';
		return cache[y][x][prev][now] = max(cache[y][x][prev][now], search(y, x + 1, prev, now));
	}else{
		return cache[y][x][prev][now] = search(y, x + 1, prev, now);
	}
}

int main(void){
	int C;
	scanf("%d",&C);
	while(C--){
		scanf("%d %d",&N, &M);
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				scanf("%c",&classRoom[i][j]);
				if(classRoom[i][j] == '\n') j--;
			}
		}
		
		memset(cache, -1, sizeof(cache));
		printf("%d\n",search(0, 0, 0, 0));
	}
}