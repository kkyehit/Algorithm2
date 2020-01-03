#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 8
using namespace std;
int N;

struct node{
	int sum;
	vector<int> v;
	node(int _sum, vector<int> &_v){
		sum = _sum; v = _v;
	}
	~node(){
		v.clear();
	}
};

bool isOrder(vector<int> &v){
	for(int i = 0; i < v.size() - 1; i++)
		if(v[i] > v[i + 1]) return false;
	return true;
}

void doReverse(vector<int> &v, int a, int b){
	reverse(v.begin() + a, v.begin() + b);
}

int main(void){
	int C;
	scanf("%d",&C);
	while(C--){
		scanf("%d",&N);
		vector<int> v(N, 0);
		for(int i = 0; i < N; i++)
			scanf("%d",&v[i]);
		queue<node> q;
		q.push(node(0, v));
		int res = 0;
		while(!q.empty()){
			int sum = q.front().sum;
			v = q.front().v;
			q.pop();
			
//			if(sum == 2) break;
//			printf("[%d]",sum);
//			
//			for(int i = 0; i < v.size(); i++)printf("%d ",v[i]);
//			printf("\n");
		
			if(isOrder(v)){
				res = sum;
				break;
			}
			
			for(int a = 0; a < N; a++){
				for(int b = a + 2; b <= N; b++){
					doReverse(v, a, b);
					q.push(node(sum + 1, v));
					doReverse(v, a, b);
				}
			}
		}
		printf("%d\n",res);
	}
}