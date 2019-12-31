#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>

#define LENGTH 20
#define MAX_N 1000
#define INVALID "INVALID HYPOTHESIS"

using namespace std;

int C, N;
char str[MAX_N + 1][LENGTH + 1];
char graph[26][26];
bool isVisited[26];
char tmp = 0;
	
void dfs(vector<char> &res, int index){
	isVisited[index] = 1;
	for(int i = 0; i < 26; i++){
		if(graph[index][i] && !isVisited[i])
			dfs(res, i);
	}
	res.push_back(index + 'a');
}

int main(void){
	
	scanf("%d",&C);
	while(C--){
		memset(str, 0, sizeof(str));
		memset(graph, 0, sizeof(graph));
		memset(isVisited, 0, sizeof(isVisited));

		vector<char> res;
		
		scanf("%d", &N);
		for(int i = 0; i < N; i++){
			scanf("%s", str[i]);
		}
		
		tmp = 0;
		for(int i = 0; i < N ; i++){
			if(str[i][0] == 0) continue;
			if(str[i][0] != tmp){
				if(tmp != 0){
					graph[str[i][0] - 'a'][tmp - 'a'] = 1;
				}
				tmp = str[i][0];
			}else if( i > 0 ){
				int k = 0;
				while(k < LENGTH){
					if(str[i - 1][k] == 0 || str[i][k] == 0 )break;
					if(str[i - 1][k] != str[i][k]){
						graph[str[i][k] - 'a'][str[i - 1][k] - 'a'] = 1;
						break;
					}
					k++;
				}
			}
		}
		
		for(int i = 0; i < 26; i++){
			if(!isVisited[i]){
				dfs(res, i);
			}
		}
		
		bool isError = 0;
		for(int i = 0; i < res.size(); i++){
			for(int j = i + 1; j < res.size(); j++){
				if(graph[res[i] - 'a'][res[j] - 'a']){
					isError = 1;
					break;
				}
			}
		}
		if(isError){
			printf("%s\n",INVALID);
		}else{
			for(int i = 0; i < res.size(); i++)
				printf("%c",res[i]);
			printf("\n");
		}
	}
}