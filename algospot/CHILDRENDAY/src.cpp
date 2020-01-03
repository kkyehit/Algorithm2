#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>

#define IMPOSSIBLE "IMPOSSIBLE"
#define D_LENGTH 11
#define MAX_N 10000

using namespace std;

int isVisitedModular[MAX_N * 2];
int n, m;
char d[D_LENGTH];

struct node{
	string str;
	int rest;
	node(string _str, int _rest){
		str = _str, rest = _rest;
	}
};

int strToInt(string str){
	int n = str.size();
	int res = 0;
	for(int i = 0; i < n; i++){
		res *= 10;
		res += str[i] - '0';
	}
	return res;
}

int main(void){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(d, 0, sizeof(d));
		memset(isVisitedModular, 0, sizeof(isVisitedModular));
		
		vector<int> list;
		scanf("%s",d);
		scanf("%d %d", &n, &m);
		
		for(int i = 0 ; i < D_LENGTH; i++){
			if(d[i] == 0) break;
			list.push_back(d[i] - '0');
		}
		
		sort(list.begin(), list.end());
		
		queue<node> q;
		q.push(node("", 0));
		isVisitedModular[0] = 1;
		
		string res = "";
		while(!q.empty()){
			string str = q.front().str;
			int rest = q.front().rest;
			q.pop();
			
			if(rest == n + m){
				res = str;
				break;
			}
			
			for(int i = 0; i < list.size(); i++){
				int next = rest * 10 + list[i];
				if(next >= n) next = n + next % n;
				
				if(isVisitedModular[next]) continue;
				isVisitedModular[next] = 1;
				q.push(node(str + (char)(list[i] + '0'), next));
			}
		}
		
		if(res == "") printf("%s\n",IMPOSSIBLE);
		else cout<<res<<endl;
	}
}