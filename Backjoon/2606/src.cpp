#include <stdio.h>
#include <queue>
#include <cstring>

#define MAX_N 100

using namespace std;

int n, m;
vector<int> v[MAX_N + 1];
bool isVisited[MAX_N + 1];
int main(void){
	int a, b, total = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	memset(isVisited, 0, sizeof(isVisited));
	
	queue<int> q;
	q.push(1);
	isVisited[1] = true;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		
		for(int i = 0; i < v[now].size(); i++){
			int next = v[now][i];
			if(isVisited[next]) continue;
			isVisited[next] = true;
			total++;
			q.push(next);
		}
	}
	printf("%d\n",total);
}