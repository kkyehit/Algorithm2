#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>

#define MAX_N 32000

using namespace std;
int n, m;
vector<int> v[MAX_N + 1];
int pre[MAX_N + 1];

int main(void){
	vector<int> res;
	memset(pre, 0, sizeof(pre));
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		pre[b]++;
		v[a].push_back(b);
	}
	
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i = 1; i <= n; i++){
		if(pre[i] == 0){
			pq.push(i);
		}
	}
	
	while(!pq.empty()){
		int x = pq.top();
		int vSize = v[x].size();
		pq.pop();
		
		res.push_back(x);
		
		for(int i = 0; i < vSize; i++){
			pre[v[x][i]]--;
			if(pre[v[x][i]] == 0) pq.push(v[x][i]);
		}
	}
	
	for(int i = 0; i < res.size(); i++)
		printf("%d ",res[i]);
	printf("\n");
}