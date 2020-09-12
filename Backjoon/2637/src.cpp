#include <iostream>
#include <vector>
#include <stdio.h>
#include <queue>

#define MAX_N 100

using namespace std;

int n, m;
int cnt[MAX_N + 1];
vector<int> st;
vector<pair<int, int> > need[MAX_N + 1];

int main(void){
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		need[a].push_back(make_pair(b, c));
	}
	for(int i = 1; i <= n; i++) if(need[i].size() == 0) st.push_back(i);
	
	queue<int> q;
	q.push(n);
	cnt[n] = 1;
	while(!q.empty()){
		int x = q.front(), c = cnt[x];
		q.pop();
		//printf("%d %d\n",x,c);
		
		for(int i = 0; i < need[x].size(); i++) {
			int nextC = c * need[x][i].second, nextX = need[x][i].first;
			if(cnt[nextX] == 0){
				q.push(need[x][i].first);
			}
			cnt[nextX] += nextC;
			cnt[x] = 0;
		}
	}
	for(int i = 0; i < st.size(); i++) printf("%d %d\n",st[i],cnt[st[i]]);
}