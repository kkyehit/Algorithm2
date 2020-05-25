#include <stdio.h>
#include <vector>
#include <cstring>

#define MAX_N 10000
int n, m;
int a[MAX_N + 1];
int main(void){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d",&a[i]);
	a[n] = 0;
	int start = 0, end = 0, sum = 0, res = 0;
	while(end <= n){
		if(sum == m){
			res++;
			sum += a[end++];
			//printf("%d %d\n", start, end);
		}else{
			if(sum < m) sum += a[end++];
			else sum -= a[start++];
		}
	}
	printf("%d\n",res);
}