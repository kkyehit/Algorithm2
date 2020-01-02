#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>

#define MAX_G 1000
#define INF 2123456789

using namespace std;
bool isVisited[MAX_G + 1];
int minValue;
int G, H;

void visite(vector<int> *v, int index, int flag){
	isVisited[index] = flag;
	for(int i = 0; i < v[index].size(); i++){
		isVisited[v[index][i]] = flag;
	}
}

bool check(){
	for(int i = 0; i < G; i++)
		if(!isVisited[i]) return false;
	return true;
}

int getMinValue(vector<int> *v, int index, int sum){
	if(index == G){
		if(check())
			return minValue = min(minValue, sum);
		return INF;
	}
	if(minValue < sum) return INF;
	if(isVisited[index]) return minValue = min(minValue, getMinValue(v, index + 1, sum) );
	
	minValue = min(minValue, getMinValue(v, index + 1, sum) );
	
	visite(v, index, 1);
	minValue = min(minValue, getMinValue(v, index + 1, sum + 1) );
	visite(v, index, 0);
	
	return minValue;
}


int main(void){
	int C;
	scanf("%d",&C);
	while(C--){
		vector<int> v[MAX_G + 1];
		
		minValue = INF;
		memset(isVisited, 0, sizeof(isVisited));
		
		scanf("%d %d",&G, &H);
		for(int i = 0; i < H; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		getMinValue(v, 0, 0);
		printf("%d\n",minValue);
	}
}