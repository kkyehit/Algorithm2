#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 2000
#define MAX_M 200
using namespace std;

int main(void){
	int N, M;
	scanf("%d %d", &N, &M);
	vector< vector< int> > isHeard(N, vector<int>(M, 0));
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			scanf("%d", &isHeard[i][j]);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++)
			printf("%d ",isHeard[i][j]);
		printf("\n");
	}
	sort(isHeard.begin(), isHeard.end());
	printf("\n");
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++)
			printf("%d ",isHeard[i][j]);
		printf("\n");
	}
	for(int i = 0; i < M; i++){
		for(int j = 1; j < N; j++){
			if(isHeard[j-1][i] > isHeard[j][i]){
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
}