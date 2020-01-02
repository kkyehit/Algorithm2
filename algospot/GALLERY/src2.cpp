#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

#define MAX_G 1000
#define INF 2123456789

using namespace std;
bool isVisited[MAX_G + 1];
bool isDominate[MAX_G + 1];
int G, H;

int getCamera(vector<int> *v, int index, int root){
	int res = 0;
	bool isChildDominate = true;
	
	isVisited[index] = true;
	for(int i = 0 ; i < v[index].size(); i++){
		if(!isVisited[v[index][i]]){
			res += getCamera(v, v[index][i], index);
		}
	}
	
	for(int i = 0 ; i < v[index].size(); i++){
		if(v[index][i] != root && !isDominate[v[index][i]]){
			isChildDominate = false;
		}
	}
	if(!isChildDominate){
		res++;
		isDominate[index] = true;
		for(int i = 0 ; i < v[index].size(); i++){
			isDominate[v[index][i]] = true;
		}
	}
	return res;
}

int getMinValue(vector<int> *v, int index){
	if(index == G) return 0;
	if(isVisited[index]) return getMinValue(v, index + 1);
	
	int res = getCamera(v, index, -1);
	if(!isDominate[index]){
		isDominate[index] = true;
		res++;
	}
	return res += getMinValue(v, index + 1);
}


int main(void){
	int C;
	scanf("%d",&C);
	while(C--){
		vector<int> v[MAX_G + 1];
		
		memset(isVisited, 0, sizeof(isVisited));
		memset(isDominate, 0, sizeof(isDominate));
		
		scanf("%d %d",&G, &H);
		for(int i = 0; i < H; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		printf("%d\n",getMinValue(v, 0));
	}
}