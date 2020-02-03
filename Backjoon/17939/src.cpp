#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

#define MAX_N 100000
using namespace std;

int N;
int coin[MAX_N];
priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > > pq;

int main(void){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &coin[i]);
		pq.push(make_pair(coin[i], i));
	}
	
	int start = 0;
	long long int res = 0;
	while(!pq.empty()){
		int index = pq.top().second, value = pq.top().first;
		pq.pop();
		
		if(N <= start) break;
		for(; start <= index; start++)
			res = res + ( value - coin[start] );
	}
	
	printf("%lld\n",res);
}