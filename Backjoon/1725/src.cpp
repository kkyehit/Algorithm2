#include <iostream>
#include <vector>
#include <stdio.h>
#include <stack>

#define MAX_N 100000

using namespace std;

int histogram[MAX_N + 1];
int main(void){
	int N, res = 0;
	stack<int> s;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &histogram[i]);
		while(!s.empty() && histogram[i] < histogram[s.top()]){
			int index = s.top();
			s.pop();
			int x = i;
			if(!s.empty()) x -= s.top() + 1;
			res = max(res, histogram[index] * x);
		}
		s.push(i);
	}
	
	while(!s.empty()){
		int index = s.top();
		s.pop();
		int x = N;
		if(!s.empty()) x -= s.top() + 1;
		res = max(res, histogram[index] * x);
	}
	
	printf("%d\n",res);
}