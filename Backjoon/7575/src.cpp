#include <iostream>
#include <stdio.h>
#include <vector>

#define MAX_N 100
#define MAX_M 1000
using namespace std;

int program[MAX_N][MAX_M];
int M[MAX_N];
int pattern[2][MAX_M];
int N, K;

vector<int> getPi(int index){
	int size = M[index] ;
	vector<int> pi(size, 0);
	
	int begin = 1, matched = 0;
	while(begin + matched < size){					// O(size)
		if(program[begin + matched] == program[matched]){		// 비교할 두 숫자가 같으면
			matched++;								// 동일한 접미사, 접두사의 최대 길이가 1증가한다.
			pi[begin + matched - 1] = matched;		// begin + matched - 1 까지 동일한 접미사, 접두사의 최대 길이는 matched다.
		}else{										// 두 숫자가 같지 않다면 지금까지 구한 pi를 이용하여 matched를 계산한다.
			if(matched == 0) begin++;				// 만약 matched가 0이라면 begin만 증가
			else{
				begin += matched - pi[matched - 1];	// N[begin + matched] != N[matched] 이므로 matched - 1 까지는 같다는 것을 의미한다.
				matched = pi[matched - 1];			// matched를 갱신한다.
			}
		}
	}
	return pi;
}

bool kmp(int patternNum, int programNum){
	int n = M[programNum], m = K;
	vector<int> pi = getPi(programNum);
	
	int begin = 0, matched = 0;
	while(begin + m <= n){
		if(matched < m && program[programNum][begin + matched] == pattern[patternNum][matched]){
			matched++;
			if(matched == m) return true;
		}else{
			if(matched == 0) begin++;
			else{
				begin = begin + matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return false;
}

bool isThereVirus(){
	int m = M[0];
	bool res = false;
	for(int i = 0; i + K <= m; i++){
		res = true;
		for(int j = i; j < i + K; j++)
			pattern[1][K - (j - i + 1)] = pattern[0][j - i] = program[0][j];
		for(int j = 1; j < N; j++){
			if(!res) continue;
			if(kmp(0, j)) res = true;
			else res = kmp(1,j);
		}
		if(res) return res;
	}
	return false;
}

int main(void){
	scanf("%d %d", &N, &K);
	for(int i = 0; i <= N; i++){
		scanf("%d",&M[i]);
		for(int j = 0; j < M[i]; j++){
			scanf("%d", &program[i][j]);
		}
	}
	printf("%s\n", isThereVirus()? "YES": "NO");
}