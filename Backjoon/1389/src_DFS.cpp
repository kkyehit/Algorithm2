#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>

#define MAX_N 100
#define INF 2123456789

using namespace std;
int n, m;
vector<int> v[MAX_N + 1];
int sum[MAX_N + 1];
bool isVisited[MAX_N + 1];

int DFS(int index, int end, int dept){
	if(index == end){
		return dept;
	}
	
	int vSize = v[index].size();
	int res = INF;
	for(int i = 0; i < vSize; i++){
		if(!isVisited[v[index][i]]){
			isVisited[v[index][i]] = true;
			res = min(res, DFS(v[index][i], end, dept + 1));
			isVisited[v[index][i]] = false;	
		}
	}
	return res;
	
}

int search(){
	int person = INF, cost = INF;
	memset(sum, 0, sizeof(sum));
	for(int i = 1; i <= n; i++){
		memset(isVisited, 0, sizeof(isVisited));
		for(int j = 1; j <= n; j++){
			sum[i] += DFS(i, j, 0);	
		}
		if(sum[i] < cost){
			cost = sum[i];
			person = i;
		}
	}
	return person;
}

int main(void){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	printf("%d\n",search());
}