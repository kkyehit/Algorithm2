#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define MAX_N 500

using namespace std;
int n;
int Cost[MAX_N];
int StartTime[MAX_N];
int pre[MAX_N];
vector<int> v[MAX_N];

int main(void){
	memset(pre, 0, sizeof(pre));
	memset(StartTime, 0, sizeof(StartTime));
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &Cost[i]);
		
		int a;
		while(true){
			scanf("%d", &a);
			if(a == -1) break;
			v[a - 1].push_back(i);
			pre[i]++;
		}
	}
	
	queue<pair<int ,int> > q;
	for(int i = 0; i < n; i++)
		if(pre[i]==0)
			q.push(make_pair(i, 0));
	
	while(!q.empty()){
		int x = q.front().first, c = q.front().second;
		int vSize = v[x].size();
		//printf("%d %d\n",x,c);
		q.pop();
		
		for(int i = 0; i < vSize; i++){
			pre[v[x][i]]--;
			StartTime[v[x][i]] = max(StartTime[v[x][i]], c + Cost[x]);
			if(pre[v[x][i]] == 0) q.push(make_pair(v[x][i],StartTime[v[x][i]] ));
		}
	}
	for(int i = 0; i < n; i++)
		printf("%d\n",StartTime[i] + Cost[i]);
}