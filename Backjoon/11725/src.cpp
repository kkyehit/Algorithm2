#include <stdio.h>
#include <vector>
#include <queue>
#define MAX_N 100000
#define ROOT 1

using namespace std;
int N;
vector<int> v[MAX_N + 1];

int main(void){
	int a, b;
	int parents[MAX_N + 1];
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) parents[i] = i;
	
	for(int i = 0; i < N; i++){
		scanf("%d %d", &a ,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int> q;
	parents[1] = 0;
	q.push(1);
	
	while(!q.empty()){
		int now = q.front();
		int nowSize = v[now].size();
		q.pop();
		
		for(int i = 0; i < nowSize; i++){
			int next = v[now][i];
			if(parents[next] != next ) continue;
			parents[next] = now;
			q.push(next);
		}
		
	}
	for(int i = 2; i <= N; i++) printf("%d\n",parents[i]);
}