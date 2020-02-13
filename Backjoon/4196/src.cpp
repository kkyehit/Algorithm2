#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

#define MAX_N 100000

using namespace std;

int N, M;

vector<int> nextDomino[MAX_N + 1];
stack<int> s;
bool isSCC[MAX_N + 1];
int num[MAX_N + 1];
int res, tail;
int group[MAX_N + 1];
int indegree[MAX_N + 1];

int dfs(int index){
	num[index] = tail++;
	s.push(index);
	int r = num[index];
	for(auto next : nextDomino[index]){
		if(num[next] == -1) r= min(r, dfs(next));
		else if(!isSCC[next]) r= min(r, num[next]);
	}
	
	if(r == num[index]){
		res++;
		while(1){
			int t = s.top();
			s.pop();
			isSCC[t] = true;
			group[t] = res;
			if(t == index) break;
		}
	}
	return r;
}

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &N, &M);
		for(int i = 0; i < N; i++) nextDomino[i].clear();
		
		for(int i = 0; i < M; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			nextDomino[a - 1].push_back(b - 1);
		}
		memset(isSCC, 0, sizeof(isSCC));
		memset(num, -1,sizeof(num));
		memset(indegree, 0,sizeof(indegree));
		memset(group, 0, sizeof(group));
		res = tail = 0;
		
		for(int i = 0; i < N; i++) if(num[i] == -1) dfs(i);
		
		for(int i = 0; i < N; i++) {
			for (auto j : nextDomino[i]){
				if(group[i] != group[j]) indegree[group[j]]++;
			}
		}
		
		int ret = 0;
		for(int i = 0; i < res; i++) if(indegree[i] == 0) ret++;
		
		printf("%d\n",ret);
	}
}