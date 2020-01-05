#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N;
int main(void){
	int C;
	scanf("%d",&C);
	while(C--){
		scanf("%d",&N);
		vector< vector<int> > v( 4, vector<int>() );
		map<vector< vector<int> >, int > vectorMap;
		
		for(int i = 0; i < 4; i++){
			int a;
			scanf("%d",&a);
			for(int j = 0; j < a; j++){
				int b;
				scanf("%d",&b);
				v[i].push_back(b);
			}
		}

		vector< vector<int> > v3( 4, vector<int>() );
		for(int i = N; i > 0; i--){
			v3[3].push_back(i);
		}
		
		queue< vector < vector <int> > > q;
		q.push(v);
		vectorMap[v] = 0;
		
		while(!q.empty()){
			vector< vector<int> > v2 = q.front();
			int step = vectorMap[v2];
			q.pop();
			
			/*printf("%d",step);
			for(int i = 0; i < 4; i++){
				printf("\n %d: ",i);
				for(int j = 0; j < v2[i].size(); j++){
					printf("%d ",v2[i][j]);
				}
			}
			printf("\n");*/
			if(vectorMap.count(v3) != 0) break;
			
			for(int i = 0; i < 4; i++){
				if(v2[i].size() > 0){
					for(int j = 0; j < 4; j++){
						if(i != j){
							if(v2[j].size() > 0){
								if(v2[i][v2[i].size() - 1] < v2[j][v2[j].size() - 1]){
									v2[j].push_back(v2[i][v2[i].size() - 1]);
									v2[i].pop_back();
									if(vectorMap.count(v2) == 0){
										vectorMap[v2] = step + 1;
										q.push(v2);
									}
									v2[i].push_back(v2[j][v2[j].size() - 1]);
									v2[j].pop_back();
								}
							}else{
								v2[j].push_back(v2[i][v2[i].size() - 1]);
								v2[i].pop_back();
								if(vectorMap.count(v2) == 0){
									vectorMap[v2] = step + 1;
									q.push(v2);
								}
								v2[i].push_back(v2[j][v2[j].size() - 1]);
								v2[j].pop_back();
							}
						}
					}
				}
			}
		}
		
		
		printf("%d\n",vectorMap[v3]);
	}
}