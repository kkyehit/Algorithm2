#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define MAX_H 50

using namespace std;

const int d[8][2] = {{1, 0},{-1, 0},{0, 1},{0, -1},{1,1},{1, -1}, {-1, 1}, {-1,-1}};

int W, H;
int map[MAX_H][MAX_H];
bool isVisited[MAX_H][MAX_H];

int main(void){
	while(true){
		int res = 0;
		scanf("%d %d", &W, &H);
		if(W == 0 && H == 0) break;
		
		queue<pair<int, int> > load;
		queue<pair<int, int> > q;
		
		for(int i = 0; i < H; i++)
			for(int j = 0; j < W; j++){
				scanf("%d", &map[i][j]);
				if(map[i][j] == 1) load.push(make_pair(i,j));
			}
		
		memset(isVisited, 0, sizeof(isVisited));
		
		while(!load.empty()){
			if(isVisited[load.front().first][load.front().second]) {
				load.pop();
				continue;
			}
			isVisited[load.front().first][load.front().second] = true;
			
			q.push(load.front());
			load.pop();
			
			res++;
			
			while(!q.empty()){
				int y = q.front().first, x = q.front().second;
				q.pop();
				
				for(int i = 0; i < 8; i++){
					int nextY = y + d[i][0], nextX = x + d[i][1];
					if(0 <= nextY && nextY < H && 0 <= nextX && nextX < W){
						if(isVisited[nextY][nextX] || map[nextY][nextX] == 0) continue;
						
						isVisited[nextY][nextX] = true;
						q.push(make_pair(nextY, nextX));
					}
				}
			}
		}
		printf("%d\n",res);
	}
}