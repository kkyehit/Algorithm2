#include <stdio.h>
#include <iostream>

#define MAX_N 20
#define INF 2123456789

using namespace std;

int s[MAX_N][MAX_N];
int n;

int absolute(int a){
	return ( a < 0 )? 0 - a  : a;
}

int sum(int selected){
	int res = 0;
	for(int i = 0; i < n; i++){
		if( !(selected & (1 << i) ) ) continue;
		//printf("%d ",i);
		for(int j = 0; j < n; j++){
			if( !(selected & (1 << j) ) ) continue;
			res += s[i][j];
		}
	}
	//printf(" : ");
	return res;
}

int search(int selected, int index, int ticket){
	if(ticket == 0){
		int res = absolute( sum(selected) - sum(~selected) );
		//printf("---%d\n",res);
		return res;
	}
	if(index >= n) return INF;
	
	return min(search(selected | (1 << index), index + 1, ticket - 1)
			  ,search(selected, index + 1, ticket) );
}

int main(void){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &s[i][j]);
		}
	}
	
	printf("%d\n",search(0, 0, n/2));
}