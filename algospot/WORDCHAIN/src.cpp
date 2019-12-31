#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>

#define INVALID "IMPOSSIBLE"
#define MAX_N 100
#define MAX_LENGTH 10
#define ALPHABET ('z' - 'a' + 1)

using namespace std;

int C, n;
vector<string> graph[ALPHABET][ALPHABET];
int edge[ALPHABET][ALPHABET];
int outdegree[ALPHABET], indegree[ALPHABET];

bool checkEuler(){
	int p = 0, m = 0;
	for(int i = 0; i < ALPHABET; i++){
		int d = outdegree[i] - indegree[i];
		if(d < -1 || 1 < d) return false;
		if(d == 1) p++;
		if( d == -1) m++;
	}
	return (p == 1 && m == 1) || ( p == 0 && m == 0);
}

void getEuler(int index, vector<int>& res){
	for(int i = 0; i < ALPHABET; i++){
		while(edge[index][i] > 0){
			edge[index][i]--;
			getEuler(i, res);
		}
	}
	res.push_back(index);
}

int main(void){
	scanf("%d",&C);
	
	while(C--){
		memset(edge, 0, sizeof(edge));
		memset(outdegree, 0, sizeof(outdegree));
		memset(indegree, 0, sizeof(indegree));
		
		for(int i = 0; i < ALPHABET; i++){
			for(int j = 0; j < ALPHABET; j++){
				graph[i][j].clear();
			}
		}
		
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			string str2;
			cin>>str2;
		//	getline(cin, str[i]);
			graph[str2[0] - 'a'][str2[str2.length() - 1] - 'a'].push_back(str2);
			edge[str2[0] - 'a'][str2[str2.length() - 1] - 'a']++;
			outdegree[str2[0] - 'a']++;
			indegree[str2[str2.length() - 1] - 'a']++;
		}
		
		if(!checkEuler()){
			printf("%s\n",INVALID);
		}else{
			bool isComplete = 0;
			vector<int> res;
			for(int i = 0; i < ALPHABET; i++){
				if(outdegree[i] == indegree[i] + 1){
					getEuler(i, res);
					isComplete = 1;
					break;
				}
			}
			if(!isComplete){
				for(int i = 0; i < ALPHABET; i++){
					if(outdegree[i]){
						getEuler(i, res);
						isComplete = 1;
						break;
					}
				}
			}
			
			if(!isComplete){
				printf("%s\n",INVALID);
			}else{
				if(res.size() != n + 1){
					printf("%s\n",INVALID);
				}else{
					for(int i = res.size() - 1; i > 0; i--){
						cout<<graph[res[i]][res[i - 1]].back()<<" ";
						graph[res[i]][res[i - 1]].pop_back();		
					}
					cout<<endl;
				}
			}
		}
	}
}