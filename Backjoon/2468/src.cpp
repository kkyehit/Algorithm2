#include <stdio.h>
#include <cstring>
#include <iostream>

#define MAX_N 100
#define MAX_H 100
using namespace std;
const int d[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int n;
int board[MAX_N][MAX_N];
bool isVisited[MAX_N][MAX_N];

bool isRange(int y, int x){
	if(0 <= y && y < n && 0<=x && x < n) return true;
	return false;
}

void DFS(int hight, int y, int x){
	isVisited[y][x] = true;
	for(int i = 0; i < 4; i++)
		if(isRange(y + d[i][0], x + d[i][1])
		   && !isVisited[y+d[i][0]][x+d[i][1]]
		   && board[y+d[i][0]][x+d[i][1]] > hight)
			DFS(hight, y+d[i][0], x+d[i][1]);
}

int search(){
	int res = 0, tmp = 0;
	for(int hight = 0; hight <= MAX_H; hight++){
		tmp = 0;
		memset(isVisited, 0, sizeof(isVisited));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(!isVisited[i][j] && board[i][j] > hight) {
					tmp++;
					DFS(hight, i, j);
				}
			}
		}
		res = max(res, tmp);
	}
	return res;
}

int main(void){
	scanf("%d", &n);
	for(int i = 0 ; i < n; i++){
		for(int j = 0 ; j < n; j++){
			scanf("%d",&board[i][j]);
		}
	}
	printf("%d\n",search());
}