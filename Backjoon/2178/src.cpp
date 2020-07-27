#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_N 100

using namespace std;

const int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool board[MAX_N][MAX_N];
int n, m;

struct node{
	int y, x, level;
	node(int _y, int _x, int _level) : y{_y}, x{_x}, level{_level} {}
};

bool isRange(int y, int x){
	return ( (0 <= y && y < n) && (0 <= x && x < m) );
}

int main(void){
	int total = 0;
	char a;
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%c", &a);
			board[i][j] = (a == '1');
			if(a == '\n') j--;
		}
	}
	
	queue< node > q;
	q.push(node{0,0,1});
	board[0][0] = 0;
	
	while(!q.empty()){
		int y = q.front().y, x = q.front().x, level = q.front().level;
		q.pop();
		if(y == n - 1 && x == m - 1) {
			total = level;
			break;
		}
		
		for(int i = 0; i < 4; i++){
			int nextY = y + d[i][0], nextX = x + d[i][1];
			if(isRange(nextY, nextX) && board[nextY][nextX]){
				board[nextY][nextX] = 0;
				q.push(node(nextY, nextX, level + 1));
			}
		}
	}
	
	printf("%d\n",total);
}