#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>

#define MAX_V 10000
using namespace std;

int V, E;
vector<int> v[MAX_V + 1];

bool isSCC[MAX_V + 1];
int num[MAX_V + 1];
int _num;
stack<int> s;
vector< vector<int> > scc;

int dfs(int index){
	num[index] = _num++;
	s.push(index);
	
	/*탐색을 하며 도달가능한 제일 높은 정점 찾기*/
	int res = num[index];
	for(auto i : v[index]){
		if(num[i] == -1)  res = min(res, dfs(i));  // 아직 탐색하지 않은 정점
		else if(!isSCC[i]) res = min(res, num[i]); // 이미 탐색했지만 아직 scc에 포함되지 않은 정점
	}
	
	/*더 이상 도달 가능한 자식이 없을 떄*/
	/*도달 가능한 정점이 자기 자신이라면 stack에서 꺼내 scc를 만든다.*/
	if(res == num[index]){
		vector<int> t;
		while(true){
			int p = s.top();
			s.pop();
			t.push_back(p);
			isSCC[p] = true;
			if(p == index) break;
		}
		sort(t.begin(), t.end());
		scc.push_back(t);
	}
	return res;
}


int main(void){
	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a - 1].push_back(b - 1);
	}
	memset(num, -1, sizeof(num));
	memset(isSCC, 0, sizeof(isSCC));
	
	/*모든 정점에 대해 아직 방문하지 않았다면 dfs 수행*/
	_num = 0;
	for(int i = 0; i < V; i++)
		if(num[i] == -1) dfs(i);
	
	/*정렬*/
	sort(scc.begin(), scc.end());
	
	printf("%lu\n", scc.size());
	for(int i = 0; i < scc.size(); i++){
		for(int j = 0; j < scc[i].size(); j++){
			printf("%d ",scc[i][j] + 1);
		}
		printf("-1\n");
	}
}