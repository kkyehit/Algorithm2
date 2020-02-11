#include <stdio.h>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX_N 50

typedef long long int int64;
using namespace std;

struct shark{
	int64 size, speed, intelligence;
	bool operator <= (const shark s) const{
		if(size <= s.size && speed <= s.speed && intelligence <= s.intelligence) return true;
		return false;
	}
	bool operator == (const shark s) const{
		if(size == s.size && speed == s.speed && intelligence == s.intelligence) return true;
		return false;
	}
};

int N;
int gotEaten[MAX_N];
bool ate[MAX_N];
vector<shark> s;
vector<int> v[MAX_N];

void printGotEaten(){
	printf("get eaten \n");
	for(int i = 0; i < N; i++) printf("%d ",gotEaten[i]);
	printf("\n");
}

int bipartiteMatching(int here){
	if(ate[here])return 0;
	ate[here] = true;
	
	
	int sizeV = v[here].size();
	for(int i = 0; i < sizeV; i++){
		int next = v[here][i];
		if(gotEaten[next] == -1 || bipartiteMatching(gotEaten[next])){
			gotEaten[next] = here;
			return 1;
		}
	}
	return 0;
}
 
int main(void){
	scanf("%d", &N);
	for(int i = 0 ; i < N ; i++){
		int64 a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		s.push_back({a, b, c});
	}
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++){
			if(s[j] == s[i]){
				if(i > j) v[i].push_back(j);
			}
			else if(s[j] <= s[i] && i != j) v[i].push_back(j);
		}
		
	memset(gotEaten, -1, sizeof(gotEaten));
	int res = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < 2; j++){
			memset(ate, 0, sizeof(ate));
			res += bipartiteMatching(i);
			printGotEaten();
		}
	}
	printf("%d\n",N - res);
}