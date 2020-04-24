#include <stdio.h>
#include <iostream>
#include <cstring>

#define MAX_N 100

using namespace std;
int n;
int board[MAX_N][MAX_N];
bool isVisited[MAX_N][MAX_N];

void search(int start, int x){
	board[start][x] = 1;
	isVisited[start][x] = true;
	
	for(int i = 0; i < n; i++)
		if(!isVisited[start][i] && board[x][i] == 1)
			search(start, i);
}

int main(void){
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d",&board[i][j]);
	
	memset(isVisited, 0, sizeof(isVisited));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(!isVisited[i][i] && board[i][j] == 1){
				search(i,j);
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			printf("%d ",board[i][j]);
		printf("\n");
	}
	
}