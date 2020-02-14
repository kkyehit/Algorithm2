#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <cstring>
#include <queue>

#define MAX_N 500000
#define INF 2123456789

using namespace std;

int N, M;
int S, P;
int cash[MAX_N];
bool restorant[MAX_N];
vector<int> v[MAX_N];

int cntOfSCC, num;
int groupOf[MAX_N];
int SCC[MAX_N];
int inBound[MAX_N];
bool isSCC[MAX_N];
int order[MAX_N];
bool restorantOfSCC[MAX_N];
bool canGoFromS[MAX_N];
stack<int> s;
vector<int> vOfSCC[MAX_N];
int cost[MAX_N];

int getSCC(int index){
	
	//printf("index %d\n",index);
	order[index] = num++;
	s.push(index);
	
	int res = order[index];
	for(auto i : v[index]){
		if(order[i] == -1) res = min(res, getSCC(i));
		else if(!isSCC[i]) res = min(res, order[i]);
	}
	
	if(res == order[index]){
		while(true){
			int t= s.top();
			s.pop();
			if(restorant[t]) restorantOfSCC[cntOfSCC] = true;
			SCC[cntOfSCC] += cash[t];
			groupOf[t] = cntOfSCC;
			isSCC[t] = true;
			if(t == index) break;
		}
		cntOfSCC++;
		//printf("cntOfSCC = %d, index %d, res %d\n",cntOfSCC,index,res);
	}
	return res;
}

int main(void){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a - 1].push_back(b - 1);
	}
	for(int i = 0 ; i < N; i++) scanf("%d", &cash[i]);
	
	cntOfSCC = num = 0;
	memset(SCC, 0, sizeof(SCC));
	memset(inBound, 0, sizeof(inBound));
	memset(isSCC, 0, sizeof(isSCC));
	memset(order, -1, sizeof(order));
	memset(restorantOfSCC, 0, sizeof(restorantOfSCC));
	memset(restorant, 0, sizeof(restorant));
	memset(canGoFromS, 0, sizeof(canGoFromS));
	
	scanf("%d %d", &S, &P);
	S--;
	for(int i = 0 ; i < P; i++) {
		int a;
		scanf("%d", &a);
		restorant[a - 1] =true;
	}
	for(int i = 0; i < N; i++)
		if(order[i] == -1) getSCC(i);
	
	for(int i = 0; i < N; i++)
		for( auto j : v[i])
			if(groupOf[i] != groupOf[j]) {
				inBound[groupOf[j]]++;
				vOfSCC[groupOf[i]].push_back(groupOf[j]);
			}
	
	queue<int> q;
	for(int i = 0; i < cntOfSCC; i++){
		cost[i] = SCC[i];
		if(inBound[i] == 0) {
			q.push(i);
		}
	}
	
	canGoFromS[groupOf[S]]= true;
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(auto next : vOfSCC[now]){
			if(canGoFromS[now]){
				cost[next] = max(cost[next], cost[now] + SCC[next]);
				canGoFromS[next] = true;
			}
			if(--inBound[next] == 0) q.push(next);
		}
	}

	int res=0;
		for(int i = 0; i < cntOfSCC; i++)
			if(restorantOfSCC[i] && canGoFromS[i]) res = max(res, cost[i]);
	printf("%d\n",res);
}