#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX_N 25

using namespace std;

const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int N;
char board[MAX_N][MAX_N];

bool isRange(int y, int x){
	if(0 <= y && y < N && 0 <= x && x < N) return true;
	return false;
}

int makeZero(int _y, int _x){
	int res = 0;
	queue<pair<int, int> > q;
	q.push(make_pair(_y, _x));
	
	while(!q.empty()){
		int y = q.front().first, x = q.front().second;
		q.pop();
		
		if(board[y][x] != '1') continue;
		board[y][x] = '0';
		res++;
		
		for(int i = 0; i < 4; i++){
			int nextY = y + d[i][0], nextX = x + d[i][1];
			if(isRange(nextY, nextX)  && board[nextY][nextX] == '1'){
				q.push(make_pair(nextY, nextX));
			}
		}
	}
	return res;
}


int main(void){
	int res = 0;
	vector<int> v;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%c", &board[i][j]);
			if(board[i][j] == '\n') j--;
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(board[i][j] == '1'){
				res++;
				v.push_back(makeZero(i, j));
			}
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n",res);
	for(int i = 0; i < res; i++)
		printf("%d\n",v[i]);
}