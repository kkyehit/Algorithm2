#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_N 1000
#define MAX_M 10000

using namespace std;
int T, N, M;

int main(void){
	scanf("%d",&T);
	
	while(T--){
		scanf("%d %d", &N, &M);
		vector<int> v[N + 1];
		bool isVisite[N + 1];
		queue<int> q;
		int a, b;
		int total = 0;
		
		memset(isVisite, 0 , sizeof(isVisite));
		
		for(int i = 0; i < M ; i++){
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		
		q.push(1);
		isVisite[1] = true;
		while(!q.empty()){
			int now = q.front();
			q.pop();
			
			for(int i = 0 ; i < v[now].size(); i++){
				int next = v[now][i];
				if(!isVisite[next]){
					total++;
					q.push(next);
					isVisite[next] = true;
				}
			}
		}
		
		printf("%d\n",total);
		
	}
}