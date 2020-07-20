#include <stdio.h>
#include <vector>
#include <cstring>
#define MOD 1000000007
#define MAX_N 100000

using namespace std;

typedef long long int ll;

int N;
bool isVisited[MAX_N + 1];
vector<pair<int, int> > v[MAX_N + 1];

ll total;
ll dfs(int n){
	isVisited[n] = true;
	
	ll res = 1, tmp;
	int nSize = v[n].size();
	for(int i = 0 ; i < nSize; i++){
		int next = v[n][i].first, cost = v[n][i].second;
		if(isVisited[next]) continue;
		tmp = ( dfs(next)*cost ) % MOD;
		total = (total + res*tmp) % MOD;
		res = (res + tmp ) % MOD;
		//printf("%d %lld\n",next,res);
	}
	return res;
}

int main(void){
	memset(isVisited, 0, sizeof(isVisited));
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	total = 0;
	dfs(1);
	printf("%lld\n",total);
}