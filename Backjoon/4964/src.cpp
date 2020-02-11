#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>

#define MAX_ALPHA 26
#define MAX_N 13

using namespace std;

int N;
string str[MAX_N];
int strValue[MAX_N];
bool isInclude[MAX_ALPHA];
bool notZero[MAX_ALPHA];
int value[MAX_ALPHA];

bool check(){
	int sum = 0;
	memset(strValue, 0, sizeof(strValue));
	for(int i = 0; i < N; i++){
		for(int j = 0; j < str[i].size(); j++){
			strValue[i] *= 10;
			strValue[i] += value[str[i][j]- 'A'];
		}
	}
	
	for(int i = 0; i < N - 1; i++)
		sum += strValue[i];
	
	return sum == strValue[N - 1];
	
}

int search(int index, int selected){
	if(index > MAX_ALPHA){
		return check()?1:0;
	}
	if(!isInclude[index]) return search(index + 1, selected);
	
	int res = 0;
	for(int i = notZero[index]? 1: 0; i < 10; i++){
		if(selected & (1 << i)) continue;
		value[index] = i;
		res += search(index + 1, selected | (1<<i));
	}
	return res;
}

int main(void){
	while(true){
		scanf("%d", &N);
		if(N == 0) break;
		
		memset(isInclude, 0, sizeof(isInclude));
		memset(notZero, 0, sizeof(isInclude));
		
		for(int i = 0; i < N; i++) {
			cin>>str[i];
			for(int j = 0; j < str[i].size(); j++)
				isInclude[str[i][j] - 'A'] = true;
			if(str[i].size() != 1)notZero[str[i][0] - 'A'] = true;
		}
		printf("%d\n",search(0, 0));
	}
}