#include <stdio.h>
#include <iostream>
#include <cstring>

#define MAX_N 500000
#define MAX_M 500000
#define MAX_V 10000000

using namespace std;

int v[MAX_V*2 + 1];
int n, m;

int main(void){
	int a;
	memset(v, 0, sizeof(v));
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a);
		v[a + MAX_V]++;
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d",&a);
		printf("%d ",v[a + MAX_V]);
	}
}