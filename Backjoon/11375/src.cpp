#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>

#define MAX_N 1000

using namespace std;

int N, M;
int work[MAX_N + 1];
bool isOccupied[MAX_N + 1];
vector<int> v[MAX_N + 1];

int bfs(int here){
	if(isOccupied[here]) return 0;
	isOccupied[here] = true;
	
	int vSize = v[here].size();
	for(int i = 0; i < vSize; i++){
		int next = v[here][i];
		if(work[next] == -1 || bfs(work[next]) == 1){
			work[next] = here;
			return 1;
		}
	}
	return 0;
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		int s;
		scanf("%d", &s);
		for(int j = 0; j < s; j++){
			int w;
			scanf("%d", &w);
			v[i].push_back(w - 1);
		}
	}
	memset(work, -1, sizeof(work));
	
	int res = 0;
	for(int i = 0; i < N; i++){
		memset(isOccupied, 0, sizeof(isOccupied));
		res += bfs(i);
	}
	printf("%d\n",res);
}