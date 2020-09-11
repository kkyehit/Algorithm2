#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>

#define MAX_N 10000
#define MAX_M 1000000000

using namespace std;
long long int v[MAX_N + 1];
int n, m;

int main(void){
	scanf("%d", &n);
	long long int left = 0, right = 0, mid;
	
	for(int i = 0; i < n; i++){
		scanf("%lld", &v[i]);
		right = max(v[i], right);
	}
	scanf("%d",&m);
	
	for(int i = 0; i < 100; i++){
		mid = (left + right) / 2;
		
		long long int sum = 0 ;
		
		for(int i = 0; i < n; i++){
			sum += (min(mid, v[i]));
		}
		//printf("%d %d %d %d\n", left, mid, right, sum);
		if(sum <= m) left = mid + 1;
		else right = mid;
	}
	
	printf("%lld\n", left - 1);
}