#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>

#define MAX_N 200

using namespace std;

int N, M;
int barn[MAX_N];
bool isVisite[MAX_N];
vector<int> v[MAX_N + 2];

int dfs(int here){
	if(isVisite[here]) return 0;
	isVisite[here] = true;
	
	int vSize = v[here].size();
	
	for(int i = 0; i < vSize; i++){
		int next = v[here][i];
		if(barn[next] == -1 || dfs(barn[next])){
			barn[next] = here;
			return 1;
		}
	}
	return 0;
}

int main(void){
	int res = 0;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; i++){
		int s;
		scanf("%d", &s);
		for(int j = 0; j < s; j++){
			int mj;
			scanf("%d",&mj);
			v[i].push_back(mj - 1);
		}
	}
	memset(barn, -1, sizeof(barn));
	
	for(int i = 0; i < N; i++){
		memset(isVisite, 0, sizeof(isVisite));
		res += dfs(i);
	}
	printf("%d\n",res);
}