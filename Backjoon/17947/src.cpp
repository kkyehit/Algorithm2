#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX_N 100000

using namespace std;

bool isPossible[4 * MAX_N + 1];
int N, M, K;
int A, B;
int main(void){
	int res = 0;
	memset(isPossible, 1, sizeof(isPossible));
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		isPossible[a] = isPossible[b] = false;
	}
	scanf("%d %d", &A, &B);
	isPossible[A] = isPossible[B] = false;
	
	int pivot = abs( (A % K) - (B % K));
	
	vector< int > v;
	for(int i = 1; i <= 4 * N; i++)
		if(isPossible[i]) 
			v.push_back(-(i % K));
	
	sort(v.begin(), v.end());
	int pt = 0;
	for(int i = 0; i < v.size(); i++){
		//printf("%d ",v[i]);
		while(++pt < v.size())
			if(pivot < abs(v[i] - v[pt])) {
				res++;
				break;
			}
	}
	
	printf("%d\n",min(res, M - 1));
}