#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>

#define MAX_N 100000
using namespace std;

int N, M;
int studyAmount[MAX_N + 1];
int copyAmount[MAX_N + 1];
bool isIncluded[MAX_N + 1];
int R;
vector< pair< int, int> > v[MAX_N + 1];

void doCopyStudy(){
	for(int i = 1; i <= N; i++) copyAmount[i] = studyAmount[i];
}
int main(void){
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%d", &studyAmount[i]);
	scanf("%d", &R);
	for(int i = 0; i < R; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(make_pair(b, c));
	}
	
	int lo = 0, hi = 100000000;
	int mid = 0;
	queue< int > q;
	
	while(lo < hi){
		int cnt = 0;
		mid = (lo + hi )/ 2;
		memset(isIncluded, 0, sizeof(isIncluded));
		
		for(int i = 1; i <= N; i++)
			if(studyAmount[i] <= mid){
				isIncluded[i] = true;
				q.push(i);
				cnt++;
			}
		
		doCopyStudy();
		while(!q.empty()){
			int index = q.front();
			int vSize = v[index].size();
			q. pop();
			
			for(int i = 0; i < vSize; i++){
				int nextIndex = v[index][i].first;
				int minusValue = v[index][i].second;
				
				copyAmount[nextIndex] -= minusValue;
				if(!isIncluded[nextIndex] 
				   && copyAmount[nextIndex] <= mid){
					isIncluded[nextIndex] = true;
					q.push(nextIndex);
					cnt++;
				}
			}
		}
		
		if(M <= cnt){
			hi = mid;
		}else{
			lo = mid + 1;
		}
	}
	
	printf("%d\n",lo);
}