#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string.h>

#define MAX_N 12

using namespace std;

int N;
int c[1<<(MAX_N * 2)];

int sgn(int x){
	if(!x) return 0;
	return x > 0 ? 1 : -1;
}
int incr(int x){
	if(x < 0) return x - 1;
	return x + 1;
}

int bfs(int dis, int begin, int end){
	if(begin == end) return 0;
	queue<int> q;
	memset(c, 0, sizeof(c));
	q.push(begin);
	c[begin] = 1;
	
	q.push(end);
	c[end] = -1;

	while(!q.empty()){
		int here = q.front();
		
		q.pop();
		int top[4] = {-1, -1, -1, -1};
		for(int i = dis - 1; i >= 0 ; i--){
			top[ (here >> (i * 2)) & 3] = i;
		}
		for( int i = 0; i < 4; i++){
			if(top[i] != -1){
				for(int j = 0; j < 4; j++){
					if(i != j && (top[j] == -1 || top[j] > top[i])){
						int there = 0;
						there = here & ~( 3 << top[i]*2);
						there |= ( (j & 3 ) << top[i]*2);
						if(c[there] == 0){
							c[there] = incr(c[here]);
							q.push(there);
						}
						else if(sgn(c[there]) != sgn(c[here]))
							return abs(c[there]) + abs(c[here]) - 1;
					}
				}
			}
		}
		
	}
	return -1;
}

int main(void){
	int C;
	scanf("%d",&C);
	while(C--){
		int input[MAX_N];
		int state = 0;
		int end = 0;
		
		scanf("%d",&N);
		
		for(int i = 0; i < 4; i++){
			int a;
			scanf("%d",&a);
			for(int j = 0; j < a; j++){
				scanf("%d",&input[j]);
				state |= (i & 3) << ( ( input[j] - 1) * 2);
			}
		}
		
		for(int i = 0; i < N; i++ )
			end |= 3 << (i * 2);
		
		printf("%d\n",bfs(N, state, end));
	}
}