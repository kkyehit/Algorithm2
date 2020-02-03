#include <stdio.h>
#include <iostream>

#define TROLL_OK "Dehet YeonJwaJe ^~^\n"
#define TROLL_NO "Hing...NoJam\n"
using namespace std;

int N, T, P;
int main(void){
	scanf("%d %d %d", &N, &P, &T);
	int startHand = 0, endHand = -1;
	int pLeft = (P - 1) * 2, pRight =(P - 1) * 2 + 1; 
	int res = 0;
	int i = 0;
	while(i <= T){
		for(int j = res + 1; j <= 2 * N; j++){
			i++;
			startHand = ( endHand + 1 ) % ( 2 * N );
			endHand = ( j + endHand ) % ( 2 * N );
			res = j;
			//printf("plus : %d %d\n", res, i);

			if(i == T)break;
		}
		if(i == T)break;
		for(int j = 2 * N - 1; j > 0; j--){
			i++;
			startHand = ( endHand + 1 ) % ( 2 * N );
			endHand = ( j + endHand ) % ( 2 * N );
			res = j;
			//printf("minus %d %d\n", res, i);
			if(i == T)break;
		}
		if(i == T)break;
	}
	if(endHand < startHand){
		if( (startHand <= pLeft && pLeft <= 2 * N) || (0 <= pLeft && pLeft <= endHand)){
			printf("%s",TROLL_OK);
		}else if( (startHand <= pLeft && pLeft <= 2 * N) || (0 <= pLeft && pLeft <= endHand)){
			printf("%s",TROLL_OK);	
		}else{
			printf("%s",TROLL_NO);
		}
	}else if( (startHand <= pLeft && pLeft <= endHand) || (startHand <= pRight	 && pRight <= endHand) ) {
		printf("%s",TROLL_OK);
	}else{
		printf("%s",TROLL_NO);
	}
	//printf("start : %d end : %d P : %d pLeft : %d pRight : %d\n", startHand, endHand, P, pLeft, pRight);
	//printf("%d\n",res);
}