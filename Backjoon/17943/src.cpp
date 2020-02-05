// record[x] = x ^ x + 1
// record[x + 1] = x + 1 ^ x + 2
// x ^ x + 2 = record[x] ^ record[x + 1]
// x ^ x + 3 = record[x] ^ record[x + 1] ^ record[x + 2]
// xorToN[x] = record[1]^record[2]^...^record[X];
// x ^ x + 3 = xorToN[x - 1]^xorToN[x + 2]

#include <stdio.h>
#include <iostream>

#define MAX_N 200000

using namespace std;

int xorToN[MAX_N + 2];
int N, Q;
int main(void){
	scanf("%d %d", &N, &Q);
	xorToN[0] = 0;
	for(int i = 1; i < N; i++){
		int a;
		scanf("%d", &a);
		xorToN[i] = a ^ xorToN[i - 1];
	}
	//for(int i = 0; i <= N; i++) printf("%d ",xorToN[i]);
	//printf("\n");
	
	int command, x, y, d;
	for(int i = 0; i < Q; i++){
		scanf("%d", &command);
		switch(command){
			case 0:
				scanf("%d %d", &x, &y);
				printf("%d\n",xorToN[x - 1]^xorToN[y - 1]);
				break;
			case 1:
				scanf("%d %d %d", &x, &y, &d);
				printf("%d\n",d^xorToN[x - 1]^xorToN[y - 1]);
				break;
		}
	}
}