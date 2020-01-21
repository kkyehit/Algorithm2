#include <iostream>

using namespace std;

int main(void){
	int T;
	scanf("%d",&T);
	while(T--){
		int N, M;
		scanf("%d %d", &N, &M);
		printf("%d\n",(N < 12 || M < 4)? -1 : 11*M+4);
	}
}