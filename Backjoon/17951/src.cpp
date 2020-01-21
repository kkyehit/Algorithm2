#include <stdio.h>
#include <iostream>

#define MAX_N 100000
#define MAX_X 20
using namespace std;


int main(void){
	int N, K;
	int score[MAX_N];
	int left = 0, right = MAX_N * MAX_X + 1, res = -1;
	
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++) scanf("%d", &score[i]);
	
	while(left < right){
		int mid = ( left + right ) / 2, group = 0, subSum = 0;
		for(int i = 0; i < N; i++){
			subSum += score[i];
			if(subSum >= mid){
				group++;
				subSum = 0;
			}
		}
		if(group >= K) {
			left = mid + 1;
			res = max(res, mid);
			
		}
		else right = mid; 
	}
	printf("%d\n", res);
}