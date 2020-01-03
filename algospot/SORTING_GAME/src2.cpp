#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>

#define MAX_N 8
using namespace std;
int N;

bool isOrder(vector<int> &v){
	for(int i = 0; i < v.size() - 1; i++)
		if(v[i] > v[i + 1]) return false;
	return true;
}

void doReverse(vector<int> &v, int a, int b){
	reverse(v.begin() + a, v.begin() + b);
}

map<vector<int>, int> toSort;
void init(int n){
	vector<int> perm(n, 0);
	for(int i = 0; i < n; i++) perm[i] = i;
		
	queue<vector<int> > q;
	q.push(perm);
	
	toSort[perm] = 0;
	
	while(!q.empty()){
		vector<int> here = q.front();
		q.pop();
		int cost = toSort[here];
		
		for(int i = 0; i < n; i++){
			for(int j = i + 2; j <= n; j++){
				doReverse(here, i, j);
				if(toSort.count(here) == 0){
					toSort[here] = cost + 1;
					q.push(here);
				}
				doReverse(here, i, j);
			}
		}
	}
}

int main(void){
	int C;
	scanf("%d",&C);
	for(int i = 1; i <= MAX_N; i++)
		init(i);
	while(C--){
		scanf("%d",&N);
		vector<int> v(N, 0);
		for(int i = 0; i < N; i++)
			scanf("%d",&v[i]);
		
		
		
		vector<int> fixed(N);
		for(int i = 0; i < N; i++){
			int smaller = 0;
			for(int j = 0; j < N; j++)
				if(v[j] < v[i])
					smaller++;
			fixed[i] = smaller;
		}
		
		printf("%d\n",toSort[fixed]);
	}
}