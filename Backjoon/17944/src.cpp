#include <stdio.h>
#include <iostream>

using namespace std;

int N, T;
int main(void){
	scanf("%d %d", &N, &T);
	int res = 0;
	int i = 0;
	while(i <= T){
		for(int j = res + 1; j <= 2 * N; j++){
			i++;
			res = j;
			//printf("plus : %d %d\n", res, i);

			if(i == T)break;
		}
		if(i == T)break;
		for(int j = 2 * N - 1; j > 0; j--){
			i++;
			res = j;
			//printf("minus %d %d\n", res, i);
			if(i == T)break;
		}
		if(i == T)break;
	}
	printf("%d\n",res);
}