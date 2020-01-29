#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stack>

#define MAX_N 1000000

using namespace std;

int main(void){
	int N, res = 0;
	stack<pair<int, int> > s;
	scanf("%d", &N);
	while(N--){
		int c, A, T;
		scanf("%d",&c);
		switch(c){
			case 1:
				scanf("%d %d", &A, &T);
				if(--T <= 0) res += A;
				else s.push(make_pair(A, T));
				break;
			case 0:
				if(s.empty()) break;
				s.top().second--;
				if(s.top().second == 0){
					res += s.top().first;
					s.pop();
				}
				break;
		}		
	}
	printf("%d\n",res);
}
