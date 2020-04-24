#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

#define MAX_N 10000

using namespace std;
int n, m;
vector<int> v[MAX_N + 1];
bool isVisite[MAX_N + 1];
int cnt[MAX_N + 1];

void BFS(int top){
	queue<int> q;
	q.push(top);
	isVisite[top] = true;
	
	while(!q.empty()){
		int x = q.front();
		int vSize = v[x].size();
		q.pop();

		cnt[top]++;
		
		for(int i = 0; i < vSize; i++){
			if(!isVisite[v[x][i]]) {
				q.push(v[x][i]);
				isVisite[v[x][i]] = true;
			}
		}
	}
}

vector<int> search(){
	int maxCnt = 0;
	vector<int> res;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++){
		memset(isVisite, 0, sizeof(isVisite));
		BFS(i);
	}
	for(int i = 1; i <= n; i++){
		if(maxCnt < cnt[i]){
			maxCnt = cnt[i];
		}
	}
	for(int i = 1; i <= n; i++){
		if(maxCnt == cnt[i]){
			res.push_back(i);
		}
	}
	
	return res;
}

int main(void){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[b].push_back(a);
	}
	vector<int> res = search();
	for(int i = 0; i < res.size(); i++) printf("%d ",res[i]);
	printf("\n");
}
