#include <stdio.h>
#include <stack>

#define MAX_N 10000
using namespace std;

int res[2][MAX_N + 2];
int main(void){	
	int N, low, col;
	long long int sum = 0, ret = 0, T = 0;
	scanf("%d",&N);
	sum = ( 2 * N * (2 * N + 1) ) / 2;
	for(int i = 1; i < N - 1; i++) res[0][i] = i;
	for(int i = 1; i < N - 1; i++) res[1][i] = N - 2 + i;
	if(N == 1){
		res[1][0] = 1;
		res[0][0] = 2;	
	}else{
		res[0][N - 1] = 2 * N - 1;
		res[1][0] = 2 * N - 2;
		res[1][N - 1] = 2 * N - 3;
		res[0][0] = 2 * N;
	}
	low = 1; col = N - 1;
	while(low >= 0){
		ret += sum * T++;
		sum -= res[low][col--];
		if(col < 0){
			low--; col = N - 1;
		}
	}
	
	printf("%lld\n",ret);
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < N; j++) printf("%d ",res[i][j]);
		printf("\n");
	}
}