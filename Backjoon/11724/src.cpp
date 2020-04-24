#include <stdio.h>
#include <vector>
#include <cstring>

#define MAX_N 1000
using namespace std;

int n, m;
vector<int> v[MAX_N + 1];
bool isVisited[MAX_N + 1];

void DFS(int x){
	int vSize = v[x].size();
	isVisited[x] = true;
	for(int i = 0; i < vSize; i++)
		if(!isVisited[v[x][i]]) 
			DFS(v[x][i]);
}

int search(){
	int res=0;
	memset(isVisited, 0, sizeof(isVisited));
	
	for(int i = 1 ; i <= n; i++){
		if(!isVisited[i]){
			res++;
			DFS(i);
		}
	}
	return res;
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