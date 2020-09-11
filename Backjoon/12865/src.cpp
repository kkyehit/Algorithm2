#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>

#define MAX_N 100
#define MAX_K 100000
#define MAX_W 100000

using namespace std;

int n, k;
vector<pair<int, int> > v;
int cache[MAX_N][MAX_W + 1];

int dp(int index, int weight){
	if (weight < 0) return -2123456789;
	if (index >= n) return 0;
	
	int &ret = cache[index][weight];
	if(ret != -1) return ret;
	
	
	ret = v[index].second + dp(index + 1, weight - v[index].first);
	return ret = max(ret, dp(index + 1, weight));
}

int main(void){
	scanf("%d %d", &n, &k);
	for(int i = 0 ;i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v.push_back(make_pair(a, b));
	}
	memset(cache, -1, sizeof(cache));
	printf("%d\n",dp(0,k));
}